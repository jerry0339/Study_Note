#include<bits/stdc++.h>
using namespace std;

int n;
string m = "";

vector<int> getPI(string p) {
    int M=p.size();
    vector<int> fail(M,0);
    for(int i=1, j=0; i<M; i++) {
        while(j>0 && p[i]!=p[j]) j = fail[j-1];
        if(p[i] == p[j]) fail[i] = ++j;
    }
    return fail;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    string str;
    for(int i=0; i<n; i++) {
        cin>>str;
        if(str.size()<6) for(int i=0; i<6-str.size(); i++) m += '0';
        m += str;
    }
    reverse(m.begin(), m.end());
    auto ret = getPI(m);

    int idx=5, mxval=0;
    for(int i=5; i<ret.size(); i+=6){
        if(ret[i]%6) continue;
        if(ret[i]>mxval) mxval = ret[i], idx=i;
    }
    int k = (ret.size() - idx - 1) / 6;
    int p = (idx - ret[idx] + 1) / 6;
    if(k==n) p = 1;
    cout<<k<<' '<<p;
}