// fail함수 탐색하기

/*
1. 문자열S의 Prefix이면서 동시에 Surfix인 부분문자열은 fail[N-1], fail[fail[N]-1], fail[fail[fail[N]-1]-1].... 뿐임
2. 위의 부분문자열중 Prefix,Surfix가 아닌 문자열을 찾으려면 문자열의 [1,N-1] 범위에서 찾아야 함
3. 따라서 Prefix, Surfix이면서 두 경우가 아닌 위치에서도 등장하는 부분문자열은 ,
    1.에서의 부분문자열중 fail[N-1]을 제외한 문자열중 [1,N-1] 범위에 등장하는 문자열을 찾아야 하므로
    K:[1,N-1] 범위의 fail[K]의 값이 있는지 없는지 저장하면 BOJ_13506 답을 구해낼 수 있음
*/

#include<bits/stdc++.h>
using namespace std;

string str;
bool chk[1000010]{};

vector<int> getPI(string p) {
    int M=p.size();
    vector<int> fail(M,0);
    for(int i=1, j=0; i<M; i++) {
        while(j>0 && p[i]!=p[j]) j = fail[j-1];
        if(p[i] == p[j]) fail[i] = ++j;
        //if(i != M-1) chk[fail[i]] = true;
    }
    return fail;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>str;

    auto fail = getPI(str);
    for(int i=1; i<fail.size()-1; i++){
        chk[fail[i]] = true;
    }

    for(int i=fail[str.size()-1]; i; i=fail[i-1]) {
        if(chk[i]) {
            cout<<str.substr(0,i);
            return 0;
        }
    }
    cout<<-1;
}