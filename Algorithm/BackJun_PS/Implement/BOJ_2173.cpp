#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

struct Info{
    int i,j,a,b,s;
    Info(int i=0, int j=0, int a=0, int b=0, int s=0): i(i), j(j), a(a), b(b), s(s) {}
};

int N,M;
int m[33][33]{};
bool vi[33][33]{};
vector<Info> stk;

int chk(int i, int j, int a, int b){
    int sum = 0;
    for(int x = i; x<=a; x++) {
        if(vi[x][j] || vi[x][b]) return -INF;
        sum += m[x][j];
        sum += m[x][b];
    }
    for(int y = j+1; y<b; y++) {
        if(vi[i][y] || vi[a][y]) return -INF;
        sum += m[i][y];
        sum += m[a][y];
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++){
            cin>>m[i][j];
        }
    }
    
    while(M--){
        int maxsum = -INF, sum = 0;
        int maxi, maxj, maxa, maxb;
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                for(int a=i+2; a<=N; a++){
                    for(int b=j+2; b<=N; b++){
                        sum = chk(i,j,a,b);
                        if(maxsum < sum) {
                            maxsum = sum;
                            maxi = i; maxj = j;
                            maxa = a; maxb = b;
                        }
                        
                    }
                }
            }
        }
        if(maxsum==-INF) {cout<<0; return 0;}
        stk.push_back(Info(maxi, maxj, maxa, maxb, maxsum));
        for(int x = maxi; x<=maxa; x++) {
            vi[x][maxj] = true;
            vi[x][maxb] = true;
        }
        for(int y = maxj+1; y<maxb; y++) {
            vi[maxi][y] = true;
            vi[maxa][y] = true;
        }
    }

    for(auto val : stk){
        cout<<val.s<<' '<<val.i<<' '<<val.j<<' '<<val.a<<' '<<val.b<<'\n';
    }
}