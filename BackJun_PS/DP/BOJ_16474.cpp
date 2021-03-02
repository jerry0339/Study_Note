#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int aa[2002]{}, bb[2002]{}, dp[2002][2002]{};
int can[2002][2002]{};

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	cin>>N>>M;
    
    int t;
	for (int i=1; i<=N; i++) {
		cin>>t;
		aa[t] = i;
	}
	for (int i=1; i<=M; i++) {
		cin>>t;
		bb[t] = i;
	}
	
    cin>>K;
	for (int i = 0; i < K; i++) {
		int x, y;
		cin>>x>>y;
		can[aa[x]][bb[y]] = 1;
	}

    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            dp[i][j] = max({dp[i][j-1], dp[i-1][j], dp[i-1][j-1] + can[i][j]});
        }
    }

	cout<<K-dp[N][M];
}