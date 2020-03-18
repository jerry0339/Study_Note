// <나머지> - 3052
// unique()함수 사용
#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> v(10);
    for(int i=0; i<10; i++) {
        cin>>v[i];
        v[i] %= 42;
    }
    sort(v.begin(),v.end());
    auto it = unique(v.begin(),v.end()); 
    // unique함수는 중복된수들을 뒤로 밀어냄, 중복수들의 첫번째수의 iterator를 반환
    // erase(it,v.end()); 하면 v에는 중복이 제거된 수만 남음
    cout<<it - v.begin();
}