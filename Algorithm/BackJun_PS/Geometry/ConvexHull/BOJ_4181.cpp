// <Convex Hull> - BOJ_4181
// ConvexHull개념, ccw를 이용한 정렬

#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define sz(x) (int)(x).size()
#define eb emplace_back
#define xx first
#define yy second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int N;
vector<pii> v;

int ccw(pii p, pii a, pii b){
	ll t = (ll)(a.xx-p.xx)*(b.yy-p.yy) - (ll)(b.xx-p.xx)*(a.yy-p.yy);
    return t ? (t>0 ? 1 : -1) : 0;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int a,b;
    char c;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>a>>b;
        cin>>c;
        if(c=='Y') v.push_back({a,b});
	}

    // x,y값 가장 작은 점 기준으로 반시계 방향으로 정렬
    swap(v[0],*min_element(v.begin(), v.end()));
    sort(++v.begin(), v.end(), [&](pii a, pii b) -> bool {
        int ret = ccw(v[0], a, b);
        if(ret==0) {
            if(a.yy<=v[0].yy) return a.xx<b.xx;
            else return a>b;
        }
        return ret > 0;
    });

    cout<<v.size()<<'\n';
    for(int i=0; i<v.size(); i++){
        cout<<v[i].xx<<' '<<v[i].yy<<'\n';
    }
}