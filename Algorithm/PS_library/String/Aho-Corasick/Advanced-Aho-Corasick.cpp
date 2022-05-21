// [구사과님 코드 참고](https://gist.github.com/koosaga/96e5de4ccb99616f9bc3a760ec964cbe)
// [참고 블로그](https://m.blog.naver.com/kks227/220992598966)
// [그림 참고](https://blog.myungwoo.kr/101)
// [9250 문자열 집합 판별](https://www.acmicpc.net/problem/9250)

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100000+5, MAXC = 26;
int trie[MAXN][MAXC]{}, piv, tpiv; // trie[p1][i] = p2: 현재노드(p1)에서 탐색하는 문자가 i일때 가는 노드 p2 -> go(p1, i) = p2
int fail[MAXN]{}; // failure link: 현재 노드에서 해당 문자의 go 목적지가 없을 때 가는 노드
int term[MAXN]{}; // output check: 현재 노드에 도달하면 찾는 문자열 집합, 이문제에서는 존재만 따지므로 0또는1 값임
int fCache[MAXN][MAXC]; // fail 성능향상 10745 censoring 참고
vector<string> words;

void init(vector<string> &v){
    memset(fCache,-1,sizeof(fCache));
    piv = 0; // 가장 나중에 생성된 노드 번호
    tpiv = 0; // 가장 나중의 output 번호
    for(string &i : v){ // Trie에 저장할 문자열이 담긴 배열 v
        int p = 0;
        for(char &j : i){
            if(!trie[p][j-'a']) trie[p][j-'a'] = ++piv; // 다음 노드가 없으면 생성
            p = trie[p][j-'a']; // 다음 노드로 이동
        }
        term[p] = ++tpiv; // 저장할 문자열의 마지막 문자에 해당하는 노드에 번호 붙임
    }

    // BFS를 통해 깊이가 작은 트라이 노드부터 방문하면서 fail함수를 DP를 적용하듯이 생성
    queue<int> q;
    for(int i=0; i<MAXC; i++){
        // 연결리스트는 root를 넣으면 되지만, 배열로 생성된 trie는 없어서 0번노드에 연결된 노드들 큐에 넣어줘야 함
        if(trie[0][i]) q.push(trie[0][i]);
    }
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i=0; i<MAXC; i++){ // 다음 노드 탐색
            // fail함수 초기화 로직은 연결리스트버전 코드나 위의 블로그 링크 참고
            int next = trie[now][i];
            if(next){
                int p = fail[now];
                while(p && !trie[p][i]) p = fail[p];
                p = trie[p][i];
                fail[next] = p;
                if(term[p]) term[next] = term[p];
                q.push(next);
            }
        }
    }
}

// fail[p] 탑다운;
int solve(int p, int c) {
	int& ret = fCache[p][c];
	if (~ret) return ret;
	if (!p || trie[p][c]) ret = p;
	else ret = solve(fail[p], c);
	return ret;
}

int query(string &s){
    // 아래의 로직은 연결리스트버전 코드나 위의 블로그 링크 참고
    int p = 0;
    for(char &i : s){
        while(p && !trie[p][i-'a']) p = solve(p, i-'a'); // fail[p] 탑다운
        p = trie[p][i-'a'];
        // 등장하는 문자열의 개수를 구하고 싶으면 아래 조건문의 실행횟수 구해서 반환하면 됨
        if(term[p]) return term[p];
    }
    return 0;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N,M;
    string str;

	cin>>N;
	for(int i=0; i<N; i++) {
        cin>>str;
        words.push_back(str);
    }
	init(words);

	cin>>M;
	while(M--){
		string s;
		cin >> s;
		cout<<(query(s) ? "YES" : "NO")<<'\n';
	}
}