// 답을 정해놓고 그 답이 가능한지 이진탐색하는 종류의 문제들을 Parametric Search 라고함
#include<bits/stdc++.h>
using namespace std;
int N;

bool isP(int mid){
    int cnt = 0;
    // calculate condition (cnt)
    
    //upper_bound condition
    if(cnt >= N) return true;
    else return false;
    // return cnt>=N;

    // lower_bound condition
    if(cnt > N) return true;
    else return false;
    // return cnt>N;
}

int b_search(int l, int r)
{
    int s = l, e = r, mid;
    while (s <= e) {
        mid = (s + e) / 2;
        if (isP(mid)) s = mid + 1;
        else                 e = mid - 1;

    }
    return s; // lower_bound, upper_bound(s = mid + 1;에 =포함)
    // ex) v = {1, 2, 2, 2, 3}; 에서 2를 search할때, lower_bound는 idx 1, upper_bound는 idx 4가 출력됨

    // return e; // upper_bound(=포함) - 1
    // ex) v = {1, 2, 2, 2, 3}; 에서 2를 search할때, upper_bound-1 출력시 idx 3이 출력됨
}

int lowerBoundEx(int l, int r){
    int s = l, e = r, mid;
    while(s<=e){
        mid = (s+e)/2;
        if(!isP(mid)) s = mid + 1;
        else e = mid - 1;
    }

    return s;
}