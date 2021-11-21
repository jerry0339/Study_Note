#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll N,M;
ll rm[1000]{};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    ll t, pre=0;
    for(ll i=1; i<=N; i++){
        cin>>t;
        ll next = (pre + t) % M;
        rm[next]++;
        pre = next;
    }

    rm[0]++;
    ll ans = 0;
    for(int i=0; i<M; i++){
        if(rm[i] < 2) continue;
        ans += rm[i] * (rm[i]-1) / 2;
    }
    cout<<ans;
}