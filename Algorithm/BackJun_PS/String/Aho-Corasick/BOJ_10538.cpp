#include<bits/stdc++.h>
using namespace std;

int MR, MC, NR, NC;
char m[2001][2001]{};
int picture[2001][2001]{};
vector<string> words;

int charMatcher(char ch){
    if(ch=='x') return 0;
    else return 1;
}

const int MAXN = 1000000+5, MAXC = 2;
int trie[MAXN][MAXC]{}, piv, tpiv;
int fail[MAXN]{};
int term[MAXN]{};
void init(vector<string> &v){
    piv = 0;
    tpiv = 0;
    for(string &i : v){
        int p = 0;
        for(char &j : i){
            if(!trie[p][charMatcher(j)]) trie[p][charMatcher(j)] = ++piv;
            p = trie[p][charMatcher(j)];
        }
        term[p] = ++tpiv;
    }

    queue<int> q;
    for(int i=0; i<MAXC; i++) if(trie[0][i]) q.push(trie[0][i]);
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
                if(term[p]) term[next] = term[p];
                q.push(next);
            }
        }
    }
}

void query(string &s, int row){
    int p = 0;
    for(int k=0; k<s.size(); k++){
        char i = s[k];
        while(p && !trie[p][charMatcher(i)]) p = fail[p];
        p = trie[p][charMatcher(i)];
        if(term[p]) picture[row][k] = term[p];
    }
}

int query2(string &s){
    int p = 0;
    for(int k=0; k<s.size(); k++){
        char i = s[k];
        while(p && !trie[p][charMatcher(i)]) p = fail[p];
        p = trie[p][charMatcher(i)];
        if(term[p]) return term[p];
    }
}

vector<int> getPI(string p) {
    int M=p.size();
    vector<int> fail(M,0);
    for(int i=1, j=0; i<M; i++) {
        while(j>0 && p[i]!=p[j]) j = fail[j-1];
        if(p[i] == p[j]) fail[i] = ++j;
    }
    return fail;
}

int KMP(string s, string p) { 
    int N=s.size(), M=p.size(), ret=0;
    vector<int> fail=getPI(p);
    for(int i=0, j=0; i<N; i++) {
        while(j>0 && s[i]!=p[j]) j = fail[j-1];
        if(s[i] == p[j]) {
            if(j == M-1) {
                ret++;
                j = fail[j];
            } else ++j;
        } 
    }
    return ret;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin>>MR>>MC>>NR>>NC;
    string str;
    for(int i=0; i<MR; i++){
        cin>>str;
        words.push_back(str);
    }
    init(words);

    for(int i=0; i<NR; i++){
        cin>>str;
        query(str, i);
    }
    string ord = "";
    for(int i=0; i<words.size(); i++){
        ord += (query2(words[i])+'0');
    }

    int ans = 0;
    for(int j=MC-1; j<NC; j++){
        string tmp = "";
        for(int i=0; i<NR; i++){
            tmp += (picture[i][j]+'0');
        }
        ans += KMP(tmp, ord);
    }
    cout<<ans;
}