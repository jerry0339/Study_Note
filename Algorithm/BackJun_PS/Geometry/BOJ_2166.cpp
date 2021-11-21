// <다각형의 면적> - BOJ_2166
// 기하 - CCW,
// N개의 점으로 이루어진 다각형의 면적 - (신발끈 공식)
// 절대값 처리는 ccw를 이용하여 면적을 다 더한 후 처리한다.

#include <bits/stdc++.h>
using namespace std;
#define xx first
#define yy second
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

ll ccw(vector2 p, vector2 a, vector2 b) {
    ll ret = (a-p).cross(b-p);
    return ret;
    // ret이 음수가 나올 수 있지만, 여기서 절대값 처리하면 오류남.
    // 면적 계산중 -해야하는 면적이 있을 수도 있음.
}

int N;
vector<vector2> v;

int main() {
    cin >> N;

    for(int i=0; i<N; i++){
        ll a,b; cin>>a>>b;
        v.push_back(vector2(a,b));
    }

    ll res=0;
    for(int i=1; i<N-1; i++){
        res += ccw(v[0],v[i],v[i+1]);
    }
    
    if(res<0) res*=-1;
    if(res%2) cout<<res/2<<".5";
    else cout<<res/2<<".0";
}
