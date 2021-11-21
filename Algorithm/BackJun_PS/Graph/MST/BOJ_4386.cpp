#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;

int N;
vector<pdd> m;
vector<pair<double, pii>> dis;
int parent[101]{};

int find(int k) {
    if (k == parent[k]) return k;
    else return parent[k] = find(parent[k]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    parent[a] = b;
}

double calDist(pdd a, pdd b){
    double x = a.xx - b.xx;
    double y = a.yy - b.yy;
    return sqrt(x*x + y*y);
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cin>>N;
    for(int i=0; i<=N; i++) parent[i] = i;
    
    double a,b;
    for(int i=0; i<N; i++){
        cin>>a>>b;
        m.push_back({a,b});
    }
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            dis.push_back({calDist(m[i],m[j]),{i,j}});
        }
    }
    sort(dis.begin(), dis.end());

    int tmp = 0;
    double ans = 0;
    for(auto val : dis){
        int a = val.yy.xx;
        int b = val.yy.yy;
        if(find(a)==find(b)) continue;
        ans += val.xx;
        merge(a,b);
        if(++tmp==N-1) break;
    }

    cout.precision(2);
    cout<<fixed;
    cout<<ans;
}

