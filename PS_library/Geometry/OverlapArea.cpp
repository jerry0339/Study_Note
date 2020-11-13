// <넓이> - BOJ_1077
// 기하학 종합세트
// 볼록 껍질, 선분 교차 판정, 볼록다각형 내부점 판정, 다각형넓이

#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define sz(x) (int)(x).size()
#define eb emplace_back
using namespace std;
const double EPSILON = 1e-11;

struct Point {
    double x, y;
    Point(double x_=0, double y_=0) :x(x_), y(y_){}
    bool operator==(const Point& pt) const {
        return x == pt.x && y == pt.y;
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
    double dot(const Point& pt) const {
        return x * pt.x + y * pt.y;
    }
    double cross(const Point& pt) const {
        return x * pt.y - pt.x * y;
    }
};

int ccw(Point p, Point a, Point b) {
    double ret = (a-p).cross(b-p);
    if (fabs(ret) < EPSILON) return 0;
    else if(ret < 0) return -1;
    else return 1;
}

double area(const vector<Point>&p){
    double ret=0;
    if(p.size()<3) return 0;
    for(int i=0;i<p.size();i++) {
        int j=(i+1)%p.size();
        ret+=p[i].cross(p[j]);
    }
    return fabs(ret)/2.0;
}

void convexHull(vector<Point> &v){
    if(v.size()<3) return;
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
    v = hull;
}

bool lineIntersection(Point a, Point b, Point c, Point d, Point& x) {
    double det = (b - a).cross(d - c);
    if (fabs(det) < EPSILON) return false;
    x = a + (b - a) * ((c - a).cross(d - c) / det);
    return true;
}

bool paralleSegments(Point a, Point b, Point c, Point d, Point& p) {
    if (b < a) swap(a, b);
    if (d < c) swap(c, d);
    if (ccw(a, b, c) != 0 || b < c || d < a) return false;
    if (a < c) p = c;
    else p = a;
    return true;
}

bool inBoundingRectangle(Point p, Point a, Point b) {
    if (b < a) swap(a, b);
    return p == a || p == b || (a < p && p < b);
}

bool segmentIntersection(Point a, Point b, Point c, Point d, Point& p) {
    if (!lineIntersection(a, b, c, d, p))
        return paralleSegments(a, b, c, d, p);
    return inBoundingRectangle(p, a, b) && inBoundingRectangle(p, c, d);
}

// 볼록다각형 "b"내부에 위치한 볼록다각형 "a"의 점을 res에 저장 (겹치는점, 다각형의 선 위에 위치한 점 포함)
void pointInConvexPoly(vector<Point> &a, vector<Point> &b, vector<Point> &res){
    for(int i=0; i<sz(a); i++){
        bool ptIn = true;
        Point np = a[i];
        for(int j=0; j<sz(b); j++){
            if(ccw(np,b[j],b[(j+1)%b.size()])<0) {
                ptIn=false;
                break;
            }
        }
        if(ptIn) res.eb(np);
    }
}

int N,M;
vector<Point> poly1;
vector<Point> poly2;
vector<Point> ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
	int a,b;
	for(int i=0; i<N; i++){cin>>a>>b; poly1.eb(Point(a,b)); }
    for(int i=0; i<M; i++){cin>>a>>b; poly2.eb(Point(a,b)); }
    
    convexHull(poly1); // 180도 점, 중복점 제거 포함
    convexHull(poly2); // 180도 점, 중복점 제거 포함
    pointInConvexPoly(poly1, poly2, ans);
    pointInConvexPoly(poly2, poly1, ans);

    for(int i=0; i<sz(poly1); i++){
        for(int j=0; j<sz(poly2); j++){
            Point x;
            if(segmentIntersection(poly1[i],poly1[(i+1)%poly1.size()],poly2[j],poly2[(j+1)%poly2.size()],x)){
                ans.eb(x);
            }
        }
    }

    convexHull(ans); // 180도 점, 중복점 제거 포함
    cout.precision(10);
    cout<<fixed;
    cout<<area(ans);
}