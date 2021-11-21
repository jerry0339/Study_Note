
#define abs(x) ((x) < 0 ? (-(x)) : (x))

typedef long long ll;
ll gcd(ll a, ll b) {return b ? gcd(b, a%b) : a;}

// 1 이상 N 이하의 정수에서 i의 빈도수
// [출처](https://cubelover.tistory.com/7?category=169015)
int frq(int n, int i) {
    int j, r = 0;
    for(j=1; j<=n; j*=10) if(n/j/10 >= !i) r += (n/10/j - !i)*j + (n/j%10 > i ? j : n/j%10 == i ? n%j+1 : 0);
    return r;
}