#include <bits/stdc++.h>
using namespace std;
#define xx first
#define yy second
typedef long long ll;
const double EPSILON = 1e-9;
const double PI = acos(-1);

struct vector2 {
    double x, y;
    vector2(double x_=0, double y_=0) :x(x_), y(y_){}
    
    bool operator==(const vector2& rhs) const {
        return x == rhs.x && y == rhs.y;
    }
    bool operator<(const vector2& rhs) const {
        return x != rhs.x ? x < rhs.x : y < rhs.y;
    }
    vector2 operator+(const vector2& rhs) const {
        return vector2(x + rhs.x, y + rhs.y);
    }
    vector2 operator-(const vector2& rhs) const {
        return vector2(x - rhs.x, y - rhs.y);
    }
    vector2 operator*(double rhs) const {
        return vector2(x * rhs, y * rhs);
    }
    double norm() const { return hypot(x,y); }
    vector2 normalize() const {
        return vector2(x/norm(), y/norm());
    }
    double polar() const {return fmod(atan2(y, x)+2*PI, 2*PI); }
    double dot(const vector2& rhs) const {
        return x * rhs.x + y * rhs.y;
    }
    double cross(const vector2& rhs) const {
        return x * rhs.y - rhs.x * y;
    }
    vector2 project(const vector2& rhs) const{
        vector2 r = rhs.normalize();
        return r*r.dot(*this);
    }
};

double howMuchCloser(vector2 p, vector2 a, vector2 b){
    return (b-p).norm() - (a-p).norm();
}

int ccw(vector2 p, vector2 a, vector2 b) {
    double ret = (a-p).cross(b-p);
    if (fabs(ret) < EPSILON) return 0;
    else if(ret < 0) return -1;
    else return 1;
}
ll ccw2(vector2 p, vector2 a, vector2 b) {
    ll ret = (a-p).cross(b-p);
    return ret;
}

bool lineIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2& x) {
    double det = (b - a).cross(d - c);
    if (fabs(det) < EPSILON) return false;
    x = a + (b - a) * ((c - a).cross(d - c) / det);
    return true;
}

bool paralleSegments(vector2 a, vector2 b, vector2 c, vector2 d, vector2& p) {
    if (b < a) swap(a, b);
    if (d < c) swap(c, d);
    if (ccw(a, b, c) != 0 || b < c || d < a) return false;
    if (a < c) p = c;
    else p = a;
    return true;
}

bool inBoundingRectangle(vector2 p, vector2 a, vector2 b) {
    if (b < a) swap(a, b);
    return p == a || p == b || (a < p && p < b);
}

bool segmentIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2& p) {
    if (!lineIntersection(a, b, c, d, p))
        return paralleSegments(a, b, c, d, p);
    return inBoundingRectangle(p, a, b) && inBoundingRectangle(p, c, d);
}

const int MAX = 4;
int segmentIntersects(vector2 a, vector2 b, vector2 c, vector2 d) {
    if (ccw(a, b, c) == 0 && ccw(a, b, d) == 0) {
        if (b < a) swap(a, b);
        if (d < c) swap(c, d);
        if (b < c || d < a)  return 0;
        else if (b == c || d == a)
            return 1;
        else return MAX;
    } else {
        int ab = ccw(a, b, c) * ccw(a, b, d);
        int cd = ccw(c, d, a) * ccw(c, d, b);
        return ab <= 0 && cd <= 0;
    }
}

vector2 perpendicularFoot(vector2 p, vector2 a, vector2 b){
    return a + (p-a).project(b-a);
}

double pointToLine(vector2 p, vector2 a, vector2 b) {
    return (p - perpendicularFoot(p,a,b)).norm();
}

typedef pair<vector2, vector2> line;
int N;
vector<line> v;
vector<line> st;
vector2 sq[4] = {{-10.0,-10.0},{10.0,-10.0},{10.0,10.0},{-10.0,10.0}};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        double a, b, c, d;
        cin >> a >> b >> c >> d;
        v.push_back(line(vector2(a, b), vector2(c, d)));
    }

    int cp=0;
    for (int i = 0; i < v.size(); i++) {
        cp=0;
        for (int j = 0; j < 4; j++) {
            vector2 p = sq[j];
            vector2 q = sq[(j + 1) % 4];
            cp += segmentIntersects(v[i].xx, v[i].yy, p,q);
            if (cp >= MAX) {cp=MAX; break;}
            if (segmentIntersects(v[i].xx, v[i].yy, p,p)) {
                cp--;
            }
        }
        if(cp==2) st.push_back(v[i]);
    }

    int cnt = 0;
    vector2 chk;
    for (int i = 0; i < st.size(); i++) {
        for (int j = i + 1; j < st.size(); j++) {
            bool flag = 0;
            if (segmentIntersection(st[i].xx, st[i].yy, st[j].xx, st[j].yy, chk)) {
                for(int k=0; k<4; k++){
                    vector2 p = sq[k];
                    vector2 q = sq[(k + 1) % 4];
                    if(ccw(chk,p,q)>0) continue;
                    else {flag=1; break;}
                }
                if (flag) continue;
                else cnt++;
            }
        }
    }
    if(st.size()) cout<<st.size()+1+cnt;
    else cout<<1;
}
