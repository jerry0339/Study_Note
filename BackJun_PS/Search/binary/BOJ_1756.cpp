#include<bits/stdc++.h>
using namespace std;

int D,N;
int dv[300010]{}, nv[300010]{};
int m[300010]{};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>D>>N; // depth, 반죽 개수

    for(int i=1; i<=D; i++) cin>>dv[i];
    for(int i=1; i<=N; i++) cin>>nv[i];
    m[1] = dv[1];
    for(int i=2; i<=D; i++) {
        m[i] = min(m[i-1], dv[i]);
    }

    int l=1,r=D,mid;
    for(int i=1; i<=N; i++) {
        l=1;
        while(l<=r){
            mid = (l+r)/2;
            if(nv[i] <= m[mid]) l = mid+1;
            else r = mid-1;
        }
        if(r==0) {cout<<r; return 0;}
        r--;
    }
    cout<<r+1;
}