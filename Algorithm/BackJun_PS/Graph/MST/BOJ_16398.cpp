#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
using ll = long long;
using tpl = tuple<ll,ll,ll>;

ll N,M;
ll par[1001]{};
ll m[1001][1001]{};
vector<tpl> edge;

ll find(ll k) {
    if (k == par[k]) return k;
    else return par[k] = find(par[k]);
}

void merge(ll a, ll b) {
    a = find(a);
    b = find(b);
    par[a] = b;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(ll i=0; i<N; i++) par[i] = i;
    for(ll i=0; i<N; i++){
        for(ll j=0; j<N; j++){
            cin>>m[i][j];
        }
    }
    
    for(ll i=0; i<N; i++){
        for(ll j=i+1; j<N; j++){
            edge.push_back({m[i][j], i, j});
        }
    }

    sort(edge.begin(), edge.end());
    
    ll res = 0;
    for(auto now : edge){
        ll d,a,b;
        tie(d,a,b) = now;
        if(find(a)==find(b)) continue;
        merge(a,b);
        res += d;
    }

    cout<<res;
}
