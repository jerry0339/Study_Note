#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;

int N;
vector<pair<int,string>> stk;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    stk.push_back({0,""});

    cin>>N;
    string str, ch;
    int t, tt;
    for(int i=0; i<N; i++){
        cin>>str;
        if(str == "type") {
            cin>>ch>>t;
            stk.push_back({t, stk.back().yy+ch});
        }
        else { // "undo"
            cin>>tt>>t;
            int nextTime = t-tt;

            if(nextTime<=0) {
                stk.push_back({t,""});
                continue;
            }

            for(int i = stk.size()-1; i>=0; i--){
                int a = stk[i].xx;
                string b = stk[i].yy;
                if(a < nextTime){
                    stk.push_back({t,b});
                    break;
                }
            }
        }
    }

    cout<<stk.back().yy;
}
