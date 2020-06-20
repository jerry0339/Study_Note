// <합이 0인 네 정수> - BOJ_7453
// Union_find 풀이 - 코드는 아래 설명

#include<bits/stdc++.h>
using namespace std;

vector<int> ABCD[4];
vector<int> AB;
vector<int> CD;
long long cnt=0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,t; cin>>N;
    long long i,j,k,l;
    for(i=0; i<N; i++) {
        for(j=0; j<4; j++){
            cin>>t;
            ABCD[j].push_back(t);
        }
    }

    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            AB.push_back(ABCD[0][i]+ABCD[1][j]);
            CD.push_back(-ABCD[2][i]-ABCD[3][j]);
        }
    }
    sort(AB.begin(),AB.end());
    sort(CD.begin(),CD.end());
    N = AB.size();

    // Union_find 풀이
    // AB벡터의 원소와 CD원소가 같은 쌍의 개수 cnt. AB,CD벡터는 중복값 보유
    for(i=0,j=0; i<N&&j<N; ){
        if(AB[i] < CD[j]){
            i++;
        } else if(AB[i] > CD[j]){
            j++;
        } else{
            for(k=i+1; k<N; k++) {if(AB[i] != AB[k]) break;} // 중복값 계산
			for(l=j+1; l<N; l++) {if(CD[j] != CD[l]) break;} // 중복값 계산
			cnt+=((k-i)*(l-j));
            i=k;
            j=l;
        }
    }
    cout<<cnt;
}