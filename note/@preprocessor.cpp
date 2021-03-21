#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast")

#include<bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(x) (int)(x).size()
#define ini(x, y) memset(x, y, sizeof(x))
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL)
#define xx first
#define yy second
typedef pair<int, int> pii;
typedef long long ll;

int main() {
    FASTIO;

}

/*********************<priority_queue>***********************/
struct Info{
    int d,y,x;
    Info(int d_=0, int y_=0, int x_=0) :d(d_), y(y_), x(x_){}
};
struct comp{ // min heap
    bool operator()(Info &a, Info &b){
        return a.d > b.d;
    }
};

// priority_queue<자료형, 구현체, 비교 연산자>
// 구현체는 기본적으로 vector위에서 돌아감.
priority_queue<int, vector<int>, comp> pq;
/************************************************************/

#define abs(x) ((x) < 0 ? (-(x)) : (x))
ll gcd(ll a, ll b) {return b ? gcd(b, a%b) : a;}
int gcd(int a, int b) {return b ? gcd(b, a%b) : a;}

typedef unsigned long long ull;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<string, int> psi;
typedef pair<char, int> pci;
typedef pair<int, char> pic;
