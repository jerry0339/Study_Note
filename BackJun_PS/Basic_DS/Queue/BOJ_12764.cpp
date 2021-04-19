#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;

struct comp{
    bool operator()(piii &a, piii &b){
        return a.xx.yy > b.xx.yy;
    }
};

int N;
pii m[100001]{};
int seat[100001]{};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0; i<N; i++) cin>>m[i].xx>>m[i].yy;
    sort(m, m+N);

    int idx = 0;
    priority_queue<piii,vector<piii>,comp> pq;
    priority_queue<int,vector<int>,greater<int>> rm;
    for(int i=0; i<N; i++){
        while(!pq.empty()){
            int preEnd = pq.top().xx.yy;
            int preSeat = pq.top().yy;
            if(preEnd < m[i].xx) {
                rm.push(preSeat);
                pq.pop();
            } else break;
        }
        if(rm.empty()){
            pq.push({m[i],idx});
            seat[idx++]++;
        } else {
            pq.push({m[i], rm.top()});
            seat[rm.top()]++;
            rm.pop();
        }
    }

    cout<<idx<<'\n';
    for(int i=0; i<N; i++){
        if(!seat[i]) break;
        cout<<seat[i]<<' ';
    }
}