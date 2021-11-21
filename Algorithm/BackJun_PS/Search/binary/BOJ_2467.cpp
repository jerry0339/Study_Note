#include<bits/stdc++.h>
using namespace std;
#define abs(x) ((x) < 0 ? (-(x)) : (x))
typedef long long ll;
const ll INF = 2000000000LL;

ll N;
ll m[100010]{};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    ll n;
    for(ll i=0; i<N; i++) {
        cin>>m[i];
        if(m[i]>=0) n = i;
    }
    
    ll min_=INF ,min1=INF, min2=INF;
    for(ll i=0; i<n; i++) {
        auto k = lower_bound(m,m+N,m[i]*-1);
        ll a = k-m;
        if(a == i) a++;
        ll b = k-m-1;
        if(b == i) b--;
        ll asum, bsum;
        if(a < N && a >= 0) {
            asum = abs(m[a] + m[i]);
        } else asum = INF;
        if(b < N && b >= 0) {
            bsum = abs(m[b] + m[i]);
        } else bsum = INF;
        if(asum < bsum){
            if(asum < min_) {
                min_ = asum;
                min1 = i;
                min2 = a;
            }
        }else {
            if(bsum < min_) {
                min_ = bsum;
                min1 = i;
                min2 = b;
            }
        }
    }
    cout<<m[min1]<<' '<<m[min2];
}