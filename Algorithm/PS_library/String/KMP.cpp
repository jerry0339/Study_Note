// https://www.acmicpc.net/problem/1786
// KMP 알고리즘
// O(M+N) : M -> 문자열s길이, N -> 문자열p길이

#include<bits/stdc++.h>
using namespace std;

vector<int> getPI(string p) {
    int m=p.size(), j=0;
    vector<int> fail(m,0);
    //p와 p끼리 KMP를 수행
    for(int i=1; i<m; i++) {
        while(j>0 && p[i]!=p[j]) j = fail[j-1];
        if(p[i] == p[j]) fail[i] = ++j;
    }
    return fail;
}

//문자열s 중에 문자열p가 등장하는 시작 인덱스들이 담긴 벡터를 리턴
vector<int> KMP(string s, string p) { 
    vector<int> ret, fail=getPI(p);
    int n=s.size(), m=p.size(), j=0;
    for(int i=0 ; i<n; i++) {
        while(j>0 && s[i]!=p[j]) j = fail[j-1]; // 매칭 중 불일치 발생, 이전의 매칭됐던 문자열 적용
        if(s[i] == p[j]) { // 한 글자 매칭 성공한 경우
            if(j == m-1) { // 완전 매칭 성공한 경우
                ret.push_back(i-m+1);
                j = fail[j];
            } else j++;
        } 
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
    cout<<v.size()<<'\n';
    for(int i=0; i<v.size(); i++) {
        cout<<v[i]+1<<' ';
    }
}