// <용액> BOJ_2467
// 투포인터

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define abs(x) ((x) < 0 ? (-(x)) : (x))
typedef long long ll;

ll m[100010]{};
ll N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    ll t;
    for(ll i=0; i<N; i++) cin>>m[i];

    ll l=0, r=N-1;
    ll min_= 2000000000;
    ll a, b;
    while(l<r){
        ll cs = m[l]+m[r];
        ll as = abs(cs);
        if(min_ > as) {
            min_ = as;
            a = m[l];
            b = m[r];
        }
        if(cs<0) l++;
        else if(cs>0)r--;
        else {
            cout<<a<<' '<<b;
            return 0;
        }
    }
    cout<<a<<' '<<b;
}

