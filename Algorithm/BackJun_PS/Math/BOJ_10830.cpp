#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> Matrix;
const ll MOD = 1000;

ll N,B;
Matrix mt;

// (n*m * m*l) 행렬 곱
Matrix operator*(const Matrix &x, const Matrix &y){
    Matrix res(x.size(),vector<ll>(y[0].size(),0));
    for(ll i=0; i<x.size(); i++){
        for(ll k=0; k<y[0].size(); k++){
            for(ll j=0; j<x[i].size(); j++){
                res[i][k] += x[i][j] * y[j][k];
            }
            res[i][k] %= MOD;
        }
    }
    return res;
}

Matrix fastp(Matrix x, ll y){
    if(y == 0) {
        // 단위행렬 반환
        int size = x[0].size();
        Matrix unit(size, vector<ll>(size,0));
        for(int i=0; i<size; i++) unit[i][i] = 1;
        return unit;
    }
    if(y&1) return x * fastp(x, y-1);
    auto tmp = fastp(x, y/2);
    return tmp * tmp;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>B;
    mt.resize(N,vector<ll>(N,0));
    for(ll i=0; i<N; i++) {
        for(ll j=0; j<N; j++){
            cin>>mt[i][j];
        }
    }

    auto ans = fastp(mt, B);
    for(auto v : ans){
        for(auto val : v){
            cout<<val<<' ';
        }
        cout<<'\n';
    }
}