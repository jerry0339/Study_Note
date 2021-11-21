// O(N + X*(logQ)^2) : X -> 쿼리로 주어진 K의 합
#include<bits/stdc++.h>
#define xx first
#define yy second
#define MAX 500001
using namespace std;
using ll = long long;

int N,Q;
map<int,pair<int,ll>> vertex[MAX]{};
int par[MAX]{};
int lev[MAX]{};
vector<int> stk[MAX]{};
bool vi[MAX]{};


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>Q;

    lev[1] = 0;
    for(int i=2; i<=N; i++){
        cin>>par[i];
        lev[i] = lev[par[i]] + 1;
    }

    int k,t, maxlev=0;
    for(int q=1; q<=Q; q++){
        cin>>k;
        while(k--){
            cin>>t;
            vertex[t][q] = {1,0};
            if(!vi[t]) {
                maxlev = max(maxlev, lev[t]);
                stk[lev[t]].push_back(t);
                vi[t] = true;
            }
        }
    }

    for(int i=maxlev; i>0; i--){
        for(auto cn : stk[i]){
            int nn = par[cn];
            int nlev = lev[nn];
            if(vertex[cn].size() > vertex[nn].size()) vertex[cn].swap(vertex[nn]);

            for(auto val : vertex[cn]){
                int idx = val.xx;
                int cnum = val.yy.xx;
                ll csum = val.yy.yy;
                if(vertex[nn].count(idx)==0) vertex[nn][idx] = {cnum, csum};
                else {
                    pair<int,ll> &next = vertex[nn][idx];
                    int &nnum = next.xx;
                    ll &nsum = next.yy;
                    nsum += ((ll)cnum*nnum*nlev + csum);
                    nnum += cnum;
                }
            }
            if(!vi[nn]) {
                stk[nlev].push_back(nn);
                vi[nn] = true;
            }
        }
    }

    for(auto val : vertex[1]){
        cout<<val.yy.yy<<'\n';
    }
}