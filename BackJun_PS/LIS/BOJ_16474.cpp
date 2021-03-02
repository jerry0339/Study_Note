#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
typedef pair<int,int> pii;
const int INF = 0x3f3f3f3f;

int N,M,K;
int aa[2002]{}, bb[2002]{};
vector<int> lis;
vector<pii> m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;

    int t;
    for(int i=0; i<N; i++) {
        cin>>t;
        aa[t] = i;
    }
    for(int i=0; i<M; i++) {
        cin>>t;
        bb[t] = i;
    }

    cin>>K;
    int a,b;
    for(int i=0; i<K; i++){
        cin>>a>>b;
        m.push_back({aa[a],bb[b]});
    }
    
    sort(m.begin(), m.end(), [&](pii &x, pii &y) -> bool {
        if(x.xx == y.xx) return x.yy > y.yy;
        return x.xx < y.xx;
    });

    lis.push_back(-INF);
    for (int i = 0; i < m.size(); i++) {
        if (lis.back() < m[i].yy) lis.push_back(m[i].yy);
        else *lower_bound(lis.begin(), lis.end(), m[i].yy) = m[i].yy;
    }
    
    cout<<K - lis.size() + 1;
}