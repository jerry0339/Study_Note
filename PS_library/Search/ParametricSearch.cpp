// 답을 정해놓고 그 답이 가능한지 이진탐색하는 종류의 문제들을 Parametric Search 라고함
#include<bits/stdc++.h>
using namespace std;
int N;

bool ispossible(int mid){
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
        if (ispossible(mid)) s = mid + 1;
        else                 e = mid - 1;

        /*
        if(v[mid] < val)      s = mid + 1;
        else if(v[mid > val]) e = mid - 1;
        else { // v[mid] == val
            // == 따로 정의
            // ex) v = {1, 2, 2, 2, 3}; 에서 2를 search할때, mid(idx)가 1,2,3일때 s와 e의 idx이동을 정의
        }
        */
    }
    return s; // lower_bound, upper_bound(s = mid + 1;에 =포함)
    // ex) v = {1, 2, 2, 2, 3}; 에서 2를 search할때, lower_bound는 idx 1, upper_bound는 idx 4가 출력됨

    // return e; // upper_bound(=포함) - 1
    // ex) v = {1, 2, 2, 2, 3}; 에서 2를 search할때, upper_bound-1 출력시 idx 3이 출력됨
}