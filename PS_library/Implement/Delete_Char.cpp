#include<bits/stdc++.h>
using namespace std;

/*
1. remove함수로 공백문자 검색후 모두 삭제시킴.
2. erase함수를 이용하여 비어있는 문자열을 삭제시킴. 
    -> (remove함수는 삭제를 시킬때 배열 또는 문자열의 총 길이를 변경시키지 않기때문)

- 공백뿐만아니라 특정 문자열을 검색하여 그 문자열을 삭제할때 요긴하게 쓰일 수 있는 코드이다

*/

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string str = "I am nutella !!!";
    
    std::string::iterator end_pos = std::remove(str.begin(), str.end(), ' '); 
    str.erase(end_pos, str.end());
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());

    cout<<str;
    // Iamnutella!!! 출력
}