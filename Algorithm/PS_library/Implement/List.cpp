// https://www.acmicpc.net/problem/5397
// BOJ_5397 - 키로커
// list 이용

#include<bits/stdc++.h>
using namespace std; 
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N; 
    cin>>N;
    while (N--) {
        string str;
        cin>>str;
        list<char> lt;
        auto cursor = lt.begin();
 
        for(int i=0; i<str.size(); i++) {
            char ch = str[i];
            if(ch == '-'){
                if (cursor != lt.begin())  lt.erase((--cursor)++);
            } else if(ch == '<'){
                if (cursor != lt.begin()) cursor--;
            } else if(ch == '>'){
                if (cursor != lt.end()) cursor++;
            } else {
                lt.insert(cursor, ch);
            }
        }

        for (auto x : lt) cout<<x;
        cout<<'\n';
    }
}
