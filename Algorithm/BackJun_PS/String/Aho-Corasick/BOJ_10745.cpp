#include<bits/stdc++.h>
using namespace std;

int N;
vector<string> words;

const int MAXN = 100000+5, MAXC = 26;
int trie[MAXN][MAXC]{}, piv, tpiv;
int fail[MAXN]{}, fCache[MAXN][MAXC];
int term[MAXN]{};
void init(vector<string> &v){
    memset(fCache,-1,sizeof(fCache));
    piv = 0;
    tpiv = 0;
    for(string &i : v){
        int p = 0;
        for(char &j : i){
            if(!trie[p][j-'a']) trie[p][j-'a'] = ++piv;
            p = trie[p][j-'a'];
        }
        term[p] = ++tpiv;
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

vector<char> query(string &s){
    int p = 0, sz = s.size(), cpos=0;
    vector<char> ret(sz+1);
    vector<int> pCache(sz+1);
    for(int k=0; k<s.size(); k++){
        char i = s[k];
        ret[cpos] = i;
        // 코드 맨 아래 주석에서 테케 예시 있음
        while(p && !trie[p][i-'a']) p = solve(p,i-'a'); 
        p = trie[p][i-'a'];
        if(term[p]) {
            cpos -= words[term[p]-1].size();
            if(cpos>=0) p = pCache[cpos];
            else p = 0;
        }
        if(cpos>=0) pCache[cpos++] = p;
        else cpos++;
    }
    ret[cpos] = 0;
    return ret;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    string str, tmp;
	cin>>str;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>tmp;
        words.push_back(tmp);
    }
    init(words);
    auto ret = query(str);
    for(auto val : ret) {
        if(!val) break;
        cout<<val;
    }
}

/*
ddabcdefg
3
abc
ddd
fg

// a의 길이만큼 fail을 매번 탐색해야 하므로 fail값 캐싱해줘야 함
aaaaaaaaaaaabbbbbbb
2
aaaaaaaaaaaaa
b
*/