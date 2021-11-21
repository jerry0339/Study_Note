#include<iostream>
#include<algorithm>
#include<sstream> // sstream 이용
#include<string>
#include<vector>
using namespace std;

int N;
vector<string> lines;

void init(){
    lines.push_back("2016-09-15 20:59:57.421 0.351s");
    lines.push_back("2016-09-15 20:59:58.233 1.181s");
    lines.push_back("2016-09-15 20:59:58.299 0.8s");
    lines.push_back("2016-09-15 20:59:58.688 1.041s");
    lines.push_back("2016-09-15 20:59:59.591 1.412s");
    lines.push_back("2016-09-15 21:00:00.464 1.466s");
    lines.push_back("2016-09-15 21:00:00.741 1.581s");
    lines.push_back("2016-09-15 21:00:00.748 2.31s");
    lines.push_back("2016-09-15 21:00:00.966 0.381s");
    lines.push_back("2016-09-15 21:00:02.066 2.62s");
}

int main() {
    init();
    for(auto &line : lines){
        stringstream ss(line);
        string token;
        // getline(ss, token, split기준)
        while(getline(ss, token, ' ')) cout<<token<<"###"; 
        cout<<'\n';
    }
    
}