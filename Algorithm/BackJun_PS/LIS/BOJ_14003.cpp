// LIS 역추적 : https://www.crocus.co.kr/681

#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int N;
int m[1000010]{};
int trace[1000010]{};
vector<int> lis;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0; i<N; i++) cin>>m[i];

    lis.push_back(-INF);
    for (int i = 0; i < N; i++) {
        if (lis.back() < m[i]) {
            trace[i] = lis.size();
            lis.push_back(m[i]);
        }
        else {
            int idx = lower_bound(lis.begin(), lis.end(), m[i]) - lis.begin();
            trace[i] = idx;
            lis[idx] = m[i];
        }
    }

    int length = lis.size()-1;
    cout<<length<<'\n';
    
    vector<int> ans;
    for(int i=N-1; i>=0; i--){
        if(trace[i] == length) {
            ans.push_back(i);
            length--;
            if(length < 1) break;
        }
    }

    for(int i=ans.size()-1; i>=0; i--) cout<<m[ans[i]]<<' ';
}