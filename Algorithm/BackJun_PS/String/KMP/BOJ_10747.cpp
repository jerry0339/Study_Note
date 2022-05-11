// https://www.acmicpc.net/problem/10747
// 특정 문자열 계속 지워서 생기는 문자열 출력하기
// ex) whatthemomooofun - moo = whatthefun

#include<bits/stdc++.h>
using namespace std;

vector<int> getPI(string p) {
    int M=p.size();
    vector<int> fail(M,0);
    for(int i=1, j=0; i<M; i++) {
        while(j>0 && p[i]!=p[j]) j = fail[j-1];
        if(p[i] == p[j]) fail[i] = ++j;
    }
    return fail;
}

vector<char> KMP(string s, string p) {
    int N=s.size(), M=p.size();
    vector<char> ret;
    vector<int> fail=getPI(p);
    vector<int> kmpi(N);
    for(int i=0, j=0; i<N; i++) {
        ret.push_back(s[i]);
        while(j>0 && s[i]!=p[j]) j = fail[j-1];
        if(s[i] == p[j]) {
            if(j == M-1) {
                int tM = M;
                while(tM--) ret.pop_back();
                j = kmpi[ret.size()];
            } else ++j;
        }
        kmpi[ret.size()] = j;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string str1, str2;
    getline(cin,str1);
    getline(cin,str2);
    
    auto v = KMP(str1, str2);
    for(int i=0; i<v.size(); i++) cout<<v[i];
}