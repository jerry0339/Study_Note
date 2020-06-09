// <절대값 힙> - BOJ_11286
// STL 우선순위 큐 기본문제

#include<bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(x) (int)(x).size()
#define aa first
#define bb second
typedef pair<int, int> pii;
typedef long long ll;

struct comp{
	bool operator()(pii &a, pii &b){
        // 대충 (a > b)가 참이면 a와b를 swap한다는 뜻으로 인식 -> 오름차순이 되므로 최소힙이 됨.
		if(a.aa == b.aa) return a.bb > b.bb; 
        return a.aa > b.aa;
	}
};

priority_queue<pii, vector<pii>, comp> pq;
int N,n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    while(N--){
        cin>>n;
        if(!n){
            if(pq.empty()) {cout<<0<<'\n'; continue;}
            cout<<pq.top().bb<<'\n';
            pq.pop();
        }else{
            pq.push({abs(n),n});
        }
    }

}