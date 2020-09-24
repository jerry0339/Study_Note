// 팰린드롬 수 찾기
// 마나커(manacher) 알고리즘

#include<bits/stdc++.h>
using namespace std;

int A[200010]{};
int manacher(string str, int n){
    memset(A,0,sizeof(A));
    // 짝수길이 문자열 체크하기 위함
    string S = "#";
    for(int i=0; i<n; i++){
        S += str[i];
        S += '#';
    }

    // 알고리즘 이해 - (https://www.crocus.co.kr/1075)
    int N = S.size();
    int r = 0, p = 0, ans=0;
    for(int i=0; i<N; i++) {
        if(i <= r) 
            A[i] = min(A[2 * p - i], r - i);
        else 
            A[i] = 0;

        while ((i-A[i]-1 >= 0) && (i+A[i]+1 < N) && (S[i-A[i]-1] == S[i+A[i]+1]))
            A[i]++;
        
        if (r < i+A[i]) {
            r = i+A[i];
            p = i;
        }
        ans = max(ans, A[i]);
    }
    return ans; // 가장 긴 팰린드롬 부분 문자열의 길이 반환
}

/*
<푼문제>
https://www.acmicpc.net/problem/14444
https://www.acmicpc.net/problem/1747

<풀어볼 문제>
https://www.acmicpc.net/problem/2079
*/