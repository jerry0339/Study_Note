// <좌표 압축> - BOJ_18870 (기본문제: 실버)
// 1차원 직선상의 좌표를 압축
// 점의 범위가 10만개 정도 되는 경우 세그트리나 BIT등을 이용하여 매 쿼리를 log시간복잡도에 처리할 수 있지만
// -10억~10억 정도의 범위라면 공간복잡도가 너무 커짐 -> 따라서 좌표압축을 이용하여 공간복잡도, 시간복잡도도 줄일 수 있음.

#include<bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()

// unique()와 lower_bound() 함수를 이용한 좌표압축
/*
vector<int> v;
vector<int> idx;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N; cin>>N;
    v.resize(N);
    for(int i=0; i<N; i++)
        cin>>v[i];
    idx = v;
    sort(all(v));
    auto n = unique(all(v));
    v.erase(n,v.end());
    for(int i=0; i<N; i++){
        cout<<lower_bound(all(v),idx[i])-v.begin()<<' ';
    }

}
*/

vector<pair<int,int>> v;
int ans[1000000]{}; // 들어오는 데이터 개수만큼만 공간 사용.

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,n; cin>>N;
    v.resize(N);
    for(int i=0; i<N; i++){
        cin>>n;
        v[i]={n,i};
    }
    sort(all(v));

    int cnt=1;
    for(int i=1; i<N; i++){
        if(v[i].first==v[i-1].first) {
            ans[v[i].second] = ans[v[i-1].second];
        }
        else ans[v[i].second] = cnt++;
    }

    for(int i=0; i<N; i++)
        cout<<ans[i]<<' ';
}