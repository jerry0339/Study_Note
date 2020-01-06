#include <iostream>
using namespace std;

class MyClass {
   private:
    static int static_n;  // 스테틱 멤버
    double f;

   public:
    int n, m;
    //  멤버함수 프로토타입 (선언)
    static void set_static(int);  // 스테틱 멤버
    static int get_static();
    void setF(double);
    double getF();
    int sum();
    void print();
};

// static변수는 main()함수 시작전 한번 이상의 초기화가 꼭!!! 필요함.
int MyClass::static_n = 0;

int main() {
    MyClass A, B;  // <- A: 오브젝트라고 부름 (즉, 클래스 자료형을 가진 변수 = 오브젝트)
    int k; cin>>k;
    A.n = 19;
    A.m = 1;
    A.setF(1.1);
    B.n = 23;
    B.m = 2;
    B.setF(3.14);

    double sumf = A.getF() + B.getF();
    cout << "sum of f : " << sumf << endl;

    A.sum();
    B.sum();
    A.print();
    B.print();

    //static변수는 main()함수 시작전 초기화 필요한걸 잊지말자...!!!!
    MyClass::set_static(28);  // static멤버는 오브젝트없이 클래스명으로 바로접근.
    cout << "static_n : " << MyClass::get_static() << endl;
    return 0;
}

// MyClass의 멤버함수의 정의
int MyClass::sum() {
    return m + n;
}
void MyClass::print() {
    cout << "m: " << m << ", n: " << n << endl;
}

void MyClass::setF(double val) {
    f = val;
}
double MyClass::getF() {
    return f;
}

void MyClass::set_static(int n) {  // 정의할때는 함수 앞에 static안넣어도됨.
    static_n = n;
}

int MyClass::get_static() {  // 정의할때는 함수 앞에 static안넣어도됨.
    return static_n;
}
