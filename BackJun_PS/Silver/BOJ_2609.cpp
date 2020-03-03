// <최대공약수, 최소공배수> - 2609
// 유클리드 호제법
#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int a,b;
    cin>>a>>b;
    int mul = a*b;

    while(b){
        int r = a % b;
        a = b;
        b = r;
    }

    cout<<a<<"\n"<<mul/a;
}

