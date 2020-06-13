// n과m 시리즈의 dfs코드

#include<bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
int const SIZE = 8;

int N,M;
vector<int> num;
vector<int> st(SIZE);
bool vi[SIZE]={0,};

void solve(int depth, int cur){
    if(depth == M) {
        for(int i=0; i<M; i++){
            cout<<st[i]<<' ';
        } cout<<'\n';
        return;
    }
    int before = -1; // check repeated value
    //if num[i] can be before, add condition(if(i==0){....})
    for(int i=cur+1; i<N; i++){ // combination index
        if(before==num[i]) continue;
        //if(vi[i]) continue;
        //vi[i] = true;
        before = num[i]; 
        st[depth]=num[i];
        solve(depth+1, i);
        //vi[i] = false; // backtracking
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    num.resize(N);
    for(int i=0; i<N; i++){
        cin>>num[i];
    }
    sort(all(num));
    solve(0,-1);
}