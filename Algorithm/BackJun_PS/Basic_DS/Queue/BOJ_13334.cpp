// 13334 철로
// pq

#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
typedef pair<int,int> pii;

int N,D;
vector<pii> v;

bool comp(pii &a, pii &b){
    if(a.yy==b.yy) return a.xx < b.xx;
    return a.yy < b.yy;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    int a,b;
    for(int i=0; i<N; i++){
        cin>>a>>b;
        if(a>b) swap(a,b);
        v.push_back({a,b});
    }
    sort(v.begin(), v.end(), comp);
    cin>>D;

    priority_queue<int, vector<int>, greater<int>> pq;
    int cy = v[0].yy;
    int cx = cy-D;
    int res = 0;
    for(auto val : v){
        int nx = val.xx;
        int ny = val.yy;
        if(ny-nx > D) continue;
        if(ny==cy) {
            pq.push(nx);
            res = max(res, (int)pq.size());
            continue;
        }
        cy = val.yy;
        cx = cy - D;
        pq.push(nx);
        while(!pq.empty()){
            int prex = pq.top();
            if(prex < cx) pq.pop();
            else break;
        }
        res = max(res, (int)pq.size());
    }
    cout<<res;
}