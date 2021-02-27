#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int N;
int m[40010]{};
vector<int> lis;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>N;
    for(int i=0; i<N; i++)
        cin>>m[i];

    lis.push_back(-INF);
    for(int i=0; i<N; i++){
        if(lis.back() < m[i]) lis.push_back(m[i]);
        else {
            auto iter = lower_bound(lis.begin(),lis.end(),m[i]);
            *iter = m[i];
        }
    }

    cout<<lis.size()-1;
}