#include<bits/stdc++.h>
using namespace std;
int N;
// 답을 정해놓고 그 답이 가능한지 이진탐색하는 종류의 문제들을 Parametric Search 라고함
// 비재귀 버전
bool ispossible(int mid){ // int or bool확인
    int cnt = 0;
    // cnt계산 예시)
    // for (int i = 0; i < M; i++) cnt += (c[i] - 1) / mid + 1; // N or M 확인!!!!
    
    // 1. 하나의 mid만 탐색 가능한 경우-> 계산값만 반환
    return cnt;

    // 2. 조건확인(max인 mid탐색) : ex) BOJ_1654<랜선자르기>
    if(cnt >= N) return true; // 큰 mid탐색
    else return false;  // 작은 mid탐색
    // 조건문 없이 간단하게 리턴 (아래코드)
    // return cnt>=N; // N or M 확인!!!

    // 3. 조건확인(min인 mid탐색) : ex) BOJ_2792<보석상자>
    if(cnt > N) return true; // 큰 mid탐색
    else return false; // 작은 mid탐색
    // 조건문 없이 간단하게 리턴 (아래코드)
    // return cnt>N; // N or M 확인!!!
}

int b_search(int l, int r)
{
    int s = l, e = r;
    int mid;
    
    while (s <= e) {
        mid = (s + e) / 2;

        // 1. 조건(ispossible)에 의해 단 하나의 mid만 결정될 수 있는경우 예시
        int tmp = ispossible(mid);
        if (tmp==N) return mid;
        else if(tmp<N) s = mid + 1;
        else           e = mid - 1;

        // 2. ispossible로 mid가 여러가지 -> min 또는 max mid탐색: ispossible()코드 참고
        if (ispossible(mid)) s = mid + 1;
        else                 e = mid - 1;
        
    }
 
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