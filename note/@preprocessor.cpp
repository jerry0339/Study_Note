#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast")

#include<bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(x) (int)(x).size()
#define ini(x, y) memset(x, y, sizeof(x))
#define FASTIO cin.tie(NULL); ios::sync_with_stdio(false)
#define xx first
#define yy second
typedef pair<int, int> pii;
typedef long long ll;

int main() {
    FASTIO;
    
}

#define abs(x) ((x) < 0 ? (-(x)) : (x))
ll gcd(ll a, ll b) {return b ? gcd(b, a%b) : a;}
int gcd(int a, int b) {return b ? gcd(b, a%b) : a;}

priority_queue<int, vector<int>, greater<int>> pq;

typedef unsigned long long ull;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<string, int> psi;
typedef pair<char, int> pci;
typedef pair<int, char> pic;


