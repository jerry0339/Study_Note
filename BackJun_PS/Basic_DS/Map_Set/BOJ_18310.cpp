// greedy

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
map<int,int> m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    int k;
    for(int i=0; i<N; i++) {
        cin>>k;
        m[k]++;
    }

    int sum = 0;
    for(auto val : m){
        sum += val.second;
        if(sum>=((N+1)/2)) {
            cout<<val.first;
            return 0;
        }
    }
}