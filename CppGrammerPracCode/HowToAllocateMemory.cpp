#include <iostream>
#include <vector>
#define rep(i, x, n) for (int i = x; i < n; i++)

using namespace std;

class Node {
public:
    int num;
    Node(int num) : num(num) {}
};

// Vector_Init(.....).cpp 자료와 함께보면 좋음...
int main() {
    int N, M;
    cin >> N >> M;
    //vector<vector<int>> arr(N, vector<int>(Y)); // 이렇게 한번에 메모리할당도 가능함.

    //------------------------------------------------------------
    // 간단한 int형 2차원 벡터 동적으로 생성하기.
    vector<vector<int>> arr(N);
    for (int i = 0; i < N; i++)
        arr[i] = vector<int>(M);
    // assign 함수로 M개의 항을 모두 i+1으로 같게 초기화하는 코드
    for (int i = 0; i < N; i++) { 
        arr[i].assign(M, i + 1);
    }

    //출력
    rep(i, 0, N) {
        rep(j, 0, M) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    //------------------------------------------------------------


    //------------------------------------------------------------
    // 클래스로 2차원 벡터 만들기, 동적으로 생성하기
    cout << endl;
    vector<vector<Node*>> node(N);

    //아래 코드도 M을 입력받아 동적할당하지만, 열의 개수를 모두 M으로 같도록 할당해준 코드 -> Static allocation 이라고 표현
    cout<<"Static allocation of 2-Dimension Vector"<< endl;
    for (int i = 0; i < N; i++) {
      node[i] = vector<Node*>(M);
      for(int j=0; j<M; j++){
          node[i][j] = new Node(i*j);
      }
    }
    for (int i = 0; i < N; i++) { // 출력
        for (int j = 0; j < M; j++) {
            cout << node[i][j]->num << " ";
        }
        cout << endl;
    }
    cout<<endl;

    // 아래코드는 위와는 달리 push_back()함수를 통해 행마다 다른 열의 개수를 가질 수 있음
    cout<<"Dynamic allocation of 2-Dimension Vector using push_back()"<< endl;
    int m = M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < m; j++) {
            node[i].push_back(new Node(i * j));
        }
        m++;
    }
    m = M;
    for (int i = 0; i < N; i++) { // 출력
        for (int j = 0; j < m; j++) {
            cout << node[i][j]->num << " ";
        }
        m++;
        cout << endl;
    }

    // 아래코드는 Node(i*j) 에서 오류가남. new키워드 없이 생성자를 바로 호출 불가
    // 그냥.... 클래스나 구조체로 vector사용할때에는 포인터 사용하자.
    /*
    vector<vector<Node>> node(N);
    for (int i = 0; i < N; i++) {
        node[i] = vector<Node>(M);
        for (int j = 0; j < M; j++) {
            node[i][j] = Node(i * j);
        }
    }*/

    //------------------------------------------------------------
}