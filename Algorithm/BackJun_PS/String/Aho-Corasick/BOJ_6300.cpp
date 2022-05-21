#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
using pii = pair<int,int>;
using piic = pair<pii,char>;

int L,C,W;
char m[1001][1001]{};
vector<string> words;
vector<piic> ans(1000,{{-1,-1},'A'});

const int MAXN = 100000+5, MAXC = 26;
int trie[MAXN][MAXC], piv, tpiv;
int fail[MAXN];
int term[MAXN];
void init(vector<string> &v){
    memset(trie, 0, sizeof(trie));
    memset(fail, 0, sizeof(fail));
    memset(term, 0, sizeof(term));
    piv = 0;
    tpiv = 0;
    for(string &i : v){
        int p = 0;
        for(char &j : i){
            if(!trie[p][j-'A']) trie[p][j-'A'] = ++piv;
            p = trie[p][j-'A'];
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

vector<pii> query(string &s){
    int p = 0;
    vector<pii> v;
    for(int k=0; k<s.size(); k++){
        char i = s[k];
        while(p && !trie[p][i-'A']) p = fail[p];
        p = trie[p][i-'A'];
        if(term[p]) v.push_back({k, term[p]});
    }
    return v;
}

void setAns(piic &a, piic b){
    if(a.xx.xx == -1) {
        a = b;
    } else {
        if(a.xx.xx == b.xx.xx) {
            if(a.xx.yy == b.xx.yy) {
                if(a.yy > b.yy) a = b;
            } else if(a.xx.yy > b.xx.yy){
                a = b;
            }
        } else if(a.xx.xx > b.xx.xx) {
            a = b;
        }
    }
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin>>L>>C>>W;
    string str;
    for(int i=0; i<L; i++){
        cin>>str;
        for(int j=0; j<C; j++){
            m[i][j] = str[j];
        }
    }
    for(int i=0; i<W; i++){
        cin>>str;
        words.push_back(str);
    }
    init(words);

    // ----------set A----------
    for(int j=0; j<C; j++){
        string str = "";
        for(int i=L-1; i>=0; i--){
            str.push_back(m[i][j]);
        }
        auto v = query(str);
        for(auto val : v){
            string now = words[val.yy-1];
            int stIdx = L-1 - (val.xx - now.size() + 1);
            piic tmp = {{stIdx, j},'A'};
            setAns(ans[val.yy-1], tmp);
        }
    }
    // ----------set C----------
    for(int i=0; i<L; i++){
        string str = m[i];
        auto v = query(str);
        for(auto val : v){
            string now = words[val.yy-1];
            int stIdx = (val.xx-now.size()+1);
            piic tmp = {{i,stIdx}, 'C'};
            setAns(ans[val.yy-1], tmp);
        }
    }
    // ----------set E----------
    for(int j=0; j<C; j++){
        string str = "";
        for(int i=0; i<L; i++){
            str.push_back(m[i][j]);
        }
        auto v = query(str);
        for(auto val : v){
            string now = words[val.yy-1];
            int stIdx = (val.xx - now.size() + 1);
            piic tmp = {{stIdx, j},'E'};
            setAns(ans[val.yy-1], tmp);
        }
    }
    // ----------set G----------
    for(int i=0; i<L; i++){
        string str = m[i];
        reverse(str.begin(), str.end());
        auto v = query(str);
        for(auto val : v){
            string now = words[val.yy-1];
            int stIdx = C-1 - (val.xx-now.size()+1);
            piic tmp = {{i,stIdx}, 'G'};
            setAns(ans[val.yy-1], tmp);
        }
    }
    // ---------set B&F---------
    vector<string> vv;
    for(int i=0; i<L; i++){
        int ii=i, jj=0;
        string str = "";
        while(ii>=0 && jj<C){
            str.push_back(m[ii][jj]);
            ii--; jj++;
        }
        vv.push_back(str);
    }
    for(int j=1; j<C; j++){
        int ii=L-1, jj=j;
        string str = "";
        while(ii>=0 && jj<C){
            str.push_back(m[ii][jj]);
            ii--; jj++;
        }
        vv.push_back(str);
    }
    for(int k=0; k<vv.size(); k++){
        string str = vv[k];
        // ----------set B----------
        vector<pii> v = query(str);
        int i=k, t=0;
        if(k>=L) t=k-L+1, i=L-1;
        for(pii val : v){
            string now = words[val.yy-1];
            int stIdx = (val.xx - now.size() + 1);
            piic tmp = {{i-stIdx, stIdx+t},'B'};
            setAns(ans[val.yy-1], tmp);
        }
        v.clear();
        reverse(str.begin(), str.end());
        // ----------set F----------
        v = query(str);
        int j=k; t=0;
        if(k>=C) t=k-C+1, j=C-1;
        for(pii val : v){
            string now = words[val.yy-1];
            int rvsStIdx = (val.xx - now.size() + 1);
            int stIdx = j-rvsStIdx;
            piic tmp = {{rvsStIdx+t, stIdx},'F'};
            setAns(ans[val.yy-1], tmp);
        }
    }
    // ---------set D&H---------
    vv.clear();
    for(int i=L-1; i>=0; i--){
        int ii=i, jj=0;
        string str = "";
        while(ii<L && jj<C){
            str.push_back(m[ii][jj]);
            ii++; jj++;
        }
        vv.push_back(str);
    }
    for(int j=1; j<C; j++){
        int ii=0, jj=j;
        string str = "";
        while(ii<L && jj<C){
            str.push_back(m[ii][jj]);
            ii++; jj++;
        }
        vv.push_back(str);
    }
    for(int k=0; k<vv.size(); k++){
        string str = vv[k];
        // ----------set D----------
        vector<pii> v = query(str);
        int i=L-k-1, t=0;
        if(k>=L) t=k-L+1, i=0;
        for(pii val : v){
            string now = words[val.yy-1];
            int stIdx = (val.xx - now.size() + 1);
            piic tmp = {{i+stIdx, stIdx+t},'D'};
            setAns(ans[val.yy-1], tmp);
        }
        v.clear();
        reverse(str.begin(), str.end());
        // ----------set H----------
        v = query(str);
        int j=k; t=0;
        if(k>=C) t=k-C+1, j=C-1;
        for(pii val : v){
            string now = words[val.yy-1];
            int rvsStIdx = (val.xx - now.size() + 1);
            int stIdx = j-rvsStIdx;
            piic tmp = {{L-1-(rvsStIdx+t), stIdx},'H'};
            setAns(ans[val.yy-1], tmp);
        }
    }

    for(int i=0; i<W; i++){
        cout<<ans[i].xx.xx<<' '<<ans[i].xx.yy<<' '<<ans[i].yy<<'\n';
    }
}