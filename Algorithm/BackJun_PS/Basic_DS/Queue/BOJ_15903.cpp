// greedy

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N,M;
priority_queue<ll,vector<ll>,greater<ll>> pq;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    ll k;
    for(ll i=0; i<N; i++){
        cin>>k;
        pq.push(k);
    }

    while(M--){
        ll t1 = pq.top(); pq.pop();
        ll t2 = pq.top(); pq.pop();
        ll sum = t1+t2;
        pq.push(sum);
        pq.push(sum);
    }

    ll res = 0;
    while(!pq.empty()){
        res += pq.top();
        pq.pop();
    }
    cout<<res;
}