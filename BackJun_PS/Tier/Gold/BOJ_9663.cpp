// <N-Queen> - 9663
// BackTracking

#include<bits/stdc++.h>
using namespace std;

int n,cnt = 0;
vector<int> dpt(1);

bool isPossible(int depth){ // Bounding
    for(int i=1; i<depth; i++){
        // 좌우는 검사할 필요x depth기준을 행으로 정했기 때문
        if(dpt[i] == dpt[depth]) // 상하(열) 확인
            return false;
        if(abs(dpt[i] - dpt[depth]) == abs(i - depth)) // 대각 확인
            return false;
    }
    return true;
}

void backTrack(int depth){ // using dfs
    if(depth > n) {
        cnt++; 
        return;
    }
    for(int i=1; i<=n; i++) {
        dpt.push_back(i);
        if(isPossible(depth)){ // cutting
            backTrack(depth+1);
        }
        dpt.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n; // 1~15

    backTrack(1);
    cout<<cnt;
}