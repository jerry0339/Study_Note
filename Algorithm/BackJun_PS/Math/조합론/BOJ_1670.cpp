// 카탈란 수

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 987654321;

int N;
ll dp[10010]{};

ll func(int n) {
    if(n%2) return 0;
    if(n==2 || n==0) return 1;
    ll &ret = dp[n];
    if(ret!=0) return ret;
    for(int i=2; i<=n; i+=2) {
        ret += (func(i-2) * func(n-i))%MOD;
        ret %= MOD;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    
    cout<<func(N);
}