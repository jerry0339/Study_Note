// 예시 BOJ_2110

#include<bits/stdc++.h>
using namespace std;

int N,M;
int m[200001]{};

bool isP(int mid){
    int res=1, tmp=m[0];
    for(int i=1; i<N; i++){
        if(tmp+mid <= m[i]) {
            res++;
            tmp = m[i];
        }
    }
    if(res >= M) return true;
    else return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i=0; i<N; i++) cin>>m[i];
    sort(m,m+N);
    
    int s=1, e=m[N-1]-m[0];
    while(s<=e){
        int mid = (s+e)/2;
        if(isP(mid)) s = mid + 1;
        else e = mid - 1;
    }

    cout<<e;
}

// 함수
int lowerBoundEx(int l, int r){
    int s = l, e = r, mid;
    while(s<=e){
        mid = (s+e)/2;
        if(!isP(mid)) s = mid + 1;
        else e = mid - 1;
    }

    return s;
}