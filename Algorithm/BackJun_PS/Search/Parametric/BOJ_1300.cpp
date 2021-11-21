// <K번째 수>
// 이분탐색

#include<bits/stdc++.h>
using namespace std;

int N,K;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;
    int l=1, r=K, mid;
    while(l<=r){
        mid = (l+r)/2;
        int cnt = 0;
        for(int i=1; i<=N; i++){
            if(mid/i>N){cnt+=N;}
            else{cnt+=mid/i;}
        }
        if(cnt<K) l=mid+1;
        else r=mid-1;
    }
    cout<<l;
}