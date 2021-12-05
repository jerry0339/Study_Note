#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
const int INF = 0x3f3f3f3f;

int N;
int m[20][20]{};
vector<int> stk;
int minDiff = INF;
bool vi[20]{};

int calScore() {
    vector<int> t1, t2;
    for(int i=0; i<N; i++){
        if(vi[i]) t1.push_back(i);
        else t2.push_back(i);
    }

    int t1sum = 0;
    for(int i=0; i<t1.size(); i++){
        for(int j=i+1; j<t1.size(); j++){
            int a = t1[i], b = t1[j];
            t1sum += (m[a][b] + m[b][a]);
        }
    }

    int t2sum = 0;
    for(int i=0; i<t2.size(); i++){
        for(int j=i+1; j<t2.size(); j++){
            int a = t2[i], b = t2[j];
            t2sum += (m[a][b] + m[b][a]);
        }
    }

    return abs(t1sum - t2sum);
}

void dfs(int dpt, int cp) {
    if(dpt == N/2) {
        int diffScore = calScore();
        minDiff = min(minDiff, diffScore);
        return;
    }

    for(int i=cp+1; i<N; i++){
        vi[i] = true;
        dfs(dpt+1, i);
        vi[i] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>m[i][j];
        }
    }

    dfs(0, -1);
    
    cout<<minDiff;
}