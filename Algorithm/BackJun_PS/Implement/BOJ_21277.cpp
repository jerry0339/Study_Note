#include<bits/stdc++.h>
using namespace std;

int N,M;
int tN,tM;
int m[150][150]{};
int sub[50][50]{};

bool chkOverlap(int y, int x){ // 겹치면 1반환
    for(int i=0; i<tN; i++){
        for(int j=0; j<tM; j++){
            if(sub[i][j] && m[i+y][j+x])
                return true;
        }
    }
    return false;
}

int comp(){
    int minArea = 1e9;
    for(int i=0; i<150-tN; i++){
        for(int j=0; j<150-tM; j++){
            if(chkOverlap(i,j)) continue;
            int miny = min({i, i+tN, 50, 50+N});
            int minx = min({j, j+tM, 50, 50+M});
            int maxy = max({i, i+tN, 50, 50+N});
            int maxx = max({j, j+tM, 50, 50+M});
            int sum = (maxy-miny) * (maxx-minx);
            minArea = min(minArea, sum);
        }
    }
    return minArea;
}

void rotate(){
    int t[tM][tN]{};
    for(int j=0, ii=0; j<tM; j++, ii++){
        for(int i=tN-1, jj=0; i>=0; i--, jj++){
            t[ii][jj] = sub[i][j];
        }
    }
    swap(tN, tM);
    for(int i=0; i<tN; i++){
        for(int j=0; j<tM; j++){
            sub[i][j] = t[i][j];
        }
    }
}

void printsub(){
    for(int i=0; i<tN; i++){
        for(int j=0; j<tM; j++){
            cout<<sub[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string str;
    cin>>N>>M;
    for(int i=50; i<50+N; i++){
        cin>>str;
        for(int j=50; j<50+M; j++){
            m[i][j] = str[j-50] - '0';
        }
    }

    cin>>tN>>tM;
    for(int i=0; i<tN; i++){
        cin>>str;
        for(int j=0; j<tM; j++){
            sub[i][j] = str[j] - '0';
        }
    }
    
    int ans = 1e9;
    ans = min(ans, comp());
    rotate();
    ans = min(ans, comp());
    rotate();
    ans = min(ans, comp());
    rotate();
    ans = min(ans, comp());
    cout<<ans;
}