// <교차점> - BOJ_10255
// 기하 (선분 교차 판단)

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
    double norm() const { return hypot(x,y); }
    vector2 normalize() const {
        return vector2(x/norm(), y/norm());
    }
    // 내적,외적
    double dot(const vector2& rhs) const {
        return x * rhs.x + y * rhs.y;
    }
    double cross(const vector2& rhs) const {
        return x * rhs.y - rhs.x * y;
    }
};

int ccw(vector2 p, vector2 a, vector2 b) {
    double ret = (a-p).cross(b-p);
    if (fabs(ret) < EPSILON) return 0;
    else if(ret < 0) return -1;
    else return 1;
}

int segmentIntersects(vector2 a, vector2 b, vector2 c, vector2 d) {
    if (ccw(a, b, c) == 0 && ccw(a, b, d) == 0) { // 한직선위에 두 선분
        if (b < a) swap(a, b);
        if (d < c) swap(c, d);
        if (b < c || d < a) // 교차하지 않을때
            return 0;
        else if (b == c || d == a) // 한점만 교차할때
            return 1;
        else return MAX; // 선교차(무수히 많을 점)일때
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
        vector2 sq[4];
        vector2 line[2];
        for (int i = 0; i < 3; i += 2) { //sq[0]에 사각형 왼쪽아래, sq[2]에 오른쪽위 좌표 저장
            cin >> sq[i].x >> sq[i].y;
        }
        //sq[0]: 왼쪽아래, 1++: sq[0]에서부터 반시계방향의 점
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
