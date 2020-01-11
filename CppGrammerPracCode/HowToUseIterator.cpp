#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Node {
   private:
    int num;
    int sum;
    int fac;

   public:
    Node(int n) : num(n) {
        sum = sumFunc(n);
        fac = facFunc(n);
    }
    // Function Prototype
    int sumFunc(int);
    int facFunc(int);
    int getNum();
    int getSum();
    int getFac();
};

int main() {
    vector<Node*> n;
    int N;
    cin >> N;

    // Node초기화. 1~N까지 인덱스에따라 num, sum, fac를 생성자를 이용하여 초기화
    for (int i = 1; i <= N; i++) {
        n.push_back(new Node(i));
    }

    vector<Node*>::iterator iter = n.begin();
    iter++;  // 0 -> 1번 노드로 이동
    cout << "<Testing of iterator>" << endl;
    cout << "print : " << (*(iter - 1))->getNum() << endl;  // 1출력
    cout << "print : " << (*iter)->getNum() << endl;        // 2출력
    cout << "print : " << iter[1]->getNum() << endl;        // 3출력
    cout << "print : " << (*iter++)->getNum() << endl;      // 2출력
    cout << "print : " << (*++iter)->getNum() << endl;      // 4출력
    cout << endl;

    int M;
    cin >> M;
    // M만큼 수를 받고 그 수가 node에 있으면 삭제
    while (M--) {
        if (n.empty()) break;
        int searchIdx;
        cin >> searchIdx;
        for (vector<Node*>::iterator it = n.begin(); it != n.end(); it++) { // iterator 변수 생성방법, 종료조건
            if (searchIdx == (*it)->getNum()) {
                n.erase(it);
                break;
            }
        }
    }

    // iterator이용하여 Node 모두 출력
    cout << "<Information of Nodes>" << endl;
    for (auto it = n.begin(); it != n.end(); it++) { // auto 자료형으로 컴파일러가 알아서 iterator형으로 변수 생성해줌.
        cout << "Num : " << (*it)->getNum() << ", Sum : " << (*it)->getSum() << ", Fac : " << (*it)->getFac() << endl;
    }
    cout<<"\n";

    // foreach문 이용하여 Node 모두 출력
    cout << "<Information of Nodes by foreach>" << endl;
    for(Node* it : n){
        cout << "Num : " << it->getNum() << ", Sum : " << it->getSum() << ", Fac : " << it->getFac() << endl;
    }

}

// Function Definition
int Node::facFunc(int n) {
    int result = 1;
    for (int i = n; i > 0; i--) {
        result *= i;
    }
    return result;
}
int Node::sumFunc(int n) {
    int result = 0;
    for (int i = 1; i <= n; i++) {
        result += i;
    }
    return result;
}
int Node::getNum() {
    return num;
}
int Node::getSum() {
    return sum;
}
int Node::getFac() {
    return fac;
}
