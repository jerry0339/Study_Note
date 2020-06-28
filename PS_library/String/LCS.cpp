// <LCS>
// 1. Longest Common Substring
// 2. Longest Common Subsequence
#include<bits/stdc++.h>
using namespace std;

int LCS[100][100]={0,};

int LCSubstring(string &A, string &B){
    int ans = 0;
    for (int i = 1; i <= A.length(); i++) { 
        for (int j = 1; j <= B.length(); j++) { 
            if (A[i - 1] == B[j - 1]) { 
                LCS[i][j] = LCS[i - 1][j - 1] + 1; 
                if (ans < LCS[i][j]) { 
                    ans = LCS[i][j]; 
                }
            } 
        }
    }
}

int LCSubsequence(string &A, string &B){
    for(int i=1;i<=A.length(); i++) { 
        for(int j=1;j<=B.length(); j++) { 
            if (A[i-1] == B[j-1]) { 
                LCS[i][j] = LCS[i-1][j-1] + 1; 
            } else { 
                LCS[i][j] = max(LCS[i][j-1], LCS[i-1][j]); 
            } 
        } 
    }
}
