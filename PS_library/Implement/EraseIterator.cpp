#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
typedef pair<int,int> pii;

map<int,set<int>> m;
set<int>::iterator tmp;
vector<int> ans;

int main(){
    for(auto it = m.begin(); it != m.end(); ){ // ++it를 for문 조건에 넣지않음
        tmp = it->yy.begin();
        ans.push_back(*tmp);
        it->yy.erase(tmp++);
        
        // it++로 넣으면 반복자 복사를 먼저하고 erase하기 때문에 지우고 나서도 다음반복자 참조가능
        if(it->yy.size()==0) m.erase(it++); 
        else ++it; // 지우는게 아니라면 다음반복자를 참조 할 수 있도록 함
    }
}
