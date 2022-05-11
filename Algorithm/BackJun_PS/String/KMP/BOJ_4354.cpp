#include<bits/stdc++.h>
using namespace std;

vector<int> getPI(string p) {
    int M=p.size(), j=0;
    vector<int> fail(M,0);
    for(int i=1; i<M; i++) {
        while(j>0 && p[i]!=p[j]) j = fail[j-1];
        if(p[i] == p[j]) fail[i] = ++j;
    }
    return fail;
}

int KMP(string s, string p) { 
    int N=s.size(), M=p.size(), ret=0;
    vector<int> fail=getPI(p);
    for(int i=0, j=0; i<N; i++) {
        while(j>0 && s[i]!=p[j]) j = fail[j-1];
        if(s[i] == p[j]) {
            if(j == M-1) {
                ret++;
                j = fail[j];
            } else j++;
        } 
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string str;
    while(true){
        getline(cin,str);
        if(str==".") break;
        string str2 = str+str;
        cout<<KMP(str2,str)-1<<'\n';
    }
}