// <직사각형> - BOJ_1945
// Line Sweeping, ccw, sort
// 2D Point ccw로 정렬((0,0)기준) : 즉, (0,0)을 지나는 직선이 움직일때 먼저 닿는 순으로 정렬가능

#include<bits/stdc++.h>
using namespace std;

struct pt{int x, y, w;};

int ccw(pt a, pt b){ // (0,0), a, b 를 ccw한 결과 반환
    long long t = 1ll * a.x * b.y - 1ll * b.x * a.y;
    if(t > 0) return 1;
    if(t < 0) return -1;
    return 0;
}

bool cmp(pt a, pt b){
    return ccw(a,b) > 0;
}

vector<pt> v;
int N;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0; i<N; i++) {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        v.push_back({min(a,c),max(b,d),-1});
        v.push_back({max(a,c),min(b,d),1});
    }
    sort(v.begin(),v.end(),cmp);

    int cur=0, max_=0;
    for(int i=0; i<v.size(); i++){
        cur += v[i].w;
        max_ = max(max_, cur);
    }
    cout<<max_<<'\n';
}