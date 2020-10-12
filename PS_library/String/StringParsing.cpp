// 2020 Kakao Blind Req No.3

#include<bits/stdc++.h>
using namespace std;

int N,M;
vector<int> mask[1<<9];

int chkmask(string stt){
    if(stt=="cpp") return (1<<0);
    else if(stt=="java") return (1<<1);
    else if(stt=="python") return (1<<2);
    else if(stt=="backend") return (1<<3);
    else if(stt=="frontend") return (1<<4);
    else if(stt=="junior") return (1<<5);
    else if(stt=="senior") return (1<<6);
    else if(stt=="chicken") return (1<<7);
    else if(stt=="pizza") return (1<<8);
    else return 0;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N = 1;
    vector<int> ans;
    N = 6;
    M = 6;
    vector<string> info;
    info.push_back("java backend junior pizza 150");
    info.push_back("python frontend senior chicken 210");
    info.push_back("python frontend senior chicken 150");
    info.push_back("cpp backend senior pizza 260");
    info.push_back("java backend junior chicken 80");
    info.push_back("python backend senior chicken 50");
    for(int i=0; i<N; i++){
        string str = info[i];
        int mk = 0;
        int sc = 0;

        // Parsing
        while(1){
            int t = str.find(' ');
            if(t==-1) {
                sc = stoi(str);
                break;
            }
            string stt = str.substr(0, t);
            str = str.substr(t+1, str.size()-t-1);
            mk |= chkmask(stt);
        }
        mask[mk].push_back(sc);
    }

    for(int i=0; i<(1<<9); i++){
        if(mask[i].size()<2) continue;
        sort(mask[i].begin(), mask[i].end());
    }
    
    vector<string> query(6);
    query[0] = "java and backend and junior and pizza 100";
    query[1] = "python and frontend and senior and chicken 200";
    query[2] = "cpp and - and senior and pizza 250";
    query[3] = "- and backend and senior and - 150";
    query[4] = "- and - and - and chicken 100";
    query[5] = "- and - and - and - 150";
    for(int i=0; i<M; i++){
        string str = query[i];
        int mk = 0;
        int sc = 0;
        while(1){
            int t = str.find(' ');
            if(t==-1) {
                sc = stoi(str);
                break;
            }
            string stt = str.substr(0, t);
            str = str.substr(t+1, str.size()-t-1);
            int tmk = chkmask(stt);
            if(tmk) mk |= tmk;
        }

        if(mask[mk].size()==0) {ans.push_back(0); continue;}
        int idx = std::lower_bound(mask[mk].begin(), mask[mk].end(), sc-1) - mask[mk].begin();
        int sum = mask[mk].size() - idx;
        ans.push_back(sum);
    }
    for(int i=0; i<ans.size(); i++) cout<<ans[i]<<' ';
}