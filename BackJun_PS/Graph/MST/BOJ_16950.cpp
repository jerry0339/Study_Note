#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
using dpi = pair<pair<int,int>, pair<int,int>>;

int N,M,K;
int parent[1001]{};
vector<dpi> edge;
vector<dpi> ecopy;

int find(int k) {
    if (k == parent[k]) return k;
    else return parent[k] = find(parent[k]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    parent[a] = b;
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cin>>N>>M>>K;

    char ch;
    int t,a,b;
    for(int i=0; i<M; i++){
        cin>>ch;
        cin>>a>>b;
        t = ch=='R' ? 0 : 1;
        edge.push_back({{t,i},{a,b}});
    }
    ecopy = edge;
    sort(ecopy.begin(), ecopy.end());

    for(int i=1; i<=N; i++) parent[i] = i;
    int rsum = 0;
    for(auto v : ecopy){
        int d = v.xx.xx;
        int x = v.yy.xx;
        int y = v.yy.yy;
        if(find(x) == find(y)) continue;
        merge(x,y);
        rsum += d;
    }

    for(int i=1; i<=N; i++) parent[i] = i;
    int bsum = 0;
    for(int i=M-1; i>=0; i--){
        int d = ecopy[i].xx.xx;
        int x = ecopy[i].yy.xx;
        int y = ecopy[i].yy.yy;
        if(find(x) == find(y)) continue;
        merge(x,y);
        bsum += d;
    }

    if(rsum <= K && K <= bsum) ;
    else {
        cout<<0<<'\n';
        return 0;
    }

    vector<int> ans;
    for(int i=1; i<=N; i++) parent[i] = i;
    int sum = 0;
    for(int i=M-1; i>=0; i--){
        int d = ecopy[i].xx.xx;
        int k = ecopy[i].xx.yy;
        int x = ecopy[i].yy.xx;
        int y = ecopy[i].yy.yy;
        if(find(x) == find(y)) continue;
        if(d && sum==K) continue;
        ans.push_back(k);
        merge(x,y);
        sum += d;
    }

    sort(ans.begin(), ans.end());
    for(auto i : ans){
        cout<<edge[i].yy.xx<<' '<<edge[i].yy.yy<<'\n';
    }
}