#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

vector<int> GetPI(const vector<int>& v) {
    int n = v.size(); vector<int> f(n);
    for (int i = 1, j = 0; i < n; i++) {
        while (j && v[i] != v[j]) j = f[j - 1];
        if (v[i] == v[j]) f[i] = ++j;
    }
    return f;
}

int main() {
    fastio;
    int n; cin >> n;
    vector<int> v(n);
    for (int i = n; i--; cin >> v[i]);

    vector<int> f = GetPI(v);
    int rk = 0, rp = n;
    for (int i = 0; i < n; i++) {
        const int k = n - 1 - i;
        const int p = i + 1 - f[i];
        if (rk + rp > k + p || rk + rp == k + p && rp > p) rk = k, rp = p;
    }
    cout << rk << ' ' << rp << '\n';
}