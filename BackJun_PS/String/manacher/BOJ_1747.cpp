// <소수&팰린드롬> - BOJ_1747
// 문자열, sieve, 마나허(manacher)이용 (manacher없이 그냥 팰린드롬인지 확인해도 됨)

#include<bits/stdc++.h>
using namespace std;
const int MAX = 2000000;

int N;
int sieve[MAX+1];
void find_prime(){
    memset(sieve, -1, sizeof(sieve));
    for(int i=2; i*i<=MAX; ++i)
        if(sieve[i] == -1)
            for(int j=i*i; j<=MAX; j+=i)
                if(sieve[j] == -1)
                    sieve[j] = i;
}

int A[16]{};
bool manacher(string str, int n){
    memset(A,0,sizeof(A));
    string S = "#";
    for(int i=0; i<n; i++){
        S += str[i];
        S += '#';
    }
    int N = S.size();
    int r = 0, p = 0;
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
    }
    if(A[N/2] == N/2) return true;
    else return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    find_prime();
    if(N==1) {cout<<2; return 0;}
    for(int i=N; i<=MAX; i++)
        if(sieve[i]==-1) {
            string str = to_string(i);
            if(manacher(str, str.size())) {cout<<i; return 0;}
        }
}