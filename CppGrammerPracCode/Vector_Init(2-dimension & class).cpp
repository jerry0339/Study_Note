#include <iostream>
#include <vector>
#define rep(i, x, n) for(int i=x; i<n; i++)
using namespace std;

class Node {
   public:
    int num;
    vector<int> arr;
    string str;
    Node(int num, vector<int> arr, string str) : num(num), arr(arr), str(str) {}
};

int main() {
    int N;
    cin >> N;
    //Node testNode;
    //cout<<testNode.num<<" "<<testNode.str<<" "<<"끝"<<endl;
    // 구조체 & 클래스 생성시 멤버들은 0 or NULL로 초기화 안됨...!!!
    // 따라서 노드 생성시 초기화를 같이 해줘야함 -> 아래코드 참고

    //벡터 초기화 방법
    vector<Node*> n;
    vector<int> arr(N);
    arr.assign(N,3); // arr배열의 0 ~ N-1 인덱스까지 3으로 할당(초기화)
    string str("test !!!");

    // 리스트 한개만 생성해서 테스트했음
    n.push_back(new Node(20,vector<int>(N),string("TEST")));
    //n.push_back(new Node(20,arr,str));
    rep(i, 0, N) {n[0]->arr[i] = i;}
    rep(i, 0, N) {cout << n[0]->num++ << " " << n[0]->arr[i] <<" "<< n[0]->str << " end" << endl;}

    // 2차원배열 or 리스트 생성방법
    int X,Y;
    cin>>X>>Y;
    //vector<vector<int>> arr2(N, vector<int>(Y)); // 이렇게 한번에 선언도 가능함.
    vector<vector<int>> arr2(N);
    for(int i =0; i<X; i++){
        arr2[i].push_back(i+1);
    }

    // 노드가 들어간 2차원배열 생성
    vector<vector<Node*>> n2(X);
    for(int i=0; i<X; i++){
        n2[i] = vector<Node*>(Y);
        for(int j=0; j<Y; j++){
            n2[i][j] = new Node(20,vector<int>(),string("TEST"));
        }
        
    }

}