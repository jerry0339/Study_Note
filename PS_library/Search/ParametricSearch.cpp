#include<bits/stdc++.h>
using namespace std;
int N;
// 답을 정해놓고 그 답이 가능한지 이진탐색하는 종류의 문제들을 Parametric Search 라고함
// 비재귀 버전
bool ispossible(int mid){ // int or bool확인
    int cnt = 0;
    // cnt계산 예시)
    // for (int i = 0; i < M; i++) // N or M 확인!!!!
    //    cnt += (c[i] - 1) / mid + 1;
    
    // cnt값(조건)을 만족하는 mid가 여러개 일때,
    // max인 mid탐색 : ex) BOJ_1654<랜선자르기>
    if(cnt >= N) return true;
    else return false;
    // return cnt>=N; // 한줄 코드

    // min인 mid탐색 : ex) BOJ_2792<보석상자>
    if(cnt > N) return true;
    else return false;
    // return cnt>N; // 한줄 코드
}

int b_search(int l, int r)
{
    int s = l, e = r, mid;
    while (s <= e) {
        mid = (s + e) / 2;
        if (ispossible(mid)) s = mid + 1;
        else                 e = mid - 1;
        
    }
    // iopossible에서 cnt값(조건)을 만족하는 mid가 여러개 일때,
    return e; // -> max mid탐색시
    return s; // -> min mid탐색시
}


/*--------------------------------------------------------------------------------------*/
// 재귀버전 default
vector<pair<int,int>> v(N);
int b_Search(int start, int end, int goal){
    int mid = (start+end)/2;
    if(v[mid].first==goal){
        return v[mid].second;
    } else if(v[mid].first > goal) {
        return b_Search(start,mid,goal);
    } else { // v[mid].first > name
        return b_Search(mid+1,end,goal);
    }
}