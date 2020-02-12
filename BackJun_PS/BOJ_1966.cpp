// <프린터 큐> - 1966
// 시뮬레이션, Pair클래스 이용, list클래스로 queue 구현
// 우선순위가 높은 순서대로 출력하기 위해 입력된 우선순위를 따로저장, 정렬하여 차례대로 큐에서 검색.
#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<n; i++)
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int C; cin >> C;

    while (C--) {
        int N, M, cnt = 0;
        cin >> N >> M;
        list<pair<int, int>> lst; // index, importance
        vector<int> imp;
        rep(i, 0, N) {
            pair<int, int> temp;
            temp.first = i;
            cin >> temp.second;
            lst.push_back(temp);
            imp.push_back(temp.second);
        }
        sort(imp.begin(),imp.end(),greater<int>());

        rep(i,0,N){
            while(1){
                if(imp[i]==lst.begin()->second){
                    cnt++;
                    if(lst.begin()->first == M) goto exit;
                    lst.pop_front();
                    break;
                }
                lst.push_back(lst.front());
                lst.pop_front();
            }
        }
        
        exit:
        cout << cnt << "\n";
    }
}