#include<bits/stdc++.h>
using namespace std;
int N;

// 답을 정해놓고 그 답이 가능한지 이진탐색하는 종류의 문제들을 Parametric Search 라고함
bool ispossible(int mid){
    int cnt = 0;
    // calculate condition (cnt)
    
    //upper_bound -1
    if(cnt >= N) return true;
    else return false;
    // return cnt>=N;

    // lower_bound
    if(cnt > N) return true;
    else return false;
    // return cnt>N;
}

int b_search(int l, int r)
{
    int s = l, e = r, mid;
    while (s <= e) {
        mid = (s + e) / 2;
        if (ispossible(mid)) s = mid + 1;
        else                 e = mid - 1;
        
    }
    return e; // -> upper_bound -1
    return s; // -> lower_bound
}