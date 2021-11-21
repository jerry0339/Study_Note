// <Scrambled Letters> - BOJ_5867
// binary search, 문자열 처리, 인덱싱

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
#define xx first
#define yy second
typedef pair<string, int> psi;
typedef pair<int, int> pii;

int N;
vector<psi> v1;
vector<psi> v2;
vector<pii> ans(50010);

bool comp1(const psi &a, const psi &b){
    string t = a.xx;
    reverse(t.begin(),t.end());
    if(t==b.xx) return false;
    return a.xx < b.xx;
}
bool comp2(const psi &a, const psi &b){
    string t = a.xx;
    reverse(t.begin(),t.end());
    if(t==b.xx) return false;
    return a.xx < b.xx;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    string str;
    for(int i=0; i<N; i++) {
        cin>>str;
        sort(str.begin(), str.end());
        v1.push_back({str,i});
        reverse(str.begin(), str.end());
        v2.push_back({str,i});
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int s,e,mid;

    for(int i=0; i<N; i++){
        string str1 = v1[i].xx;
        string str2 = v2[i].xx;
        int idx1 = v1[i].yy;
        int idx2 = v2[i].yy;

        auto a1 = lower_bound(v2.begin(),v2.end(),v1[i],comp1) - v2.begin();
        auto a2 = upper_bound(v1.begin(),v1.end(),v2[i],comp2) - v1.begin();
        ans[idx1].xx = a1+1;
        ans[idx2].yy = a2;
    }
    
    for(int i=0; i<N; i++) cout<<ans[i].xx<<' '<<ans[i].yy<<'\n';
}