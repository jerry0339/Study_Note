#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL)
#define abs(x) ((x) < 0 ? (-(x)) : (x))
ll gcd(ll a, ll b) {return b ? gcd(b, a%b) : a;}
int gcd(int a, int b) {return b ? gcd(b, a%b) : a;}

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<string>
#include<memory.h>
#include<math.h>
#define ini(x, y) memset(x, y, sizeof(x))
#define rall(v) (v).rbegin(), (v).rend()
#define all(v) v.begin(),v.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const int INF = 0x3f3f3f3f;
const long long llINF = 1e18;

struct Info{
    int d,y,x;
    bool operator < (const Info &t) const {
        return d < t.d;
    }
    Info(int d_=0, int y_=0, int x_=0) :d(d_), y(y_), x(x_){}
};

struct comp{ // priority_queue-> min heap
    bool operator()(Info &a, Info &b){
        return a.d > b.d;
    }
};

priority_queue<int, vector<int>, comp> pq;

int N,M,T;

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cin>>T;
    while(T--){
        cin>>N>>M;
    }

    double ans = 0.123456789;
    cout.precision(2);
    cout<<fixed;
    cout<<ans<<'\n';
}
