#include <bits/stdc++.h>
using namespace std;
#define aa first
#define bb second
#define EPSILON 0.0001
struct vector2;
typedef pair<vector2, vector2> pr;

const double PI = 2.0 * acos(0.0);
struct vector2 { // 2차원 벡터 표현(p519)
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
    //벡터길이 반환
    double norm() const { return hypot(x,y); }
    //단위벡터 반환, 영벡터에 대해 호출한 경우 반환 값은 정의되지 않음
    vector2 normalize() const {
        return vector2(x/norm(), y/norm());
    }
    // x축의 양의 방향으로부터 이 벡터까지 반시계 방향으로 잰 각도
    double polar() const {return fmod(atan2(y, x)+2*PI, 2*PI); }
    // 내적,외적
    double dot(const vector2& rhs) const {
        return x * rhs.x + y * rhs.y;
    }
    double cross(const vector2& rhs) const {
        return x * rhs.y - rhs.x * y;
    }
    //이 벡터를 rhs에 사영한 결과
    vector2 project(const vector2& rhs) const{
        vector2 r = rhs.normalize();
        return r*r.dot(*this);
    }
};

// a가 b보다 p에 얼마나 가까운지
double howMuchCloser(vector2 p, vector2 a, vector2 b){
    return (b-p).norm() - (a-p).norm();
}
// 같은 직선상에 놓인경우(기울기 같은경우) false리턴
bool lineIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2& x) {
    double det = (b - a).cross(d - c);
    if (fabs(det) < EPSILON) return false;
    x = a + (b - a) * ((c - a).cross(d - c) / det);
    return true;
}

double ccw(vector2 a, vector2 b) {
    return a.cross(b);
}
// 교차점p기준 a->b 시계방향인지 반시계인지 확인
double ccw(vector2 p, vector2 a, vector2 b) {
    return ccw(a - p, b - p);
}
// 두 직선이 평행할때 교차했는지 판별, 교차점이 무수히 많은 경우 교차점은 아무거나 반환
bool paralleSegments(vector2 a, vector2 b, vector2 c, vector2 d, vector2& p) {
    if (b < a) swap(a, b);
    if (d < c) swap(c, d);
    if (ccw(a, b, c) != 0 || b < c || d < a) return false;
    if (a < c) p = c;
    else p = a;
    return true;
}
// 선분(ab)위 점(p)인지 확인
bool inBoundingRectangle(vector2 p, vector2 a, vector2 b) {
    if (b < a) swap(a, b);
    return p == a || p == b || (a < p && p < b);
}

bool segmentIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2& p) {
    if (!lineIntersection(a, b, c, d, p))
        return paralleSegments(a, b, c, d, p);
    return inBoundingRectangle(p, a, b) && inBoundingRectangle(p, c, d);
}
// 교차여부만 판별
bool sementIntersects(vector2 a, vector2 b, vector2 c, vector2 d) {
    double ab = ccw(a, b, c) * ccw(a, b, d);
    double cd = ccw(c, d, a) * ccw(c, d, b);

    if (ab == 0 && cd == 0) {
        if (b < a) swap(a, b);
        if (d < c) swap(c, d);
        return !(b < c || d < a);
    }
    return ab <= 0 && cd <= 0;
}
// 점 p에서 (a,b)직선에 내린 수선의 발 구함
vector2 perpendicularFoot(vector2 p, vector2 a, vector2 b){
    return a + (p-a).project(b-a);
}
//점p와 (a,b)직선 사이의 거리를 구한다.
double pointToLine(vector2 p, vector2 a, vector2 b) {
    return (p - perpendicularFoot(p,a,b)).norm();
}

/*----------------------------------------------------------------------------------*/
// 아래는 <정사각형 자르기> - BOJ_1604 코드
int N;
vector<pr> v;
vector<pr> st;
pr sq[4] = {
    {{-10, 10}, {10, 10}},
    {{-10, -10}, {10, -10}},
    {{-10, 10}, {-10, -10}},
    {{10, 10}, {10, -10}},
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        v.push_back({vector2(a, b), vector2(c, d)});
    }

    vector2 chk;
    for (int i = 0; i < v.size(); i++) {
        int flag1 =0, flag2 =0;
        for (int j = 0; j < 4; j++) {
            if (segmentIntersection(v[i].aa, v[i].bb, sq[j].aa, sq[j].bb, chk)) {                
                if ((chk.x == 10 || chk.x == -10) && (chk.y == 10 || chk.y == -10))
                    flag2++;
                else flag1++;
            }
        }
        if (flag1) st.push_back(v[i]);
        if (flag2==4) st.push_back(v[i]);
    }

    int cnt = 0;
    for (int i = 0; i < st.size(); i++) {
        for (int j = i + 1; j < st.size(); j++) {
            if (segmentIntersection(st[i].aa, st[i].bb, st[j].aa, st[j].bb, chk)) {
                if (chk.x >= 10 || chk.x <= -10 || chk.y >= 10 || chk.y <= -10)
                    continue;
                else
                    cnt++;
            }
        }
    }
    if(st.size()) cout<<st.size()+1+cnt;
    else cout<<0;
}
