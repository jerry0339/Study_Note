#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 10000;
const int TrieNode = 10; // 트라이 노드의 포인터개수:10 -> 전화번호

struct Trie {
    Trie *next[TrieNode];
    bool finish;
    Trie(){
        finish = false;
        memset(next, 0, sizeof(next));
    }
    ~Trie(){
        for(int i=0; i<TrieNode; i++)
            if(next[i]) delete next[i];
    }

    void insert(const char* key){
        if(*key=='\0') finish = true;
        else {
            int cn = *key-'0';
            if(next[cn]==NULL) next[cn] = new Trie();
            next[cn]->insert(key+1);
        }
    }

    bool find(const char* key){        
        if(*key == '\0') return false;
        if(finish==true) return true;
        
        int cn = *key-'0';
        return next[cn]->find(key+1);
    }

};

int T,N;
char m[MAX_N+1][TrieNode+1]{};
Trie *root;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>T;
    while(T--){
        cin>>N;
        root = new Trie;
        for(int i=0; i<N; i++) cin>>m[i];
        for(int i=0; i<N; i++) root->insert(m[i]);

        int chk=0;
        for(int i=0; i<N; i++){
            if(root->find(m[i])) 
                chk = 1;
        }

        if(chk) cout<<"NO"<<'\n';
        else cout<<"YES"<<'\n';

        delete root;
    }

}