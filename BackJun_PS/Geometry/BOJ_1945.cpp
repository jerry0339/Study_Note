// <직사각형> - BOJ_1945
// 기하

#include <bits/stdc++.h>
using namespace std;
#define xx first
#define yy second
#define all(x) x.begin(), x.end()
typedef long long ll;

struct vector2 {
    ll x, y;
    vector2(ll x_=0, ll y_=0) :x(x_), y(y_){}
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
    vector2 operator*(ll rhs) const {
        return vector2(x * rhs, y * rhs);
    }
    ll dot(const vector2& rhs) const {
        return x * rhs.x + y * rhs.y;
    }
    ll cross(const vector2& rhs) const {
        return x * rhs.y - rhs.x * y;
    }
};

int ccw(vector2 p, vector2 a, vector2 b) {
    ll ret = (a-p).cross(b-p);
    if (ret==0) return 0;
    else if(ret < 0) return -1;
    else return 1;
}

int segmentIntersects(vector2 a, vector2 b, vector2 c, vector2 d) {
    int ab = ccw(a, b, c) * ccw(a, b, d);
    return ab <= 0;
}

typedef pair<vector2, vector2> line;
int N;
vector<line> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    vector2 lp={(ll)1e10,0}, rp={0,(ll)1e10};
    for(int i=0; i<N; i++){
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        v.emplace_back(line(vector2(a,d),vector2(c,b)));
    }

    int max_=0;
    for(int i=0; i<N; i++){ // 직선
        int lcnt=0, rcnt=0;
        for(int j=0; j<N; j++){ // 사각형 대각선분
            if(segmentIntersects(vector2(0,0),v[i].xx,v[j].xx,v[j].yy)) lcnt++;
            if(segmentIntersects(vector2(0,0),v[i].yy,v[j].xx,v[j].yy)) rcnt++;
        }
        max_ = max({max_,lcnt,rcnt});
    }
    cout<<max_;
}
