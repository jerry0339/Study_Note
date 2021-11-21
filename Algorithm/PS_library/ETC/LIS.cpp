// <가장 긴 증가하는 부분 수열 5> - BOJ_14003
// LIS(Longest Increase Subsequence) : 이분탐색 이용 O(NlogN)
// 최대값에 -INF 넣는거 확인
// LIS길이가 아닌 sequence를 직접 구해야 함
// -> LIS 역추적 이용, 참고 : https://www.crocus.co.kr/681

#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int N;
int m[1000010]{};
int trace[1000010]{}; // 역추적을 위한 배열
vector<int> lis;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0; i<N; i++) cin>>m[i];

    lis.push_back(-INF);
    for (int i = 0; i < N; i++) { // N이 m의 size인지 체크
        if (lis.back() < m[i]) {
            trace[i] = lis.size();
            lis.push_back(m[i]);
        }
        else {
            int idx = lower_bound(lis.begin(), lis.end(), m[i]) - lis.begin();
            trace[i] = idx;
            lis[idx] = m[i];
        }
    }

    int length = lis.size()-1;
    cout<<length<<'\n';
    
    vector<int> ans;
    for(int i=N-1; i>=0; i--){ // 자세한건 위의 주소 참고
        if(trace[i] == length) {
            ans.push_back(i);
            length--;
            if(length < 1) break;
        }
    }

    for(int i=ans.size()-1; i>=0; i--) cout<<m[ans[i]]<<' ';
}

// 역추적 없는 버전
/*
#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int N;
int m[1000010]{};
vector<int> lis;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0; i<N; i++) cin>>m[i];

    lis.push_back(-INF);
    for (int i = 0; i < N; i++) { // N이 m의 size인지 체크
        if (lis.back() < m[i]) lis.push_back(m[i]);
        else *lower_bound(lis.begin(), lis.end(), m[i]) = m[i];
    }

    cout<<lis.size()-1;
}
*/