// c++17 부터는 __gcd(x,y) 함수를 제공

int gcd(int a, int b) { // 비재귀
    int r;
    while(b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int gcd(int x, int y) { // 재귀
    if (y == 0) return x;
    else return gcd(y, x%y);
}