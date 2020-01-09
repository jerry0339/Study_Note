#include <iostream>
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

    for (int i = 1; i <= N; i++) {
        n.push_back(new Node(i));
    }

    vector<Node*>::iterator iter = n.begin();
    iter++;  // 0 -> 1번 노드로 이동
    cout << "<Testing of iterator>" << endl;
    cout << (*(iter - 1))->getNum() << endl;  // 1출력
    cout << (*iter)->getNum() << endl;        // 2출력
    cout << iter[1]->getNum() << endl;        // 3출력
    cout << (*iter++)->getNum() << endl;      // 2출력
    cout << (*++iter)->getNum() << endl;      // 4출력
    cout << endl;

    int M;
    cin >> M;
    while (M--) {
        if (n.empty()) break;
        int searchIdx;
        cin >> searchIdx;
        for (auto it = n.begin(); it != n.end(); it++) {
            if (searchIdx == (*it)->getNum()) {
                n.erase(it);
                break;
            }
        }
    }

    cout << "<Information of Nodes>" << endl;
    for (vector<Node*>::iterator it = n.begin(); it != n.end(); it++) {
        cout << "Num : " << (*it)->getNum() << ", Sum : " << (*it)->getSum() << ", Fac : " << (*it)->getFac() << endl;
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

