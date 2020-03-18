// <나무자르기> - 2805
// <binary_search>이용
// 1. 인덱스가 reverse인경우
// 2. 탐색할 값이 존재하지 않을경우 근사값 출력. (근사값은 upper_bound)
// ex) 인덱스 : [8] [7] [6] [5] [4] [3] [2] [1] [0] -> 문제에서 index = 절단할 높이
//     변수값 : 10  12  13  14  16  18  21  22  23  -> 문제에서 변수값 = 나무 높이의 합 M
//     탐색할 값 : 20
//     탐색후 출력값 : 21


#include<bits/stdc++.h>
using namespace std;

int n;
long long m;
vector<int> t;

long long b_search(long long start, long long end) { // reversed index
    long long sum=0;
    long long mid = (start+end)/2;
    for(int i=0; i<n; i++) {
        long long diff = t[i];
        diff -= mid;
        if(diff<=0) break;
        sum += diff;
    }
    
    if(sum == m) {
        return mid;
    } else if(sum > m) {
        if(mid+1> start) return mid;
        b_search(start,mid+1);
    } else { // sum < m
        if(mid-1 < end) return mid-1;
        b_search(mid-1,end);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=0; i<n; i++) {
        int h; cin>>h;
        t.push_back(h);
    }
    sort(t.begin(), t.end(),greater<int>());

    long long ans = b_search(t[0]-1,0);
    cout<<ans;
}
