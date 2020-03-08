// <next_permutation(), prev_permutation() 연습>
// 두함수 모두 정렬이 되어 있어야함.
// next_permutation()은 오름차순,
// prev_permutation()은 내림차순으로 정렬되어 있어야함.
// 인자에는 range[first, last)가 들어가야 함.
// 한번수행하면 true를 반환하고 원래 순열로 돌아오면 false를 반환함.

// 재귀로 구현하려면 ?? BackTracking의 BOJ_15649를 참고...

#include<bits/stdc++.h>
using namespace std;

bool cmp(int &p1, int &p2){

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin>>n;
    vector<int> arr(n);

    // 1~n 까지 정렬된 수들로 벡터에 저장
    for(int i=0; i<n; i++) { 
        arr[i] = i+1;
    }

    // prev_permutaion의 경우 내림차순으로 정렬되어 있어야함.
    reverse(arr.begin(),arr.end());
    do{
        for(int i=0; i<n; i++)
            cout<<arr[i]<<' ';
        cout<<'\n';
    } while(prev_permutation(arr.begin(), arr.end()));

    // while문이 끝나고 아래를 출력해보면 첫번째 순열로 돌아와 있다.
    for(int i=0; i<n; i++)
            cout<<arr[i]<<' ';
    cout<<'\n';

}