// <Programiranje> - BOJ_15355
// DP

#include<bits/stdc++.h>
using namespace std;

string str;
int q, cnt[50001][26];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>str>>q;
    for(int i=0; i<str.size(); i++){
		cnt[i+1][str[i]-'a'] = 1;
		for(int j=0; j<26; j++)
			cnt[i+1][j] += cnt[i][j];
	}

    while(q--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int i;
        for(i=0; i<26; i++){
            // ex) 4~10 까지의 합 ? : sum(10) - sum(3)과 같은 원리
            if(cnt[b][i] - cnt[a-1][i] != cnt[d][i] - cnt[c-1][i]) { 
                cout<<"NE"<<'\n';
                break;
            }
        }
        if(i==26) cout<<"DA"<<'\n';
    }

    // 메모이제이션 출력
    /*
    cout<<"  ";
    for(char i='a'; i<='z'; i++) cout<<i<<' ';
    cout<<'\n';
    for(int i=0; i<=str.size(); i++){
        cout<<i<<' ';
        for(int j=0; j<26; j++){
            cout<<cnt[i][j]<<' ';
        }
        cout<<'\n';
    }*/

}

/*
abababba
2
3 5 1 3
1 2 7 8

*/