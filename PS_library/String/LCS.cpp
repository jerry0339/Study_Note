// <LCS>
// 1. Longest Common Substring
// 2. Longest Common Subsequence
#include<bits/stdc++.h>
using namespace std;

int LCS[1010][1010]{};

// ex) AXBXCXY, ABCXY -> CXY
int LCSubstring(string &A, string &B){
    int ans = 0;
    for (int i=1; i <= A.length(); i++) {
        for (int j=1; j <= B.length(); j++) {
            if (A[i-1] == B[j-1]) { 
                LCS[i][j] = LCS[i-1][j-1] + 1; 
                if (ans < LCS[i][j]) { 
                    ans = LCS[i][j]; 
                }
            } 
        }
    }
}

// ex) AXBXCXY, ABCXY -> ABCXY
int LCSubsequence(string &A, string &B){
    for(int i=1; i<=A.length(); i++) { 
        for(int j=1; j<=B.length(); j++) { 
            // LCS배열은 인덱스가1부터, string A,B는 인덱스가 0부터 시작하므로
            // A에는 i-1, B에는 j-1이 인덱싱되고 LCS[i][j]로 인덱싱 됨
            if (A[i-1] == B[j-1]) {
                LCS[i][j] = LCS[i-1][j-1] + 1;
            } else { 
                LCS[i][j] = max(LCS[i][j-1], LCS[i-1][j]); 
            } 
        }
    }
    return LCS[A.length()][B.length()];
}

// LCS 문자열 추적
// https://mygumi.tistory.com/126 참고
string printLCSubseq(string &A, string &B){
    int LCSLength = LCSubsequence(A,B);
    int i=A.length(), j=B.length();
    string ans;
    while(LCS[i][j]){
        if(LCS[i][j-1]<LCS[i][j] && LCS[i-1][j]<LCS[i][j]){
            ans+=A[i-1];
            i--; j--;
        } else if(LCS[i][j-1]==LCS[i][j]) {
            j--;
        } else if(LCS[i-1][j]==LCS[i][j]){
            i--;
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(0);
    string a,b;
    cin>>a>>b;
    string ans = printLCSubseq(a,b);
    cout<<ans.size()<<'\n'<<ans;
}