// <수 고르기> - BOJ_2230
// Two-pointer

#include<bits/stdc++.h>
using namespace std;

int N,M;
int m[100010]{};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i=0; i<N; i++)cin>>m[i];
    sort(m,m+N);

    int s=0,e=0, a=m[N-1]-m[0];
    while(s<=e && e<N){
        int t = m[e]-m[s];
        if(t>=M) {
            a = min(a, t);
            s++;
        } else e++;
    }
    cout<<a;
}