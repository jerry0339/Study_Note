
// String클래스의 substr함수 이용
// str.substr(startPos, strLength);

#include <iostream>
#include <string>
using namespace std;



// 문자 하나씩 뒤로 밀어서 출력하기
int main() {
    string s;
    cout << "input String " << '\n';
    getline(cin, s, '\n');  // 문자열 입력
    int len = s.length();   // 문자열의 길이
    for (int i = 0; i < len; i++) {
        string first = s.substr(0, 1);      // 맨 앞의 문자 1개를 문자열로 분리
        string sub = s.substr(1, len - 1);  // 나머지 문자들을 문자열로 분리
        s = sub + first;                    // 두 문자열을 연결하여 새로운 문자열로 만듦
        cout << s << endl;
        
    }
}

/*
input:
I love you

*/