// <쿼드트리> - BOJ_1992
// 분할정복 코드

#include<bits/stdc++.h>
using namespace std;
const int DIV = 2;

int N;
int v[65][65]{}; // 배열
string ans;

void go(int y, int x, int k) {
    bool flag=true; // Check Condition
    for(int i=y; (i<y+k)&&flag; i++)
        for(int j=x; (j<x+k)&&flag; j++)
            if (v[y][x] != v[i][j])
                flag=false; // 하나라도 다른항이 있으면 false

    if (flag) { // Conquer
        ans+=(v[y][x]+'0');
    }
    else { // Divide
        k/=DIV;
        for(int i=0;i<DIV;i++){
            for(int j=0;j<DIV;j++){
                if(i==0 && j==0) ans+='(';
                go(y+i*k,x+j*k,k);
                if(i==1 && j==1) ans+=')';
            }
        }
            
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    string str;
    for(int i=0; i<N; i++){
        cin>>str;
        for(int j=0; j<N; j++){
            v[i][j] = str[j]-'0';
        }
    }

    go(0,0,N);
    cout<<ans;
}


