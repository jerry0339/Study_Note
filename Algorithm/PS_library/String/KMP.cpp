// https://www.acmicpc.net/problem/1786
// KMP : 커누스 모리스 프랫 알고리즘(Knuth-Morris-Pratt algorithm)
// 문자열 m에서 n문자열 검색을 목적으로, 문자열m의 길이:M, 문자열n의 길이:N
// getPi(string m) : 접두, 접미 정보 반환, O(M)
// kmp(string m, string n) : 문자열m에서 문자열n이 존재한지 검색하여 위치한 인덱스들을 반환, O(M+N)

#include<bits/stdc++.h>
using namespace std;

vector<int> getPi(string p){ // O(M) , M = p.size()
    int m = (int)p.size(), j=0;
    vector<int> pi(m, 0);
    for(int i = 1; i< m ; i++){ // i: 부분 문자열(0~i 범위의 문자열)의 마지막 문자 인덱스
        while(j > 0 && p[i] != p[j]) j = pi[j-1]; // 이해하기 어려움 구글링ㄱㄱ
        if(p[i] == p[j]) pi[i] = ++j;
    }
    return pi;
}

vector<int> kmp(string s, string p){ // O(M+N) , M = p.size(), N = s.size()
    vector<int> ans;
    auto pi = getPi(p); // O(M)
    int n = (int)s.size(), m = (int)p.size(), j =0;

    // getPi와 똑같은 원리 : O(N)
    for(int i = 0 ; i < n ; i++){ 
        while(j>0 && s[i] != p[j]) j = pi[j-1];
        if(s[i] == p[j]){
            if(j==m-1){
                ans.push_back(i-m+1);
                j = pi[j];
            } 
            else j++;
        } 
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string str1;
    string str2;
    getline(cin,str1);
    getline(cin,str2);
    
    auto v = kmp(str1, str2);
    cout<<v.size()<<'\n';
    for(int i=0; i<v.size(); i++) {
        cout<<v[i]+1<<' ';
    }
}