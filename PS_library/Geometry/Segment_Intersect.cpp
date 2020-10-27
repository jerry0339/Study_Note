// <교차점> - BOJ-10255
// 선분 교차 판정

#include <bits/stdc++.h>
using namespace std;
const double EPSILON = 1e-9;
const int MAX = 4;

const double PI = 2.0 * acos(0.0);
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

int ccw(vector2 p, vector2 a, vector2 b) {
    double ret = (a-p).cross(b-p);
    if (fabs(ret) < EPSILON) return 0;
    else if(ret < 0) return -1;
    else return 1;
}

int segmentIntersects(vector2 a, vector2 b, vector2 c, vector2 d) {
    int ab = ccw(a, b, c) * ccw(a, b, d);
    int cd = ccw(c, d, a) * ccw(c, d, b);

    if (!ccw(a, b, c) && !ccw(a, b, d)) {//평행일때
        if (b < a) swap(a, b);
        if (d < c) swap(c, d);
        if (b < c || d < a) // 교차하지 않을때
            return 0;
        else if (b == c || d == a) // 한점만 교차일때
            return 1;
        else return MAX; // 선교차(무수히 많은 점)일때
    }
    return ab <= 0 && cd <= 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        vector2 sq[4];
        vector2 line[2];
        for (int i = 0; i < 3; i += 2) {
            cin >> sq[i].x >> sq[i].y;
        }
        sq[1].x = sq[2].x;
        sq[1].y = sq[0].y;
        sq[3].x = sq[0].x;
        sq[3].y = sq[2].y;
        cin >> line[0].x >> line[0].y >> line[1].x >> line[1].y;
        int ans = 0;
        for (int i = 0; i < 4; ++i) {
            vector2 a = line[0];
            vector2 b = line[1];
            vector2 p = sq[i];
            vector2 q = sq[(i + 1) % 4];
            ans += segmentIntersects(a, b, p, q);
            if (ans >= MAX) {
                ans = MAX;
                break;
            }
            if (segmentIntersects(a, b, p, p)) {
                ans--;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
