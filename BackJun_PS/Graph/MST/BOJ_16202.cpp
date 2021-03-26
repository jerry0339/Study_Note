// BOJ_16202
// MST

#include<bits/stdc++.h>
using namespace std;

struct Edge{
    int c,a,b;
    Edge(int c_=0, int a_=0, int b_=0) :c(c_), a(a_), b(b_){}
};

bool comp(Edge &x, Edge &y){
    return x.c < y.c;
}

int N,M,C;
int parent[1001]{};
vector<Edge> ed;

int find(int a){
	if(parent[a]<0) return a;
	return parent[a] = find(parent[a]);
}
int find2(int k) {
    if (k == parent[k]) return k;
    else return parent[k] = find(parent[k]);
}

void merge(int a, int b){
	a = find(a);
    b = find(b);
	if(a==b) return;
	if(parent[a] < parent[b]) swap(a,b);
	parent[b] += parent[a];
	parent[a] = b;
}
void merge2(int a, int b) {
    a = find(a);
    b = find(b);
    parent[a] = b;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M>>C;
    int a,b,c;
    for(int i=0; i<M; i++){
        cin>>a>>b;
        ed.emplace_back(Edge(i+1,a,b));
    }
    sort(ed.begin(), ed.end(), comp);

    bool chk = false;
    for(int k=0; k<C; k++){
        if(chk) {cout<<0<<' '; continue;}
        memset(parent, -1, sizeof(parent));
        int tmp = 0, sum = 0;
        for(int i=k; i<M; i++){
            int x = ed[i].a;
            int y = ed[i].b;
            if(tmp==N-1) break;
            if(find(x)==find(y)) continue;
            merge(x, y);
            sum += ed[i].c;
            tmp++;
        }

        if(tmp==N-1) cout<<sum<<' ';
        else {
            cout<<0<<' ';
            chk = true;
        }

    }

}