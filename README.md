# **< Master-of-Algorithm >**
- 알고리즘PS의 시작

[https://ryute.tistory.com/m/33]


# 목록
1. VS Code 단축키, 사용법
2. C++ default main code
3. C++ References
4. String 클래스
5. Vector 클래스
6. Linked List 사용예시
7. STL의 함수들
8. 기타...
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
	int N, M;
	cin>>N>>M;
	vector<int> arr(N+1);
    rep(i, 0, N) cin>>arr[i]; // i=0부터 N-1까지 (idex)
}
~~~
*********************************************************************************************************


# C++ References
~~~
C++이 제공하는 헤더에서 함수들에 대한 상세한 정보 확인가능
http://www.cplusplus.com/reference/algorithm/

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
// foreach도 포함 !
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
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
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

~~~
*********************************************************************************************************


# STL의 함수들 사용예시

1. **find() 함수**
~~~cpp
auto it = find(arr.begin(), arr.end(), a);
// iterator 로 반환

/*
 <Algo find 속도>
Binary Tree 기반 자료구조에서는 O(logn)
Hashing 으로 관리한다면 O(1)
Array 기반 자료구조는 O(n)
*/
~~~

2. **binary_search() 함수**
~~~cpp
sort(arr.begin(), arr.end());
auto result = binary_search(arr.begin(), arr.end(), a);

~~~

3. **lower_bound(), upper_bound() 함수**
~~~cpp
vector<int> v = { 1,2,4,4,4,5,7,7,7,9,10 };

// lower_bound : value보다 작지 않은 값 중 첫번째 iterator를 반환
auto l = lower_bound(v.begin(), v.end(), 4);
cout << "4의 처음 위치 : " << (l - v.begin()) << endl;
// 2 출력 (index)


// upper_bound : value보다 큰 값 중 첫번째 iterator를 반환
auto u = upper_bound(v.begin(), v.end(), 4);
cout << "4보다 큰 값 중 처음 위치 : " << (u - v.begin()) << endl;
// 5 출력 (index)

/* 
lower_bound값과 upper_bound값의 차이를 통해 value의 갯수를 구할 수 있다.
위의 결과에서 u - l = 3
4의 개수는 3개.
*/

~~~

4. **sort() 함수**
~~~cpp

~~~

5. **includes() 함수, lower,greater 클래스**
~~~cpp
#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    int N; cin>>N;
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);
    
    vector<int> v2;
    v2.push_back(10);
    v2.push_back(40);
    v2.push_back(20);
   
    vector<int> v3;
    v3.push_back(10);
    v3.push_back(20);
    v3.push_back(60);

    vector<int> v4;
    v4.push_back(40);
    v4.push_back(20);
    v4.push_back(10);
    
    // 정렬을 하고 난 후 includes로 비교해야함
    // bool형 반환
    if(includes(v1.begin(), v1.end(), v2.begin(), v2.end()))
        cout << "v2 is part of v1" << endl;
    else
        cout << "v2 is not part of v1" << endl;
    
    if(includes(v1.begin(), v1.end(), v3.begin(), v3.end()))
        cout << "v3 is part of v1" << endl;
    else
        cout << "v3 is not part of v1" << endl;
    
    //정렬 기준을 greater<int> 설정 ( 내림차순 )
    sort(v1.begin(), v1.end(), greater<int>());
    sort(v2.begin(), v2.end(), greater<int>());
    for(int num: v1){
        cout<<num<<" ";
    } cout<<"\n";
    for(int num: v2){
        cout<<num<<" ";
    } cout<<"\n";
    //비교 기준을 greater<int> 설정
    if(includes(v1.begin(), v1.end(), v2.begin(), v2.end(), greater<int>()))
        cout << "Using greater class : v2 is part of v1" << endl;
    

    sort(v1.begin(), v1.end(), less<int>());
    sort(v4.begin(), v4.end(), less<int>());
    for(int num: v4){
        cout<<num<<" ";
    } cout<<"\n";
    for(int num: v1){
        cout<<num<<" ";
    } cout<<"\n";
    //비교 기준을 less<int> 설정
    if(includes(v1.begin(), v1.end(), v4.begin(), v4.end(), less<int>()))
        cout << "Using less class : v4 is part of v1" << endl;

    return 0;
}

~~~


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
 4. endl 은 사용하지말자 !! (느림)
 ~~~
 11725 문제풀던중 정답은 나오지만 시간초과가 나오는 상황
 검색해보니....

endl은 '\n'을 출력하고 강제로 버퍼를 비움.

출력을 하던 도중에 입력을 받을 경우 버퍼를 비워야 하는게 맞지만,
11725문제 경우는 최대 10만개의 라인을 출력만 하므로 (입력을 저장한 후 bfs계산하는 코드 작성함)
endl을 쓰면 불필요하게 버퍼를 비우므로 매우 느려짐.

따라서 endl 대신 \n을 출력하여 해결함.
 ~~~
