#include<bits/stdc++.h>
using namespace std;

int N,K;
int arr[100001]{};
int presum[100001]{};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;
    for(int i=1; i<=N; i++){
        cin>>arr[i];
        presum[i] = presum[i-1] + arr[i];
    }
    int st=1, ed=1;
    int len;
    if(arr[1]>=K) len=1;
    else len=1e9;
    while(st<=ed && ed<=N){
        if(presum[ed]-presum[st-1]>=K){
            len = min(len, ed-st+1);
            st++;
        } else ed++;
    }

    if(len==1e9) cout<<0;
    else cout<<len;
}