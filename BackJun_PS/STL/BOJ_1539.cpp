// map, lower_bound, iterator 이용

#include<bits/stdc++.h>
#define xx first
#define yy second
#define MAX_N 250000
using namespace std;
typedef long long ll;

ll N;
map<ll,ll> m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;

    ll sum=0, iter, k, k2;
    for(int i=0; i<N; i++) {
        cin>>k;
        auto iter = m.lower_bound(k);
        if(iter==m.begin()) k2 = iter->yy + 1LL;
        else if(iter==m.end()) k2 = (--iter)->yy + 1LL;
        else {
            k2 = iter->yy;
            k2 = max(k2, (--iter)->yy) + 1LL;
        }
        m[k] = k2;
        sum += k2;
    }

    cout<<sum;
}