#include<bits/stdc++.h>
using namespace std;

string str1 = "";
string str2 = "";

vector<int> getPI(string p) {
    int M=p.size();
    vector<int> fail(M,0);
    for(int i=1, j=0; i<M; i++) {
        while(j>0 && p[i]!=p[j]) j = fail[j-1];
        if(p[i] == p[j]) fail[i] = ++j;
    }
    return fail;
}

bool KMP(string s, string p) { 
    int N=s.size(), M=p.size();
    vector<int> ret, fail=getPI(p);
    for(int i=0, j=0; i<N; i++) {
        while(j>0 && s[i]!=p[j]) j = fail[j-1];
        if(s[i] == p[j]) {
            if(j == M-1) return true;
            else ++j;
        } 
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i=0; i<360000; i++) {
        str1 += '0';
        str2 += '0';
    }
    int N, t;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>t;
        str1[t] = '1';
    }
    for(int i=0; i<N; i++){
        cin>>t;
        str2[t] = '1';
    }
    
    if(KMP(str1+str1, str2)) cout<<"possible";
    else cout<<"impossible";
}