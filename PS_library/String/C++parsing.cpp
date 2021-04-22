// 문자열 파싱

https://programmers.co.kr/learn/courses/30/lessons/17676#

#include<bits/stdc++.h>

using namespace std;

int solution(vector<string> lines) {
    vector<pair<int,int>> times;
    for(auto &line: lines){
        char buf[25];
        line.pop_back();
        int h,m,s,d; // d: duration
        double _s,_d;
        sscanf(line.c_str(), "%s %d:%d:%lf %lf", buf,&h,&m,&_s,&_d);
        h *= 3600000;
        m *= 60000;
        s = _s*1000.0;
        d = _d*1000.0;
        // s = (int)(_s*1000.0 + 0.5); // 컴파일러에 따라 오차가 다를 수 있으므로
        // d = (int)(_d*1000.0 + 0.5);
        int ed = h + m + s;
        int st = ed - d + 1;
        times.emplace_back(st, 1);
        times.emplace_back(ed, -1);
    }
    sort(times.begin(), times.end());
    
    int ans = 0, cnt = 0, n = times.size();
    for(int i=0, r=-1; i<n; i++){
        while(r+1 < n && times[r+1].first - times[i].first < 1000) 
            cnt += times[++r].second == 1;
        
        ans = max(ans, cnt);
        cnt -= times[i].second == -1;
    }
    return ans;
}