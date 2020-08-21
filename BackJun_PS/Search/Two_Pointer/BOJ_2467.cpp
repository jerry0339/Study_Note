// <용액> - BOJ_2467
// 투포인터

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define abs(x) ((x) < 0 ? (-(x)) : (x))
const int INF = 2000000000LL;

int N;
vector<int> v;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    int t;
    for(int i=0; i<N; i++) {
        cin>>t;
        v.push_back(t);
    }

    int l=0, r=N-1;
    int min_=INF;
    int a, b;
    while(l<r){
        int cs = v[l]+v[r];
        int as = abs(cs);
        if(min_ > as) {
            min_ = as;
            a = v[l];
            b = v[r];
        }
        if(cs<0) l++;
        else if(cs>0)r--;
        else {
            cout<<v[l]<<' '<<v[r];
            return 0;
        }
    }
    cout<<a<<' '<<b;
}

