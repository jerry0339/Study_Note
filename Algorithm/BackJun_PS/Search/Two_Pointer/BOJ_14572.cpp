#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
using pii = pair<int,int>;

int N,K,D;
vector<pii> v;
vector<int> adj[100001]{};
int algo[31]{};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K>>D;

    int M,a,b;
    v.push_back({-1,0});
    for(int i=1; i<=N; i++){
        cin>>M>>a;
        v.push_back({a,i});
        while(M--) {
            cin>>b;
            adj[i].push_back(b);
        }
    }
    sort(v.begin(), v.end());

    int st=1, ed=1, E=0;
    for(auto val : adj[v[st].yy]) algo[val]++;
    while(1){
        if(v[ed].xx - v[st].xx <= D) {
            int x=0, y=0, e=0;
            for(int i=1; i<=K; i++){
                if(algo[i]==0) continue;
                if(algo[i]==(ed-st+1)) y++;
                x++;
            }
            e = (x-y) * (ed-st+1);
            E = max(E,e);
            
            ed++;
            if(ed > N) break;
            for(auto val : adj[v[ed].yy]) algo[val]++;
        }
        else {
            for(auto val : adj[v[st].yy]) algo[val]--;
            st++;
        }
    }
    cout<<E;
}