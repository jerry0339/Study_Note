// <Building the Moat> - BOJ_6194
// 컨벡스헐

#include <bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
typedef long long ll;
typedef pair<double,double> pdd;
const double EPSILON = 1e-9;

int N;
vector<pdd> v;

int ccw(pdd p, pdd a, pdd b){
	double t = (a.xx-p.xx)*(b.yy-p.yy) - (b.xx-p.xx)*(a.yy-p.yy);
    if (fabs(t) < EPSILON) t =0;
    return t ? (t>0 ? 1 : -1) : 0;
}

void convexHull(vector<pdd> &v){
    if(v.size()<3) return;
    swap(v[0],*min_element(v.begin(), v.end()));  
    sort(++v.begin(), v.end(), [&](pdd a, pdd b) -> bool {
        int ret = ccw(v[0], a, b);
        return ret > 0  || (ret==0 && a < b);
    });

    vector<pdd> hull;
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
	double a,b;
	for(int i=0; i<N; i++){
		cin>>a>>b;  
		v.push_back(pdd(a,b));
	}

    convexHull(v);
    double ans =0;
    for(int i=0; i<v.size(); i++){
        double x = v[(i+1)%v.size()].xx - v[i].xx;
        double y = v[(i+1)%v.size()].yy - v[i].yy;
        ans += sqrt(x*x + y*y);
    }
    
    cout.precision(2);
    cout<<fixed;
    cout<<ans;
}