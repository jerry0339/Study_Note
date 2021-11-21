// <제곱 ㄴㄴ수> BOJ_1016
// 아리스토 테네스의 체

#include<bits/stdc++.h>
using namespace std;

/*
1 <= min <= 1e12
min <= max <= (min + 1e6)
[min,max] 제곱ㄴㄴ수 cnt ?
*/

long long min_,max_;
long long pow_[1000001]={0,};
bool vi[1000001]={0,}; // 제곱수로 나눠지면 1
int cnt=0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>min_>>max_;
    long long i;
    long long j;
    for(i=2; i<=1000000; i++){
        if(i*i>max_) break;
        long long div = i*i;
        long long start = min_/div;
        if(start*div != min_) start++;
        for(j=start; j*div<=max_; j++){
            vi[j*div-min_] = true;
        }
    }
    for(int k=0; k<max_- min_+1; k++){
        if(!vi[k]) cnt++;
    }

    cout<<cnt;
}