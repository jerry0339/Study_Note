// 톱니바퀴 - 14891
#include<bits/stdc++.h>
using namespace std;

int N,M;
int m[4][8]{};
int now[4]{};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string str;
    for(int i=0; i<4; i++){
        cin>>str;
        for(int j=0; j<8; j++) 
            m[i][j] = str[j]-'0';
    }

    cin>>M;
    int a,b;
    for(int i=0; i<M; i++){
        cin>>a>>b; a--;

        int l=a, r=a;
        for(int j=a-1; j>=0; j--){
            if(m[j][(now[j]+2)%8] ^ m[j+1][(now[j+1]+6)%8]) l--;
            else break;
        }
        for(int j=a+1; j<4; j++){
            if(m[j][(now[j]+6)%8] ^ m[j-1][(now[j-1]+2)%8]) r++;
            else break;
        }
        
        if((a-l)%2 == 0) b *= -1;
        for(int k=l; k<=r; k++){
            now[k] = (now[k]+8+b)%8;
            b *= -1;
        }
    }

    int res = 0, power = 1;
    for(int i=0; i<4; i++){
        res += (m[i][now[i]] * power);
        power*=2;
    }
    cout<<res;
}
