#include<bits/stdc++.h>
using namespace std;

int G,P;
int parent[100001]{};

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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>G>>P;
    for(int i=1; i<=G; i++) parent[i] = i;
    
    int g, ans = 0;
    while(P--){
        cin>>g;
        int par = find(g);
        if (par != 0) {
            merge(par, par - 1);
            ans++;
        } 
        else break;
    }
    cout<<ans;
}