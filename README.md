# **< Master-of-Algorithm >**
- 알고리즘PS의 시작


# 목록
1. VS Code 단축키, 사용법
2. C++ default main code
3. String 클래스
4. Vector 클래스
5. Linked List 사용예시
6. STL의 find()와 Sting의 find()
7. 기타...
*********************************************************************************************************


# VS Code 단축키, 사용법
~~~
컴파일러선택 : ctrl + alt + c
실행 : ctrl + alt + r
코드러너 실행 : ctrl + alt + N
검색 : F1 , ctrl + shift + p
설정 : ctrl + ,
git소스제어 : ctrl + shift + g
코드정렬 : shift + alt + f
o -> x로 바뀌면 저장 된거.
~~~
*********************************************************************************************************


# C++ default main code
~~~cpp
#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<n; i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N, K;
	cin>>N>>K;
	vector<int> arr(N+1);
    rep(i, 0, N) cin>>arr[i]; // i=0부터 N-1까지 (idex)
}
~~~
*********************************************************************************************************

   
# String 클래스
~~~
< string 클래스 정리 (append, length, at, insert, replace, finde, compare) >
  1. String 변수 초기화방법
    * string str1 = "Hello "; // 초기화방법
    * string copys(str1); // 이렇게 복사가능 (깊은복사)
    * cin>>str1>>str2; cin만 사용시 공백 구분하여 입력받음
    * str1 = str2 + str3; // 연산자로 문자열 붙이기 가능
    * getline(cin, str1); 
        - 공백문자 포함 한번에받기. c언어의 gets(str1)와 같은함수
        - 정확히는 -> getline(입력방식, 입력버퍼시작주소, 딜리미터)   //딜리미터 : 구분문자,
        - 버퍼는 여기공부 : https://kks227.blog.me/60204963264

  2. 문자열 확장  : str1.append("World"); // c의 strcat()과 비슷, str1 += "World"; // 위와 같은 코드
  3. 문자열길이   : str1.length(); // 문자열 길이출력
  4. 문자열인덱싱 : str1.at(3) == str1[3]
  5. 문자열삽입   : str1.insert(6, "Happy "); //str1이 "Hello World"라면, "Hello Happy World" 가 str1에 저장됨
  6. 문자열대체   : str1.replace(0, 5, "Bye"); // 0~5인덱스까지 삭제후 Bye로 대체.
  7. 문자열검색   : str1.find("World"); // 탐색문자열이 있으면 그 시작 인덱스를 반환. 없으면 -1반환
  8. 문자열비교   : str1.compare(str2); // 같으면 0 str1이 더 작으면(우선순위높으면) -1, 크면 1반환
~~~
*********************************************************************************************************


# Vector 클래스
~~~
  https://blockdmask.tistory.com/70
  * Capacity는 capacity의 크기 이상의 데이터가 들어오면 capacity의 기존메모리 x 2로 capacity가 증가함.
    
  1. vector<타입> v(n, initnum); 또는 ()안에 벡터를 넣어서 복사가능
  2. v.at(idx) 와 v[idx] 의 차이점 -> []가 더 빠르지만, at()은 인덱스 범위(range)점검하여 벗어나면 예외날림(안전).
  3. v.assign(5, 2); -> 2의 값으로 5개 원소 할당
  4. v.front(); -> 첫번째 원소 참조(반환)
  5. v.clear(); -> 모든원소 제거
  6. v.push_back(7); -> 마지막 원소뒤에 7삽입
  7. v.pop_back(); -> 마지막 원소 제거
  8. v.begin(); -> 첫번째 원소 가리킴(참조아님) : iterator와 사용
  9. v.end(); -> 마지막 원소 가리킴(참조아님) : iterator와 사용
  10. v.rbegin(); v.rend(); -> 역방향 이터레이터용 주소 반환 함수
  11. v.reserve(n); -> n개원소를 저장할 위치를 예약함 (미리 동적할당)
  12. v.resize(n); -> size를 n으로 변경. size가 더 커졌을경우는 default값인 0으로 변경 (size는 원소의 개수이므로)
  13. v.resize(n,m); -> size를 n으로 변경하고 더 커졌을경우 m으로 변경
  14. v.size(); -> 원소의 개수 리턴
  15. v.capacity(); -> 할당된 공간 리턴
  16. v2.swap(v1); -> v1과 v2를 완전 스왑. (즉, capacity를 바꿈)
  17. v.insert(2, 3, 4); -> 2번째 위치에 3개의 4값을 삽입 (뒤의 값들은 뒤로밀림)
  18. v.insert(2, 3); -> 2번째 위치에 3삽입, 삽입한 곳의 iterator를 반환
  19. v.erase(iter); -> iter가 가리키는 원소제거. 범위제거시 인자를 2개넣기. https://blockdmask.tistory.com/75 참고
  20. v.empty(); -> vector가 비었으면 리턴 true (size가 0. capacity와는 상관없는것)
~~~
*********************************************************************************************************


# Linked List With Vector and Class
~~~cpp
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
        cout<<"Num : "<<(*it)->getNum()<<", Sum : "<< (*it)->getSum()<<", Fac : "<<(*it)->getFac()<<endl;
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

~~~
*********************************************************************************************************


# STL find()와 Sting find()
~~~
 -Algo find-
https://modoocode.com/261

 -String find-
https://modoocode.com/241
~~~

~~~cpp
//update 예정
~~~

**미완**

*********************************************************************************************************


# 기타등등
 c++ 입출력, 함수인자 속도 아래 블로그참고

 https://blog.naver.com/acelhj/221316329745

 1. ios_base::sync_with_stdio(false); cin.tie(nullptr);
 ~~~
  * sync_with_stdio(false)는 c++ iostream 버퍼와 c의 stdio 버퍼의 동기화에 대한 함수
    - false설정시 동기화, iostream만의 버퍼를 만듬
  * cin.tie(nullptr); : 없으면 무조건 cin이랑 cout 들어올 때 버퍼 비움.
 ~~~
 2. 문자열 함수인자로 받을때는 &을 꼭 이용 ( call by reference )
 3. int값을 함수인자로 받을때는 그냥 call by value
