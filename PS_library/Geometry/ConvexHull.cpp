// <볼록 껍질> - BOJ_1708
// ConvexHull : Graham Scan

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

pii mpt;
bool comp(const pii &a, const pii &b){
    int ret = ccw(mpt, a, b);
    return ret > 0  || (ret==0 && a < b);
}

void convexHull(vector<pii> &v){
    if(v.size()<3) return;
    swap(v[0],*min_element(v.begin(), v.end()));  
    sort(++v.begin(), v.end(), [&](pii a, pii b) -> bool {
        int ret = ccw(v[0], a, b);
        return ret > 0  || (ret==0 && a < b);
    });

    vector<pii> hull;
    hull.emplace_back(v[0]);
    hull.emplace_back(v[1]);
    for(int i=2; i<v.size(); i++){
        while(hull.size()>1 && ccw(v[i], hull[hull.size()-2], hull[hull.size()-1])<=0){
            hull.pop_back();
        }
        hull.emplace_back(v[i]);
    }
    v = hull;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cin>>N;
	int a,b;
	for(int i=0; i<N; i++){
		cin>>a>>b;  
		v.eb(pii(a,b));
	}
    
    convexHull(v);
    cout<<v.size();
}