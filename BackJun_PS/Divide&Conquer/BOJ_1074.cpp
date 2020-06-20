// <Z> BOJ_1074
// 분할정복, 재귀

#include<bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(x) (int)(x).size()
#define aa first
#define bb second
typedef pair<int, int> pii;
typedef long long ll;

int N,r,c;
int cnt=0;

int fastp(int x, int y){
    if(y == 0) return 1;
    if(y&1) return x * fastp(x, y-1);
    auto tmp = fastp(x, y/2);
    return tmp * tmp;
}

void go(int y, int x, int k){
    int ny, nx;
    if(k==1) {
        cout<<cnt;
        exit(0);
    }
    if(y+k/2>r) {ny = y; }
    else {ny = y+k/2; cnt+=(k*k/2);}
    if(x+k/2>c) {nx = x; }
    else {nx = x+k/2; cnt+=(k*k/4);}
    go(ny, nx, k/2);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>r>>c;
    int n = fastp(2,N);
    go(0,0,n);
}