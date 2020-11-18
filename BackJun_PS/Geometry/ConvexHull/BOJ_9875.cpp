// <Cow Curling> - BOJ_9875
// Convex_hull, 볼록다각형 내부의 점 판정

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
vector<pii> v1;
vector<pii> v2;

int ccw(pii p, pii a, pii b){
	ll t = (ll)(a.xx-p.xx)*(b.yy-p.yy) - (ll)(b.xx-p.xx)*(a.yy-p.yy);
    return t ? (t>0 ? 1 : -1) : 0;
}

void convexHull(vector<pii> &v, vector<pii> &hull){
    if(v.size()<3) return;
    swap(v[0],*min_element(v.begin(), v.end()));  
    sort(++v.begin(), v.end(), [&](pii a, pii b) -> bool {
        int ret = ccw(v[0], a, b);
        return ret > 0  || (ret==0 && a < b);
    });

    hull.clear();
    hull.emplace_back(v[0]);
    hull.emplace_back(v[1]);
    for(int i=2; i<v.size(); i++){
        while(hull.size()>1 && ccw(v[i], hull[hull.size()-2], hull[hull.size()-1])<=0){
            hull.pop_back();
        }
        hull.emplace_back(v[i]);
    }
}

void pointInConvexPoly(vector<pii> &hull, vector<pii> &pt, vector<pii> &res){
    //hull의 size()가 2개인 경우(=직선인경우) 포함
    int s=hull.size()-1;
    int mid = max_element(hull.begin(), hull.end())-hull.begin();

    vector<pii> lowerHull, upperHull;
    upperHull.emplace_back(hull[0]);
    res.clear();

    for(int i=0; i<=mid; i++) lowerHull.emplace_back(hull[i]);
    for(int i=s; i>=mid; i--) upperHull.emplace_back(hull[i]);
    for(int i=0; i<pt.size(); i++){
        int a = lower_bound(lowerHull.begin(), lowerHull.end(), pt[i])-lowerHull.begin();
        int b = lower_bound(upperHull.begin(), upperHull.end(), pt[i])-upperHull.begin();
        
        if(a==0){
            if(pt[i]!=lowerHull[0]) continue;
        } else if(a==lowerHull.size()) continue;
        else {
            if(ccw(pt[i], lowerHull[a-1], lowerHull[a])<0) continue;
        }
        if(b==0){
            if(pt[i]!=upperHull[0]) continue;
        } else if(b==upperHull.size()) continue;
        else {
            if(ccw(pt[i], upperHull[b], upperHull[b-1])<0) continue;
        }
        
        res.emplace_back(pt[i]);
    }
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cin>>N;
	int a,b;
	for(int i=0; i<N; i++){
		cin>>a>>b;  
		v1.eb(pii(a,b));
	}
    for(int i=0; i<N; i++){
		cin>>a>>b;  
		v2.eb(pii(a,b));
	}
    
    vector<pii> hull1, hull2, ans;
    convexHull(v1,hull1);
    convexHull(v2,hull2);

    pointInConvexPoly(hull1,v2,ans);
    cout<<ans.size()<<' ';
    pointInConvexPoly(hull2,v1,ans);
    cout<<ans.size();
}