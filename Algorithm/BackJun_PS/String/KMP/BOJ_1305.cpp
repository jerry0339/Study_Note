// 광고

#include<bits/stdc++.h>
using namespace std;

int L;
string str;

vector<int> getPI(string p) {
    int M=p.size();
    vector<int> fail(M,0);
    for(int i=1, j=0; i<M; i++) {
        while(j>0 && p[i]!=p[j]) j = fail[j-1];
        if(p[i] == p[j]) fail[i] = ++j;
    }
    return fail;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>L;
    cin>>str;

    auto v = getPI(str);
    cout<<L-v.back();
}