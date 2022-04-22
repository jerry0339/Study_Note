#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int N,L,R,X;
int m[15]{};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>L>>R>>X;
    for(int i=0; i<N; i++) cin>>m[i];

    int ans = 0;
    for(int mask=0; mask<(1<<N); mask++){
        int sum=0, l=INF, r=0;
        for(int i=0; i<N; i++){
            if(!(mask&(1<<i))) continue;
            sum += m[i];
            l = min(l, m[i]);
            r = max(r, m[i]);
        }
        if(sum>=L && sum<=R && (r-l)>=X) ans++;
    }
    cout<<ans;
}