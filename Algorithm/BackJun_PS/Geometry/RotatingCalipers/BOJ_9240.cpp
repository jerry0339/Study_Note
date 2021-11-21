// 9240 로버트 후드
// https://aruz.tistory.com/entry/rotating-calipers 참고함

#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define sz(x) (int)(x).size()
#define xx first
#define yy second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int N;
vector<pii> v;
vector<pii> hull;

ll cross(pii a, pii b){
    return (ll)a.xx*b.yy - (ll)b.xx*a.yy;
}

int ccw(pii p, pii a, pii b){
    pii aa = {a.xx-p.xx, a.yy-p.yy};
    pii bb = {b.xx-p.xx, b.yy-p.yy};
    ll t = cross(aa,bb);
    return t ? (t>0 ? 1 : -1) : 0;
}

void convexHull(vector<pii> &v){
    if(v.size()<3) return;
    swap(v[0],*min_element(v.begin(), v.end()));  
    sort(++v.begin(), v.end(), [&](pii a, pii b) -> bool {
        int ret = ccw(v[0], a, b);
        return ret > 0  || (ret==0 && a < b);
    });

    hull.emplace_back(v[0]);
    hull.emplace_back(v[1]);
    for(int i=2; i<v.size(); i++){
        while(hull.size()>1 && ccw(v[i], hull[hull.size()-2], hull[hull.size()-1])<=0){
            hull.pop_back();
        }
        hull.emplace_back(v[i]);
    }
}

double getDist(pii a, pii b) {
    pii d = {b.xx-a.xx, b.yy-a.yy};
    return sqrt(d.xx*d.xx + d.yy*d.yy);
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(8);
    cout<<fixed;
	cin>>N;
	int a,b;
	for(int i=0; i<N; i++){
		cin>>a>>b;  
		v.push_back(pii(a,b));
	}
    if(v.size()==2) {
        cout<<getDist(v[0], v[1]);
        return 0;
    }

    convexHull(v);

    int minidx=0, maxidx=0;
    for(int i=1; i<hull.size(); i++){
        pii minpt = hull[minidx];
        pii maxpt = hull[maxidx];
        if(minpt.xx >= hull[i].xx){
            if(minpt.xx==hull[i].xx && minpt.yy > hull[i].yy) continue;
            minidx = i;
        }
        if(maxpt.xx <= hull[i].xx){
            if(maxpt.xx==hull[i].xx && maxpt.yy < hull[i].yy) continue;
            maxidx = i;
        }
    }
    
    double res = 0;
    int r=minidx, l=maxidx, n=hull.size();
    while(r!=maxidx || l!=minidx){
        res = max(res, getDist(hull[l], hull[r]));
        pii a = hull[l];
        pii b = hull[(l+1)%n];
        pii c = hull[r];
        pii d = hull[(r+1)%n];
        pii x = {b.xx-a.xx, b.yy-a.yy};
        pii y = {c.xx-d.xx, c.yy-d.yy};
        if (cross(x, y) > 0) {
            l = (l + 1)%n;
        } else {
            r = (r + 1)%n;
        }
    }

    cout<<res;
}