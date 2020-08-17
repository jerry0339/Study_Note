#include<bits/stdc++.h>
using namespace std;

int N,M,L;
int v[102]{};
int sub[102]{};
int min_= 1000;

bool isP(int mid){
    int cnt =0;
    for(int i=1; i<=N+1; i++){ 
        cnt += sub[i]/mid;
        if(sub[i]%mid==0) cnt--;
    }
    return cnt > M;
}

int search(int l, int r) {
    int s,e,mid;
    s = l; e = r;

    while(s<=e){
        mid = (s+e)/2;
        if(isP(mid)) s = mid+1;
        else         e = mid-1;
    }
    return s;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M>>L;
    int t;
    v[N+1] = L;
    for(int i=1; i<=N; i++) cin>>v[i];
    sort(v,v+N+1);
    for(int i=1; i<=N+1; i++) sub[i] = v[i]-v[i-1];

    cout<<search(0,1000);
}