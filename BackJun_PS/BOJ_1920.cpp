//<수 찾기> - 1920
// binary_search 함수 이용, 이진탐색하기위한 sort 이용.
#include<bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<n; i++)
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N;
    cin>>N;
    vector<int> arr(N);
    rep(i, 0, N)
        cin>>arr[i];
    sort(arr.begin(), arr.end());
    
    int M;
    cin>>M;
    rep(i, 0, M){
        int a;
        cin>>a;
        auto result = binary_search(arr.begin(), arr.end(), a);
        if(result){
            cout<<"1"<<"\n";
        } else cout<<"0"<<"\n";
    }
}

/*
input :
5
4 1 5 2 3
5
1 3 7 9 5

output : 
1
1
0
0
1

*/