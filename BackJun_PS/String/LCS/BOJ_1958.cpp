// <LCS 3> - BOJ_1958
// LCS

#include<bits/stdc++.h>
using namespace std;

int LCS[102][102][102]{};

int LCSubsequence3D(string &A, string &B, string &C){
    for(int i=1; i<=A.length(); i++) { 
        for(int j=1; j<=B.length(); j++) {
            for(int k=1; k<=C.length(); k++){
                if (A[i-1] == B[j-1] && B[j-1] == C[k-1]) { 
                    LCS[i][j][k] = LCS[i-1][j-1][k-1] + 1;
                } else { 
                    LCS[i][j][k] = max({LCS[i][j-1][k], LCS[i-1][j][k], LCS[i][j][k-1]}); 
                } 
            }
        }
    }
    return LCS[A.length()][B.length()][C.length()];
}


int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(0);
    string a,b,c;
    cin>>a>>b>>c;
    cout<<LCSubsequence3D(a,b,c);
}