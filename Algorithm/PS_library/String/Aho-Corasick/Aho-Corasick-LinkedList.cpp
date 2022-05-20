// 아호코라식(Aho-Corasick)
// [문자열 집합 판별 문제 코드](https://www.acmicpc.net/problem/9250)
// [참고 블로그](https://m.blog.naver.com/kks227/220992598966)

#include<bits/stdc++.h>
using namespace std;
 
 // 기존의 Trie에서 *fail 노드만 추가된 Trie구조체
struct Trie{
    Trie *go[26]; // 현재 노드에서 해당 문자를 받으면 가는 노드(즉, go[i] = 간선i일때 다음노드)
    Trie *fail; // 현재 노드에서 해당 문자의 go 목적지가 없을 때 가는 노드
    bool output; // 현재 노드에 도달하면 찾는 문자열 집합: 이 문제에서는 존재성만 따지면 됨
    
    Trie(){
        memset(go, 0, sizeof(go));
        output = false;
    }
    ~Trie(){
        for(int i=0; i<26; i++)
            if(go[i]) delete go[i];
    }
    void insert(const char* key){
        if(*key == '\0') output = true;
        else {
            int now = *key - 'a'; // 입력이 소문자인 경우
            if(!go[now]) go[now] = new Trie; // 현재 탐색중인 문자가 trie에 없는 경우 새노드 생성
            go[now]->insert(key+1); // 다음 문자노드 삽입하기 위해 다음 포인터(key+1) 탐색
        }
    }
};
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    char str[10001];

    // 트라이 초기화
    Trie* root = new Trie; // 트라이 루트 생성
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>str;
        root->insert(str); // 트라이에 S의 원소들 init
    }
 
    // BFS를 통해 트라이 노드를 방문하며 fail 함수를 만듦
    // -> BFS를 통해 깊이가 작은 노드부터 방문해가면 fail 함수를 DP를 적용하듯이 결정할 수 있음
    queue<Trie*> q;
    root->fail = root; // 루트의 fail은 루트
    q.push(root);
    while(!q.empty()){
        Trie *now = q.front();
        q.pop();
 
        // 다음노드 탐색 (소문자이므로 [0,25])
        for(int i=0; i<26; i++){
            Trie *next = now->go[i];
            if(!next) continue;
 
            if(now == root) next->fail = root; // 루트의 fail은 루트
            else{
                Trie *dest = now->fail;
                // fail을 참조할 가장 가까운 조상을 찾아간다.
                //  ex) -> fail("abcd") = fail("abc")의 다음 노드중 간선'd'가 있으면 다음 참조: 즉, go(fail("abc"), 'd')가 abcd의 fail함수
                //                                   -> 다음 노드중 간선'd'가 없으면 fail("abc")가 abcd의 fail함수
                while(dest != root && !(dest->go[i])) // dest가 ex)설명중 fail("abc")에 해당
                    dest = dest->fail;
                // fail(px) = go(fail(p), x) 
                if(dest->go[i]) dest = dest->go[i]; // ex)설명중 간선'd'가 있을때, 즉 go(fail("abc"),'d')
                next->fail = dest; // next의 fail 업데이트
            }
            // fail(x) = y일 때, output(y) ⊂ output(x)
            if(next->fail->output) next->output = true;
            q.push(next);
        }
    }
    
    cin>>M;
    for(int i=0; i<M; i++){
        cin>>str; // 패턴 매칭이 필요한 긴 문자열 입력받음
        Trie* now = root;
        bool result = false;
        for(int k=0; str[k]; k++){
            int next = str[k] - 'a';
            // 현재 노드에서 다음노드 탐색이 안되면 fail함수로 가장 최근 일치한 문자열로 이동
            while(now != root && !(now->go[next]))
                now = now->fail;
            if(now->go[next]) // 다음노드가 존재하면 이동.
                now = now->go[next];
            if(now->output){ // 현재 노드의 output이 true면 매칭된 문자열이 있다는 뜻
                result = true;
                break;
            }
        }
        if(result) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
    // 동적할당 해제
    delete root;
}