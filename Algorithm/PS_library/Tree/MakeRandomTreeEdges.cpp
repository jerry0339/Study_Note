#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> getRandomTreeEdges(int N) {
    vector<vector<int>> ret;
    vector<bool> visited(N,0);
    vector<int> arr;
    arr.push_back(0);
    visited[0] = true;
    while(1){
        int now = rand()%N;
        if(visited[now]) continue;
        arr.push_back(now);
        visited[now] = true;
        if(arr.size()==N) break;
    }

    int cn = N-1, Left=0, Right=1;
    while(cn){
        int tn = rand()%cn + 1;
        for(int i=Right; i<Right+tn; i++){
            int par = rand()%(Right-Left) + Left;
            ret.push_back({arr[par],arr[i]});
        }
        cn -= tn;
        Left = Right;
        Right = Right + tn;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    srand(time(NULL));
    int maxN = 100;
    int minN = 2;
    int num = rand()%(maxN-1) + minN;
    vector<vector<int>> retEdges = getRandomTreeEdges(num);
}