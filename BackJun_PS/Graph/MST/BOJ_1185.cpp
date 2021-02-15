#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<string>
#include<memory.h>
#define xx first
#define yy second
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
const int INF = 0x3f3f3f3f;

int N,M;
int nCost[10001]{};
vector<piii> edge;
int parent[10001]{};

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
    cin>>N>>M;
    for(int i=1; i<=N; i++) cin>>nCost[i];
    int a,b,c;
    while(M--){
        cin>>a>>b>>c;
        edge.push_back({nCost[a] + nCost[b] + c*2, {a,b}});
    }
    sort(edge.begin(), edge.end());

    for(int i=1; i<=N; i++) parent[i] = i;
    int sum=0, cnt=0;
    for(auto v : edge){
        if(cnt==N-1) break;
        int d = v.xx;
        int x = v.yy.xx;
        int y = v.yy.yy;
        if(find(x) == find(y)) continue;
        sum += d;
        cnt++;
        merge(x,y);
    }

    nCost[0] = INF;
    cout<<sum + *min_element(nCost, nCost+N);
}