#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

ll N;
ll m[500001]{};
stack<pll> stk;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    ll t;
    for(ll i=0; i<N; i++) cin>>m[i];

    ll ans=0;
    for(ll i=0; i<N; i++){
        if(stk.empty()) {
            stk.push({m[i], 1});
            continue;
        }
        ll cn = m[i];
        ll pn = stk.top().xx;
        ll pc = stk.top().yy;
        if(pn > cn) {
            stk.push({cn, 1});
            ans++;
        } else if(pn == cn) {
            if(stk.size()==pc) ans += pc;
            else ans += (pc+1);
            stk.push({cn, pc+1});
        } else { // pn < cn
            while (stk.top().xx < cn){
                ans++;
                stk.pop();
                if(stk.empty()) break;
            }
            i--;
        }
    }
    cout<<ans;
}