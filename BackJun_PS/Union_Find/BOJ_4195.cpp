#include<bits/stdc++.h>
using namespace std;

int N,M,T;
int parent[200001]{}, setSize[200001]{};

int find(int k) {
    if (k == parent[k]) return k;
    else return parent[k] = find(parent[k]);
}

int merge(int a, int b) {
    a = find(a);
    b = find(b);
    if(a==b) return setSize[a];
    if(setSize[a] > setSize[b]) swap(a,b);
    parent[a] = b;
    setSize[b] += setSize[a];
    return setSize[b];
}

map<string,int> m;

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cin>>T;
    

    while(T--){
        cin>>N;
        m.clear();
        for(int i=0; i<=N*2; i++) {
            parent[i] = i;
            setSize[i] = 1;
        }

        int idx = 0;
        string a,b;

        while(N--){
            cin>>a>>b;
            if(m.count(a)==0) m[a] = idx++;
            if(m.count(b)==0) m[b] = idx++;
            int x = m[a], y = m[b];
            
            cout<<merge(x, y)<<'\n';
        }
    }

}

