#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tpi = tuple<int,int,int>;
using tpl = tuple<ll,ll,ll>;
using dpi = pair<pii,pii>;
using dpl = pair<pll,pll>;
using pis = pair<int,string>;
using psi = pair<string,int>;

const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;

int N;
int m[500001]{};
int ans[500001]{};
vector<pii> stk;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(ans,-1,sizeof(ans));
    cin>>N;
    for(int i=0; i<N; i++) cin>>m[i];
    for(int i=N-1; i>=0; i--){
        int now = m[i];
        if(stk.size()!=0) {
            while(!stk.empty()){
                pii pre = stk.back();
                if(now>pre.yy) {
                    ans[pre.xx] = i;
                    stk.pop_back();
                } else {
                    break;
                }
            }
        }
        stk.push_back({i, now});
    }

    for(int i=0; i<N; i++) cout<<ans[i]+1<<' ';
}
