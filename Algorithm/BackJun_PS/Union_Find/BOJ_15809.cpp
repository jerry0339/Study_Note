#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
using pii = pair<int,int>;
using tpi = tuple<int,int,int>;
using dpi = pair<pii,pii>;
using pis = pair<int,string>;

const int INF = 0x3f3f3f3f;

int N,M;
int am[100001]{};
int par[100001]{};
int vi[100001]{};

int find(int k) {
    if (k == par[k]) return k;
    else return par[k] = find(par[k]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    par[a] = b;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i=0; i<=N; i++) par[i] = i;
    for(int i=1; i<=N; i++) cin>>am[i];

    int o,p,q; // 1:war, 2:ally
    for(int i=0; i<M; i++){
        cin>>o>>p>>q;
        int a = find(p);
        int b = find(q);
        
        if(o==2){
            if(am[a]>am[b]){
                am[a] -= am[b];
                merge(b,a);
            } else {
                am[b] -= am[a];
                merge(a,b);
            }
        } else {
            am[b] += am[a];
            merge(a,b);
        }

    }

    vector<int> res;
    for(int i=1; i<=N; i++){
        int now = find(i);
        if(vi[now] || am[now]==0) continue;
        res.push_back(am[now]);
        vi[now] = true;
    }
    sort(res.begin(), res.end());

    cout<<res.size()<<'\n';
    for(auto val : res){
        cout<<val<<' ';
    }
}
