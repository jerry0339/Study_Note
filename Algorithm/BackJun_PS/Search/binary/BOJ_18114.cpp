// <블랙 프라이데이> - BOJ_18114
// Binary Search 풀이 O(N^2 * logN)

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
        for(int j=i+1; j<N; j++){
            int tmp2;
            if(tmp==m[j]) {cout<<1; return 0;}
            else tmp2 = tmp-m[j];
            int ans = lower_bound(m+j+1,m+N,tmp2) - m;
            if(m[ans]==tmp2) {cout<<1; return 0;}
        }
    }
    cout<<0;
}