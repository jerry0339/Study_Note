#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
using pii = pair<int,int>;

const int MAXN = 5000000+5, MAXC = 26;
int piv, tpiv;
vector<pii> trie[MAXN]{};
int fail[MAXN]{};
int term[MAXN]{};
int len[MAXN]{};
int cache[MAXN]{};
vector<string> words;

int findNextP(int p, int c){
    for(auto next : trie[p]){
        if(next.yy == c) return next.xx;
    }
    return 0;
}

void init(vector<string> &v){
    piv = 0, tpiv = 0;
    for(string &i : v){
        int p = 0;
        for(char &j : i){
            if(!findNextP(p,j-'a')) trie[p].push_back({++piv, j-'a'});
            p = findNextP(p,j-'a');
        }
        term[p] = ++tpiv;
    }
    queue<int> q;
    for(int i=0; i<MAXC; i++) {
        int nextp = findNextP(0,i);
        if(nextp) q.push(nextp);
    }
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i=0; i<MAXC; i++){
            int next = findNextP(now,i);
            if(next){
                int p = fail[now];
                while(p && !findNextP(p,i)) p = fail[p];
                p = findNextP(p,i);
                fail[next] = p;
                if(!term[next] && term[p]) term[next] = term[p];
                q.push(next);
            }
        }
    }
}

void query(string &s){
    int p = 0;
    for(int k=0; k<s.size(); k++){
        char i = s[k];
        while(p && !findNextP(p,i-'a')) p = fail[p];
        p = findNextP(p,i-'a');
        if(term[p]) {
            cache[k-len[term[p]]+1]++;
            cache[k+1]--;
        }
    }
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int N,M;
    string str1, str2;
    cin>>N;
    cin>>str1;
    cin>>M;
    for(int i=0; i<M; i++){
        cin>>str2;
        words.push_back(str2);
        len[i+1] = str2.size();
    }
    init(words);
    query(str1);
    int ans = cache[0] ? 0:1;
    for(int i=1; i<str1.size(); i++){
        cache[i] += cache[i-1];
        if(!cache[i]) ans++;
    }
    cout<<ans;
}

/*
18
oomoomooooabcmoomo
3
moo
cm
oo

abcmoodefgh
3
moo
mood
abcdefg
*/