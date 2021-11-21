// <정사각형> - BOJ_9015
// 기하, stl set이용하는 방법

#include<bits/stdc++.h>
using namespace std;
struct vector2{
    int x,y;
    vector2(int x_=0, int y_=0) :x(x_), y(y_){}
};
vector<vector2> pt;
set<int> s[20001]; // s[x좌표].insert(y좌표) : 인덱싱을 이용해서 (시간절약+데이터분할: 시간복잡도 상수가 큰RB트리의단점 보완)
int T,N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--){
        cin>>N;
        pt.clear();
        for(int i=0; i<20001; i++) s[i].clear();
        for(int i=0; i<N; i++){
            int x,y; cin>>x>>y;
            x+=10000; 
            y+=10000;
            pt.push_back({x,y});
            s[x].insert(y);
        }
        int max_=0;
        for(int i=0; i<N; i++){
            for(int j = i+1; j<N; j++){
                vector2 a=pt[i], b=pt[j], c, d;
                int dx = a.x - b.x;
                int dy = a.y - b.y;
                c = vector2(a.x+dy, a.y-dx);
                d = vector2(b.x+dy, b.y-dx);
                if(c.x<0 || d.x<0 || c.x>20000 || d.x>20000 || c.y<0 || d.y<0 || c.y>20000 || d.y>20000) continue;
                else {
                    if(s[c.x].count(c.y) && s[d.x].count(d.y)){ // set은 find보다 count하는게 더빠를 수 있음
                        max_ = max(max_, dx*dx+dy*dy);
                    }
                }
            }
        }
        cout<<max_<<'\n';
    }

}