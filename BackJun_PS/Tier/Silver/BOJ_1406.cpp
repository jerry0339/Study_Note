// <에디터> - 1406
// list사용
#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string temp;
    list<char> str;
    list<char>::iterator cur;
    cin>>temp;
    for(int i=0; i<temp.length(); i++){
        str.push_back(temp[i]);
    }
    cur = str.end();

    cin>>n;
    while(n--) {
        char ch;
        cin>>ch;
        switch(ch){
            case 'L':
            if(cur!=str.begin()) cur--;
            break;

            case 'D':
            if(cur!=str.end()) cur++;
            break;

            case 'B':
            if(cur!=str.begin()) {
                auto temp = --cur;
                cur++;
                str.erase(temp);
            }
            break;

            case 'P':
            char inch;
            cin>>inch;
            str.insert(cur,inch);
            break;
        }
    }

    for(auto i=str.begin(); i!=str.end(); i++) cout<<*i;
}