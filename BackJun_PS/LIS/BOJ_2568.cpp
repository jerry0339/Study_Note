#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
typedef pair<int,int> pii;
const int INF = 0x3f3f3f3f;

int N;
vector<pii> m;
vector<int> lis;
int trace[100010]{};
bool vi[500010]{};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    int a,b,max_=0;
    for(int i=0; i<N; i++) {
        cin>>a>>b;
        m.push_back({a,b});
        max_ = max(max_, a);
        vi[a] = true;
    }

    sort(m.begin(), m.end(), [&](pii &x, pii &y) -> bool{
        if(x.xx == y.xx) return x.yy > y.yy;
        return x.xx < y.xx;
    });

    lis.push_back(-INF);
    for (int i = 0; i < m.size(); i++) {
        if (lis.back() < m[i].yy) {
            trace[i] = lis.size();
            lis.push_back(m[i].yy);
        }
        else {
            int idx = lower_bound(lis.begin(), lis.end(), m[i].yy) - lis.begin();
            trace[i] = idx;
            lis[idx] = m[i].yy;
        }
    }

    int length = lis.size()-1;
    cout<<N - length<<'\n';
    
    for(int i=N-1; i>=0; i--){
        if(trace[i] == length) {
            vi[m[i].xx] = false;
            length--;
            if(length < 1) break;
        }
    }
    
    for(int i=1; i<=max_; i++) {
        if(vi[i]) {
            cout<<i<<'\n';
        }
    }
}