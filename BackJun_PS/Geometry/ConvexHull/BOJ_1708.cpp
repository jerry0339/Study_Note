// <볼록 껍질> - BOJ_1708
// ConvexHull : graham scan

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
pii mpt;
vector<pii> v;

int ccw(pii p, pii a, pii b){
	ll t = (ll)(a.xx-p.xx)*(b.yy-p.yy) - (ll)(b.xx-p.xx)*(a.yy-p.yy);
    return t ? (t>0 ? 1 : -1) : 0;
}

bool comp(const pii &a, const pii &b){
    int ret = ccw(mpt, a, b);
    return ret > 0  || (ret==0 && a < b);
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
    mpt = *min_element(all(v));
    sort(all(v),comp);

    vector<pii> ans;
    ans.eb(v[0]);
    ans.eb(v[1]);
    for(int i=2; i<N; i++){
        while(sz(ans)>1 && ccw(v[i], ans[sz(ans)-2], ans[sz(ans)-1])<=0){
            ans.pop_back();
        }
        ans.eb(v[i]);
    }
    cout<<sz(ans);
}