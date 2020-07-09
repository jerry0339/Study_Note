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

// 반환을 0,1,-1로 안해주면 밑의 다른함수에서 ccw()*ccw()계산이 4제곱이기 때문에 오버플로우 발생가능
int ccw(vector2 p, vector2 a, vector2 b) {
    double ret = (a-p).cross(b-p);
    if (fabs(ret) < EPSILON) return 0;
    else if(ret < 0) return -1;
    else return 1;
}
ll ccw2(vector2 p, vector2 a, vector2 b) { // 면적계산용( BOJ_2166 참고 )
    ll ret = (a-p).cross(b-p);
    return ret;
}

// 같은 직선상에 놓인경우(기울기 같은경우) false리턴
bool lineIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2& x) {
    double det = (b - a).cross(d - c);
    if (fabs(det) < EPSILON) return false;
    x = a + (b - a) * ((c - a).cross(d - c) / det);
    return true;
}

// lineIntersection결과가 false: 두직선이 평행할때
bool paralleSegments(vector2 a, vector2 b, vector2 c, vector2 d, vector2& p) {
    if (b < a) swap(a, b); // 벡터ab 방향이 ba라면 ab로 바꿔줌
    if (d < c) swap(c, d); // 벡터cd 방향이 dc라면 cd로 바꿔줌
    // 평행하지만 같은 직선에 있지않으면 ccw에 의해, 같은 직선위지만 선분ab,cd가 최소 한 점에서 교차하지 않으면 false
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
const int MAX = 4;
int segmentIntersects(vector2 a, vector2 b, vector2 c, vector2 d) {
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
