#include<iostream>
#include<algorithm>
#include<sstream> // sstream 이용
#include<string>
#include<vector>
#include<map>
#define xx first
#define yy second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int INF = 0x3f3f3f3f;
const ll llINF = 1e18;

int N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    string s;
    getline(cin, s);
    for(int i=0; i<N; i++) {
        getline(cin, s, '\n');
        stringstream ss(s); // #include<sstream>
        string token;
        while(getline(ss, token, '$')) cout<<token<<'\n'; // '$' 과 같이 구분할 문자 정할 수 있음
        //while(ss>>token) cout<<token<<'\n';             // ' '로 알아서 구분
        cout<<'\n';
        
        // for(int j=0; j<4; j++) ss>>tmp;
    }
}