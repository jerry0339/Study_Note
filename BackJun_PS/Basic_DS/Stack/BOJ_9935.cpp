// greedy

#include<bits/stdc++.h>
using namespace std;

string str;
string bomb;
string stk;
char last;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>str;
    cin>>bomb;
    stk = "";
    last = bomb.back();
    int stksize = 0;
    for(int i=0; i<str.size(); i++){
        stk += "@";
        stk[stksize] = str[i];
        stksize++;
        if(stksize < bomb.size()) continue;
        if(str[i] != last) continue;
        bool chk = true;
        for(int j=0; j<bomb.size(); j++){
            if(stk[stksize-bomb.size()+j] != bomb[j]) {
                chk = false;
                break;
            }
        }
        if(chk) {
            stksize -= bomb.size();
        }
    }
    if(stksize==0) cout<<"FRULA";
    else {
        for(int i=0; i<stksize; i++)
            cout<<stk[i];
    }
}