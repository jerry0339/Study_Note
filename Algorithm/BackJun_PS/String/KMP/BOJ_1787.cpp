#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
int dp[1000001]{}; // prefix와 suffix의 길이중 0을 제외한 가장 짧은 값 구하기

vector<int> getPi(string p){
    int m = (int)p.size(), j=0;
    vector<int> pi(m, 0);
    for(int i = 1; i< m ; i++){
        while(j > 0 && p[i] != p[j]) j = pi[j-1];
        if(p[i] == p[j]) pi[i] = ++j;
    }
    return pi;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    string str;
    cin>>str;
    auto fail = getPi(str);

    ll ans = 0;
    for(int i=0; i<fail.size(); i++){
        dp[i] = (fail[fail[i]-1] > 0 ? dp[fail[i]-1] : fail[i]);
        if (!dp[i]) continue;
        if (i+1 - dp[i] >= dp[i])
            ans += (i+1 - dp[i]);
    }
    cout<<ans;
}