// <K번째 수> - BOJ_1300
// Parametric search

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int N,K;

bool isPossible(int mid){
    int cnt=0;
    for(int i=1; i<=N; i++){
        if(mid/i>N) cnt+=N;
        else cnt+=(mid/i);
    }
    return cnt<K;
}

int b_search(int l, int r){
    int s=l,e=r;
    int mid;

    while(s<=e){
        mid = (s+e)/2;
        if(isPossible(mid)) s = mid+1;
        else                e = mid-1;
    }
    return s;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;
    cout<<b_search(1,K);
}