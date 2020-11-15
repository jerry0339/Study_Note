// <LCS 2> - BOJ_9252
// LCS

#include<bits/stdc++.h>
using namespace std;

int LCS[1010][1010]{};

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
    return LCS[A.length()][B.length()];
}

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