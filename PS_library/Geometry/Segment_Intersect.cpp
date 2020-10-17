#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Point {
    ll x, y;
    Point(ll x_=0, ll y_=0) :x(x_), y(y_){}
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
    Point operator*(ll pt) const {
        return Point(x * pt, y * pt);
    }
    ll dot(const Point& pt) const {
        return x * pt.x + y * pt.y;
    }
    ll cross(const Point& pt) const {
        return x * pt.y - pt.x * y;
    }
};

int ccw(Point p, Point a, Point b) {
    ll ret = (a-p).cross(b-p);
    if (ret==0) return 0;
    else if(ret < 0) return -1;
    else return 1;
}

int segmentIntersects(Point a, Point b, Point c, Point d) {
    if (ccw(a, b, c) == 0 && ccw(a, b, d) == 0) {
        if (b < a) swap(a, b);
        if (d < c) swap(c, d);
        if (b < c || d < a) return 0;
        else return 1;
    } else {
        int ab = ccw(a, b, c) * ccw(a, b, d);
        int cd = ccw(c, d, a) * ccw(c, d, b);
        return ab <= 0 && cd <= 0;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        Point sq[4];
        Point line[2];
        cin >> line[0].x >> line[0].y >> line[1].x >> line[1].y;
        ll a,b,c,d,t;
        cin>>a>>b>>c>>d;
        if(a>c) {swap(a,c); swap(b,d);}
        if(b>d) {sq[3].x=a; sq[3].y=b; sq[1].x=c; sq[1].y=d;}
        else {sq[3].x=a; sq[3].y=d; sq[1].x=c; sq[1].y=b;}
        sq[2].x = sq[1].x;
        sq[0].y = sq[1].y;
        sq[0].x = sq[3].x;
        sq[2].y = sq[3].y;
        
        bool ans1 = false;
        bool ans2 = true;
        for (int i = 0; i < 4; ++i) {
            Point a = line[0];
            Point b = line[1];
            Point p = sq[i];
            Point q = sq[(i + 1) % 4];
            if(segmentIntersects(a, b, p, q)) ans1 = true;      // ans1 : 선분 교차판정
            if(!(ccw(a,p,q)==1 && ccw(b,p,q)==1)) ans2 = false; // ans2 : 점a, b가 사각형 외부이거나 사각형 위라면 false로 set
        }
        if(ans1 || ans2) cout<<"T"<<'\n';
        else cout<<"F"<<'\n';
    }
}
