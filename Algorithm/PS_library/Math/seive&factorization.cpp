#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define xx first
#define yy second
#define all(v) (v).begin(), (v).end()

bool isPrime(ll num) { // 단순 확인 함수
    if(num<2LL) return false;
    for(ll i=2; i*i<=num; i++){
        if(num%i == 0) return false;
    }
    return true;
}

const int MAX = 200100;
int sieve[MAX+1];
void find_prime(){ // 전처리 하는 함수
    memset(sieve, -1, sizeof(sieve));
    for(ll i=2; i*i<=MAX; ++i)
        if(sieve[i] == -1)
            for(ll j=i*i; j<=MAX; j+=i)
                if(sieve[j] == -1)
                    sieve[j] = i;
}
vector<int> f[MAX];
map<int, int> cnt;
void fac(int x){ // 전처리한 내용을 통해 소인수분해
    cnt.clear();
    while(sieve[x] != -1){
        cnt[sieve[x]] += 1;
        x /= sieve[x];
    }
    cnt[x] += 1;
    for(auto &p : cnt) // f에 그냥 취합, cnt는 수 하나하나 소인수분해한것
        f[p.xx].emplace_back(p.yy);
}

// pow는 실수제곱도 가능해서 정수 넣으면 실수 오차생길 수 있음. 
// a^b를 log n 만에 구해주는 함수
ll fastp(ll x, ll y){
    if(y == 0) return 1;
    if(y&1) return x * fastp(x, y-1);
    auto tmp = fastp(x, y/2);
    return tmp * tmp;
}
int n;
vector<int> a;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    find_prime();

    cin >> n;
    a.resize(n);
    for(int i=0; i<n; ++i) {
        cin >> a[i];
        fac(a[i]);
    }
    ll ans = 1;
    for(int i=2; i<MAX; ++i){
        auto &v = f[i];
        if(v.size() == 0) continue;
        sort(all(v));
        //cout << i << " : "; for(auto j : v) cout << j << ' '; cout << endl;
        if(v.size() == n) ans *= fastp(i, v[1]);
        else if(v.size()+1 == n) ans *= fastp(i, v[0]);
    }
    cout << ans;
}

/* //input
4
24 10 40 80

*/