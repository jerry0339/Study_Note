// <삭삽정렬> - BOJ_13884

#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int T,K,N;
int arr[1001]{};
int brr[1001]{};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    int minarr = 0;
    while(T--){
        cin>>K>>N;
        for(int i=0; i<N; i++){
            cin>>arr[i];
            brr[i] = arr[i];
        }
        sort(brr, brr+N);
        int idx = 0;
        for(int i=0; i<N; i++){
            if(arr[i] == brr[idx]) idx++;
        }
        cout<<K<<' '<<N-idx<<'\n';
    }
}