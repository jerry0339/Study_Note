// <감옥 건설> - BOJ_2254
// ConvexHull, 방문처리를 이용한 볼록껍질 제거(양파껍질까기...ㅋ)

#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define sz(x) (int)(x).size()
#define eb emplace_back
#define xx first
#define yy second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int N,px,py;
vector<pii> v;
vector<pii> tmp;

int ccw(pii p, pii a, pii b) {
    ll t = (ll)(a.xx - p.xx) * (b.yy - p.yy) - (ll)(b.xx - p.xx) * (a.yy - p.yy);
    return t ? (t > 0 ? 1 : -1) : 0;
}

pii mpt;
bool comp(const pii& a, const pii& b) {
    int ret = ccw(mpt, a, b);
    return ret > 0 || (ret == 0 && a < b);
}

bool convexHull() {
    mpt = *min_element(all(v));
    sort(all(v), comp);

    vector<piii> hull; // 방문처리 하기위해, 남아있는 점들의 배열(v)에서의 인덱스를 같이 저장
    bool vi[1510]{};
    hull.eb(piii(0, v[0]));
    hull.eb(piii(1, v[1]));
    vi[0] = true;
    vi[1] = true;
    for (int i = 2; i < sz(v); i++) {
        while (sz(hull) > 1 && ccw(v[i], hull[sz(hull) - 2].yy, hull[sz(hull) - 1].yy) <= 0) {
            vi[hull.back().xx] = false; // 저장된 인덱스로 백트레킹
            hull.pop_back();
        }
        hull.eb(piii(i, v[i]));
        vi[i] = true;
    }

    // v배열에서 껍질(hull배열)에 포함된 점들을 제외
    tmp.clear();
    for (int i = 0; i < sz(v); i++) {
        if (vi[i]) {
            // 감옥위치가 다음 hull밖이라면 감옥위치(px,py)가 hull에 포함되므로 담의 개수 count끝냄
            if(v[i].xx==px && v[i].yy==py) return false;
            continue;
        }
        tmp.eb(v[i]);
    }
    v.clear();
    v = tmp;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> px >> py;
    v.eb(pii(px,py));
    
    int a, b;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        v.eb(pii(a, b));
    }

    int ans = 0;
    while (sz(v)>3) {
        if(convexHull()) ans++;
        else break;
    }
    cout << ans;
}