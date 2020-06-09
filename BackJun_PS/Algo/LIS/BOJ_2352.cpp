// <반도체 설계> - BOJ_2352
// LIS(Longest Increase Subsequence) : 이분탐색 이용
// 최대값에 -INF 넣는거 확인

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9;

int N;
int m[40000]{};
int dp[40001];
vector<int> vt;                                                                                                                                                                                                                                                                                                                                                                     

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    
    for(int i=0; i<N; i++)
        cin>>m[i];

    /*
    for (int i = 0; i < N; i++) {
        if (dp[i] == 0) dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (m[i] > m[j]) {
                if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
            }
        }
    }
    int max_=0;
    for(int i=0; i<N; i++) 
        max_ = max(dp[i],max_);
    
    cout<<max_;
    */

    int ans =0;
    vt.push_back(-INF);
    for (int i = 0; i < N; i++) {
        if (vt.back() < m[i]) {
            vt.push_back(m[i]);
            ans++;
        }
        else {
            auto it = lower_bound(vt.begin(), vt.end(), m[i]);
            *it = m[i];
        }
    }

    cout<<'\n'<<ans;
}