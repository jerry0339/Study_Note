// 1786문제 코드임, https://www.acmicpc.net/problem/1786
// KMP 알고리즘
// O(M+N) : M -> 문자열s길이, N -> 문자열p길이

#include<bits/stdc++.h>
using namespace std;

// N,M이 선언되어 있음에 주의!!!!
vector<int> getPI(string p) {
    int M=p.size();
    vector<int> fail(M,0);
    //p와 p의 부분문자열을 reverse한 문자열 p`와 KMP를 수행(실제로 reverse한건 아님!)
    for(int i=1, j=0; i<M; i++) {
        while(j>0 && p[i]!=p[j]) j = fail[j-1]; // 이전 실패함수 이용
        if(p[i] == p[j]) fail[i] = ++j; // 실패함수 생성
    }
    return fail;
}

//문자열s 중에 문자열p가 등장하는 시작 인덱스들이 담긴 벡터를 리턴
vector<int> KMP(string s, string p) { 
    int N=s.size(), M=p.size();
    vector<int> ret, fail=getPI(p);
    for(int i=0, j=0; i<N; i++) {
        while(j>0 && s[i]!=p[j]) j = fail[j-1]; // 매칭 중 불일치 발생, 이전의 매칭됐던 문자열 찾기(실패함수 이용)
        if(s[i] == p[j]) {
            if(j == M-1) { // 문자열p와 완전히 매칭한 경우
                ret.push_back(i-M+1);
                j = fail[j];
            } else ++j; // 문자열p의 j번째까지 일치한 경우 j++
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