// <종이의 개수> - BOJ_1780
// 분할정복
// 재귀 + 인덱스로 접근

#include<bits/stdc++.h>
using namespace std;

int v[2188][2188];
int cnt[2]={0,};

void go(int y, int x, int k) {
    bool flag=true; // 분할한 범위의 값이 모두 같으면 true ,
    for(int i=y;(i<y+k)&&flag;i++)
        for(int j=x;(j<x+k)&&flag;j++)
            if (v[y][x] != v[i][j])
                flag=false; // 한개라도 다르면 false

    if (flag) cnt[++v[y][x]]++; // 모두 같으면 수행,
    else { // 하나라도 다르면 해당범위 n*n으로 또 분할. 밑의 코드는 3x3으로 분할
        k/=3;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                go(y+i*k,x+j*k,k);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k; cin>>n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>v[i][j];

    go(0,0,n);
    cout<<cnt[0]<<'\n'<<cnt[1]<<'\n'<<cnt[2];
}