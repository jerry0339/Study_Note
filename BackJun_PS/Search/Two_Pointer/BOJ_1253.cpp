// <좋다> BOJ_1253
// Two Pointer

#include<bits/stdc++.h>
using namespace std;

int N;
int v[2001];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=1; i<=N; i++) cin>>v[i];
    sort(v+1,v+N+1);
    
    int cnt=0;
    for(int i=1; i<=N; i++){
        int l=1, r=N;
        while(l<r){
            int cn = v[l]+v[r];
            if(cn < v[i]) l++;
            else if(cn > v[i]) r--;
            else { // cn == v[i]
                if (l!=i && r!=i) {
					cnt++;
					break;
				}
				if (r==i) {
					r--;
				} else if (l==i) {
					l++;
				}
            }

        }
    }
    cout<<cnt;
}