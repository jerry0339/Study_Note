#include <bits/stdc++.h>
using namespace std;
#define xx first
#define yy second
typedef long long ll;
const double EPSILON = 1e-9;
const double PI = acos(-1);

struct Point {
    double x, y;
    Point(double x_=0, double y_=0) :x(x_), y(y_){}
    
    bool operator==(const Point& pt) const {
        return x == pt.x && y == pt.y;
    }
    bool operator!=(const Point& pt) const {
        return x != pt.x || y != pt.y;
    }
    bool operator<(const Point& pt) const {
        return x != pt.x ? x < pt.x : y < pt.y;
    }
    Point operator+(const Point& pt) const {
        return Point(x + pt.x, y + pt.y);
    }
    Point operator-(const Point& pt) const {
        return Point(x - pt.x, y - pt.y);
    }
    Point operator*(double sc) const {
        return Point(x * sc, y * sc);
    }
    //벡터길이 반환
    double norm() const { return hypot(x,y); }
    //단위벡터 반환, 영벡터에 대해 호출한 경우 반환 값은 정의되지 않음
    Point normalize() const {
        return Point(x/norm(), y/norm());
    }
    // x축의 양의 방향으로부터 이 벡터까지 반시계 방향으로 잰 각도
    double polar() const {return fmod(atan2(y, x)+2*PI, 2*PI); }
    // 내적,외적
    double dot(const Point& pt) const {
        return x * pt.x + y * pt.y;
    }
    double cross(const Point& pt) const {
        return x * pt.y - pt.x * y;
    }
    //이 벡터를 pt에 사영한 결과
    Point project(const Point& pt) const{
        Point r = pt.normalize();
        return r*r.dot(*this);
    }
};

// a가 b보다 p에 얼마나 가까운지
double howMuchCloser(Point p, Point a, Point b){
    return (b-p).norm() - (a-p).norm();
}

// 반환을 0,1,-1로 안해주면 밑의 다른함수에서 ccw()*ccw()계산이 4제곱이기 때문에 오버플로우 발생가능
int ccw(Point p, Point a, Point b) {
    double ret = (a-p).cross(b-p);
    if (fabs(ret) < EPSILON) return 0;
    else if(ret < 0) return -1;
    else return 1;
}
// 반환범위 오버플로우 생각해야 함
double ccw2(Point p, Point a, Point b) { // 면적계산용( BOJ_2166 참고 )
    double ret = (a-p).cross(b-p);
    return ret;
}

//두 벡터의 사이각(rad) *180/PI 해줘야 각도 나옴
double intervalAngle(Point a, Point b) {
	return acos(a.dot(b) / (a.norm()*b.norm()));
}

//단순 다각형 p의 넓이를 구한다.
double area(const vector<Point>&p){
    double ret=0;
    if(p.size()<3) return 0;
    for(int i=0;i<p.size();i++) {
        int j=(i+1)%p.size();
        ret+=p[i].cross(p[j]);
    }
    return fabs(ret)/2.0;
}

// 두 직선이 평행할때(기울기만 평행, 같은직선) false, 교차시 true리턴
bool lineIntersection(Point a, Point b, Point c, Point d, Point& x) {
    double det = (b - a).cross(d - c);
    if (fabs(det) < EPSILON) return false;
    x = a + (b - a) * ((c - a).cross(d - c) / det);
    return true;
}

// 평행한 두 직선이 input, 교차판단
bool paralleSegments(Point a, Point b, Point c, Point d, Point& p) {
    if (b < a) swap(a, b); // 벡터ab 방향이 ba라면 ab로 바꿔줌
    if (d < c) swap(c, d); // 벡터cd 방향이 dc라면 cd로 바꿔줌
    // 같은 직선에 있지않으면 ccw에 의해 false, 같은 직선위지만 선분ab,cd가 최소 한 점에서 교차하지 않으면 false
    if (ccw(a, b, c) != 0 || b < c || d < a) return false;
    if (a < c) p = c;
    else p = a;
    return true;
}
// 선분(ab)위 점(p)인지 확인
bool inBoundingRectangle(Point p, Point a, Point b) {
    if (b < a) swap(a, b);
    return p == a || p == b || (a < p && p < b);
}

bool segmentIntersection(Point a, Point b, Point c, Point d, Point& p) {
    if (!lineIntersection(a, b, c, d, p))
        return paralleSegments(a, b, c, d, p);
    return inBoundingRectangle(p, a, b) && inBoundingRectangle(p, c, d);
}

// 교차여부만 판별
const int MAX = 4;
int segmentIntersects(Point a, Point b, Point c, Point d) {
    if (ccw(a, b, c) == 0 && ccw(a, b, d) == 0) { // 두선분 모두 한 직선위 일때
        if (b < a) swap(a, b);
        if (d < c) swap(c, d);
        if (b < c || d < a)  return 0; // 교차하지 않을때
        else if (b == c || d == a) // 한점에서 교차할때
            return 1;
        else return MAX; // 선분교차 - 무수히 많은점 교차
    } else { // 한직선 위가 아닐때
        int ab = ccw(a, b, c) * ccw(a, b, d); // 직선ab와 선분cd 교차 확인시 ab만 사용
        int cd = ccw(c, d, a) * ccw(c, d, b);
        return ab <= 0 && cd <= 0;
    }
}

Point perpendicularFoot(Point p, Point a, Point b){
    return a + (p-a).project(b-a);
}

double pointToLine(Point p, Point a, Point b) {
    return (p - perpendicularFoot(p,a,b)).norm();
}

void convexHull(vector<Point> &v, vector<Point> &hull){
    if(v.size()<3) return;
    swap(v[0],*min_element(v.begin(), v.end()));  
    sort(++v.begin(), v.end(), [&](Point a, Point b) -> bool {
        int ret = ccw(v[0], a, b);
        return ret > 0  || (ret==0 && a < b);
    });

    hull.clear();
    hull.emplace_back(v[0]);
    hull.emplace_back(v[1]);
    for(int i=2; i<v.size(); i++){
        while(hull.size()>1 && ccw(v[i], hull[hull.size()-2], hull[hull.size()-1])<=0){
            hull.pop_back();
        }
        hull.emplace_back(v[i]);
    }
}

// 점pt들중 볼록다각형 hull내부에 위치한 점들을 res에 저장
// 겹치는점, 다각형의 선 위에 위치한 점 포함 !!!!!
void pointInConvexPoly(vector<Point> &hull, vector<Point> &pt, vector<Point> &res){
    //hull의 size()가 2개인 경우(=직선인경우) 포함
    int s=hull.size()-1;
    int mid = max_element(hull.begin(), hull.end())-hull.begin();

    vector<Point> lowerHull, upperHull;
    upperHull.emplace_back(hull[0]);

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
}