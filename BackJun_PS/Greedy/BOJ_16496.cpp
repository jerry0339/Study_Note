#include<bits/stdc++.h>
using namespace std;

int N;
vector<string> m;
bool comp(string a, string b) {
    return a + b > b + a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    string str;
    for(int i=0; i<N; i++){
        cin>>str;
        m.push_back(str);
    }
    sort(m.begin(), m.end(), comp);

    if(m[0]=="0") {
        cout<<0;
        return 0;
    }
    for(auto v : m){
        cout<<v;
    }
}