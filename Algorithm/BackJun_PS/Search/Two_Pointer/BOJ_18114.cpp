// <블랙 프라이데이> - BOJ_18114
// Two-Pointer

#include<bits/stdc++.h>
using namespace std;

int N,C;
int m[5010]{};
int main() {
    ios_base::sync_with_stdio(0);  cin.tie(0);
    cin>>N>>C;
    for(int i=0; i<N; i++) cin>>m[i];
    sort(m,m+N);
    
    for(int i=0; i<N; i++) {
        int tmp;
        if(m[i]==C) {cout<<1; return 0;}
        else tmp = C-m[i];

        int l=i+1,r=N-1;
        while(l<r){
            if(m[l]+m[r] < tmp) l++;
            else if(m[l]+m[r] > tmp) r--;
            else {cout<<1; return 0;}
        }
    }

    for(int i=0; i<N; i++){ // 2개 선택할때 확인
        for(int j=i+1; j<N; j++){
            if(m[i]+m[j]==C) {cout<<1; return 0;}
        }
    }
    cout<<0;
}