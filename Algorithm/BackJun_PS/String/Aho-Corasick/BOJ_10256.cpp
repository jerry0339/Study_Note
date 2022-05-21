#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5000*100+5, MAXC = 4;
int trie[MAXN][MAXC], piv;
int fail[MAXN];
int term[MAXN];

int charMatcher(char ch){
    if(ch=='A') return 0;
    else if(ch=='G') return 1;
    else if(ch=='T') return 2;
    else return 3;
}

void init(vector<string> &v){
    memset(trie, 0, sizeof(trie));
    memset(fail, 0, sizeof(fail));
    memset(term, 0, sizeof(term));
    piv = 0;
    for(string &i : v){
        int p = 0;
        for(char &j : i){
            if(!trie[p][charMatcher(j)]) trie[p][charMatcher(j)] = ++piv;
            p = trie[p][charMatcher(j)];
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
    int ret = 0;
    int p = 0;
    for(int k=0; k<s.size(); k++){
        char i = s[k];
        while(p && !trie[p][charMatcher(i)]) p = fail[p];
        p = trie[p][charMatcher(i)];
        if(term[p]) ret++;
    }
    return ret;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int T,N,M;
    string str, marker;
    cin>>T;
    while(T--){
        cin>>N>>M;
        cin>>str>>marker;
        vector<string> v;
        set<string> s;
        s.insert(marker);
        for(int i=0; i<marker.size(); i++){
            for(int j=0; j<=i; j++){
                int sz = i-j+1;
                if(sz==1) continue;
                string next = "", tmp = marker.substr(j,sz);
                reverse(tmp.begin(), tmp.end());
                next += marker.substr(0,j);
                next += tmp;
                next += marker.substr(i+1);
                s.insert(next);
            }
        }
        reverse(marker.begin(), marker.end());
        s.insert(marker);
        for(int i=0; i<marker.size(); i++){
            for(int j=0; j<=i; j++){
                int sz = i-j+1;
                if(sz==1) continue;
                string next = "";
                next += marker.substr(0,j);
                next += marker.substr(j,sz);
                next += marker.substr(i+1);
                s.insert(next);
            }
        }

        for(string now : s)v.push_back(now);
        init(v);
        cout<<query(str)<<'\n';
    }    
    
}