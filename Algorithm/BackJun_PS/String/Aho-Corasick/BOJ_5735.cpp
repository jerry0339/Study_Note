#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100000+5, MAXC = 128;
int trie[MAXN][MAXC], piv;
int fail[MAXN];
int term[MAXN];
void init(vector<string> &v){
    memset(trie, 0, sizeof(trie));
    memset(fail, 0, sizeof(fail));
    memset(term, 0, sizeof(term));
    piv = 0;
    for(string &i : v){
        int p = 0;
        for(char &j : i){
            if(!trie[p][j]) trie[p][j] = ++piv;
            p = trie[p][j];
        }
        term[p] = 1;
    }

    queue<int> q;
    for(int i=0; i<MAXC; i++){
        if(trie[0][i]) q.push(trie[0][i]);
    }
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i=0; i<MAXC; i++){
            int next = trie[now][i];
            if(next){
                int p = fail[now];
                while(p && !trie[p][i]) p = fail[p];
                p = trie[p][i];
                fail[next] = p;
                if(term[p]) term[next] = 1;
                q.push(next);
            }
        }
    }
}

int query(string &s){
    int cnt = 0;
    int p = 0;
    for(char &i : s){
        while(p && !trie[p][i]) p = fail[p];
        p = trie[p][i];
        if(term[p]) {
            cnt++;
            p = 0;
        }
    }
    return cnt;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    while(true){
        int N,M;
        string str;
        cin>>N>>M;
        if(!N && !M) break;
        getline(cin,str);
        vector<string> v;
        for(int i=0; i<N; i++) {
            getline(cin, str);
            v.push_back(str);
        }
        
        init(v);

        int ret = 0;
        for(int i=0; i<M; i++){
            getline(cin, str);
            ret += query(str);
        }
        cout<<ret<<'\n';
    }
}