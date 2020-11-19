#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <memory.h>
#include <string>
using namespace std;
const double EPS = 1e-8; // EPSILON
const double PI = acos(-1);

struct Point {
    double x, y;
    Point(double x_=0, double y_=0) :x(x_), y(y_){}
    bool operator==(const Point& pt) const {return x == pt.x && y == pt.y;}
    bool operator!=(const Point& pt) const {return x != pt.x || y != pt.y;}
    bool operator<(const Point& pt) const {return x != pt.x ? x < pt.x : y < pt.y;}
    Point operator+(const Point& pt) const {return Point(x + pt.x, y + pt.y);}
    Point operator-(const Point& pt) const {return Point(x - pt.x, y - pt.y);}
    Point operator*(double pt) const {return Point(x * pt, y * pt);}
    double norm() const { return hypot(x,y); } //벡터길이 반환(점-점 거리)
    Point normalize() const {return Point(x/norm(), y/norm());} //단위벡터 반환, 영벡터입력X
    double dot(const Point& pt) const {return x * pt.x + y * pt.y;}
    double cross(const Point& pt) const {return x * pt.y - pt.x * y;}
};

class Vector2{
public:
    Vector2(){}
    int ccw(Point p, Point a, Point b); // 방향만 출력(-1:반시계, 0:평행, 1:시계)
    double ccw2(Point p, Point a, Point b); // 넓이 출력(-,+)
    double pointToPoint(Point a, Point b); // 길이 출력
    double intervalAngle(Point a, Point b); // 두 벡터의 사이각(rad) (각도: 180/PI 곱)
    double area(const vector<Point>& poly); // 다각형 p의 넓이를 구함.
    bool lineIntersection(Point a, Point b, Point c, Point d, Point& x); // 두 직선 교차여부 판별. (true:교차, false:평행)
    bool paralleSegments(Point a, Point b, Point c, Point d, Point& p); // 평행한 두 직선이 교차하는지 판단
    bool inBoundingRectangle(Point p, Point a, Point b); // 선분(ab)위 점(p)인지 확인
    pair<bool, Point> segmentIntersection(Point a, Point b, Point c, Point d); // 두직선이 겹치거나 교차하는지 판단. if(true) set 교점p
    int segmentIntersects(Point a, Point b, Point c, Point d); // 두 직선 교차여부만 판별(교차x, 교차o, 무수히 많은 점에서 교차)
    vector<Point> convexHull(vector<Point> &v); // 볼록 다각형 반환. 컨벡스 헐(그라함 스캔 O(NlogN)->정렬시간복잡도)이용
    vector<Point> pointInConvexPoly(vector<Point> &hull, vector<Point> &pt); // hull안의 점 pt를 res에 저장
    double areaOverlap(vector<Point> &poly1, vector<Point> &poly2); // 두 볼록다각형의 겹치는 면적의 넓이를 계산
};

// 반환을 0,1,-1로 안해주면 segmentIntersects함수의 ccw()*ccw()계산에서 오버플로우 발생가능
int Vector2::ccw(Point p, Point a, Point b) {
    double ret = (a-p).cross(b-p);
    if (fabs(ret) < EPS) return 0;
    else if(ret < 0) return -1;
    else return 1;
}
// 반환범위 오버플로우 생각해야 함
double Vector2::ccw2(Point p, Point a, Point b) { // 면적계산용( BOJ_2166 참고 )
    double ret = (a-p).cross(b-p);
    return ret;
}

double Vector2::pointToPoint(Point a, Point b) {
    Point d = b-a;
    return sqrt(d.x*d.x + d.y*d.y);
}

//두 벡터의 사이각(rad) *180/PI 해줘야 각도 나옴
double Vector2::intervalAngle(Point a, Point b) {
	return acos(a.dot(b) / (a.norm()*b.norm()));
}

//단순 다각형 p의 넓이를 구한다.
double Vector2::area(const vector<Point> &p){
    double ret=0;
    if(p.size()<3) return 0;
    for(int i=0;i<p.size();i++) {
        int j=(i+1)%p.size();
        ret+=p[i].cross(p[j]);
    }
    return fabs(ret)/2.0;
}

// 두 직선이 평행할때(기울기만 평행, 같은직선) false, 교차시 true리턴
bool Vector2::lineIntersection(Point a, Point b, Point c, Point d, Point& x) {
    double det = (b - a).cross(d - c);
    if (fabs(det) < EPS) return false;
    x = a + (b - a) * ((c - a).cross(d - c) / det);
    return true;
}

// 평행한 두 직선이 input, 교차판단
bool Vector2::paralleSegments(Point a, Point b, Point c, Point d, Point& p) {
    if (b < a) swap(a, b); // 벡터ab 방향이 ba라면 ab로 바꿔줌
    if (d < c) swap(c, d); // 벡터cd 방향이 dc라면 cd로 바꿔줌
    // 같은 직선에 있지않으면 ccw에 의해 false, 같은 직선위지만 선분ab, cd가 최소 한 점에서 교차하지 않으면 false
    if (ccw(a, b, c) != 0 || b < c || d < a) return false;
    if (a < c) p = c;
    else p = a;
    return true;
}

// 선분(ab)위 점(p)인지 확인
bool Vector2::inBoundingRectangle(Point p, Point a, Point b) {
    if (b < a) swap(a, b);
    return p == a || p == b || (a < p && p < b);
}

// 선분 ab, 선분 cd 교차판별, p에 교차점 저장
pair<bool, Point> Vector2::segmentIntersection(Point a, Point b, Point c, Point d) {
    pair<bool, Point> res;
    if (!lineIntersection(a, b, c, d, res.second)) return res;
    res.first = inBoundingRectangle(res.second, a, b) && inBoundingRectangle(res.second, c, d);
    return res;
}

// 교차여부만 판별
int Vector2::segmentIntersects(Point a, Point b, Point c, Point d) {
    if (ccw(a, b, c) == 0 && ccw(a, b, d) == 0) { // 두선분 모두 한 직선위 일때
        if (b < a) swap(a, b);
        if (d < c) swap(c, d);
        if (b < c || d < a)  return 0; // 교차하지 않을때
        else if (b == c || d == a) // 한점에서 교차할때
            return 1;
        else return 2; // 선분교차 - 무수히 많은점 교차
    } else { // 한직선 위가 아닐때
        int ab = ccw(a, b, c) * ccw(a, b, d); // 직선ab와 선분cd 교차 확인시 ab만 사용
        int cd = ccw(c, d, a) * ccw(c, d, b);
        return ab <= 0 && cd <= 0;
    }
}

vector<Point> Vector2::convexHull(vector<Point> &v){
    if(v.size()<3) return v;
    swap(v[0],*min_element(v.begin(), v.end()));  
    sort(++v.begin(), v.end(), [&](Point a, Point b) -> bool {
        int ret = ccw(v[0], a, b);
        return ret > 0  || (ret==0 && a < b);
    });

    vector<Point> hull;
    hull.emplace_back(v[0]);
    hull.emplace_back(v[1]);
    for(int i=2; i<v.size(); i++){
        while(hull.size()>1 && ccw(v[i], hull[hull.size()-2], hull[hull.size()-1])<=0){
            hull.pop_back();
        }
        hull.emplace_back(v[i]);
    }
    return hull;
}

// pt점들중 hull안에 있는 점들만 res에 저장 -> O(NlogN)
vector<Point> Vector2::pointInConvexPoly(vector<Point> &hull, vector<Point> &pt){
    int s=hull.size()-1;
    int mid = max_element(hull.begin(), hull.end())-hull.begin();

    vector<Point> lowerHull, upperHull;
    upperHull.emplace_back(hull[0]);

    vector<Point> res;
    for(int i=0; i<=mid; i++) lowerHull.emplace_back(hull[i]);
    for(int i=s; i>=mid; i--) upperHull.emplace_back(hull[i]);
    for(int i=0; i<pt.size(); i++){
        int a = lower_bound(lowerHull.begin(), lowerHull.end(), pt[i])-lowerHull.begin();
        int b = lower_bound(upperHull.begin(), upperHull.end(), pt[i])-upperHull.begin();
        
        if(a==0){
            if(pt[i]!=lowerHull[0]) continue;
        } else if(a==lowerHull.size()) continue;
        else {
            if(ccw(pt[i], lowerHull[a-1], lowerHull[a])<0) continue;
        }
        if(b==0){
            if(pt[i]!=upperHull[0]) continue;
        } else if(b==upperHull.size()) continue;
        else {
            if(ccw(pt[i], upperHull[b], upperHull[b-1])<0) continue;
        }
        
        res.emplace_back(pt[i]);
    }
    return res;
}

double Vector2::areaOverlap(vector<Point> &poly1, vector<Point> &poly2){    
    vector<Point> hull1, hull2;
    vector<Point> ans,res,tmp; 
    hull1 = convexHull(poly1);
    hull2 = convexHull(poly2);

    res = pointInConvexPoly(hull1, poly2);
    tmp = pointInConvexPoly(hull2, poly1);
    res.insert(res.end(), tmp.begin(), tmp.end());    

    for(int i=0; i<hull1.size(); i++){
        for(int j=0; j<hull2.size(); j++){
            pair<bool,Point> x = segmentIntersection(hull1[i],hull1[(i+1)%hull1.size()],hull2[j],hull2[(j+1)%hull2.size()]);
            if(x.first){
                res.emplace_back(x.second);
            }
        }
    }

    ans = convexHull(res); // ans: 겹치는부분의 볼록다각형
    return area(ans);
}