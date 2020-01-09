# Master-of-Algorithm
알고리즘PS의 시작


# <목록>
1. VS Code 단축키, 사용법
2. C++ defualt main code
3. C++ 문법
4. 기타...

# < VS Code 단축키, 사용법 >
*********************************************************************************************************
디버깅 하는방법 : f9(빨간점)설정후 f5로 디버깅시작, f11로 한줄씩 ㄱ
디버깅에 안보이는 변수값 보이게하려면 ? 디버깅시 조사식에 + 클릭후 추가할 변수 입력시 보임.

//컴파일러선택 : ctrl + alt + c
//실행 : ctrl + alt + r
코드러너 실행으로 바꿈 : ctrl + alt + N

o -> x로 바뀌면 저장 된거.
검색 : F1 , ctrl + shift + p
설정 : ctrl + ,
git소스제어 : ctrl + shift + g
코드정렬 : shift + alt + f


# <C++ defualt main code>
*********************************************************************************************************
{{{
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

}}}
   
# <c++ 문법>
*********************************************************************************************************
<string 클래스 정리 (append, length, at, insert, replace, finde, compare)>
  1. <String 변수 초기화방법>

    1-1) string str1 = "Hello "; // 초기화방법

    1-2) string copys(str1); // 이렇게 복사가능 (깊은복사)

    1-3) cin>>str1>>str2; cin만 사용시 공백 구분하여 입력받음

    1-4) str1 = str2 + str3; // 연산자로 문자열 붙이기 가능
    
    1-5) getline(cin, str1); // 공백문자 포함 한번에받기. c언어의 gets(str1)와 같은함수

                             // 정확히는 -> getline(입력방식, 입력버퍼시작주소, 딜리미터)   //딜리미터 : 구분문자, 

                             // 버퍼는 여기공부 : https://kks227.blog.me/60204963264

  2. 문자열 확장  : str1.append("World"); // c의 strcat()과 비슷, str1 += "World"; // 위와 같은 코드
  3. 문자열길이   : str1.length(); // 문자열 길이출력
  4. 문자열인덱싱 : str1.at(3) == str1[3]
  5. 문자열삽입   : str1.insert(6, "Happy "); //str1이 "Hello World"라면, "Hello Happy World" 가 str1에 저장됨
  6. 문자열대체   : str1.replace(0, 5, "Bye"); // 0~5인덱스까지 삭제후 Bye로 대체.
  7. 문자열검색   : str1.find("World"); // 탐색문자열이 있으면 그 시작 인덱스를 반환. 없으면 -1반환
  8. 문자열비교   : str1.compare(str2); // 같으면 0 str1이 더 작으면(우선순위높으면) -1, 크면 1반환




  # <vector 사용법>
  *********************************************************************************************************
  https://blockdmask.tistory.com/70
  *Capacity는 capacity의 크기 이상의 데이터가 들어오면 capacity의 기존메모리 x 2로 capacity가 증가함.
    
  1. vector<타입> v(n, initnum); 또는 ()안에 벡터를 넣어서 복사가능
  2. v.at(idx) 와 v[idx] 의 차이점 -> []가 더 빠르지만, at()은 인덱스 범위(range) 점검하여 벗어나면 예외를 날림(안전).
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
  19. v.erase(iter); -> iter가 가리키는 원소제거. 범위제거하려면 인자를2개넣으면됨.   *https://blockdmask.tistory.com/75 참고
  20. v.empty(); -> vector가 비었으면 리턴 true (size가 0. capacity와는 상관없는것)



# <기타등등>
*********************************************************************************************************
 c++ 입출력, 함수인자 속도 아래 블로그참고
 https://blog.naver.com/acelhj/221316329745
 <내용>
 1) ios_base::sync_with_stdio(false); cin.tie(nullptr);

  1-1) sync_with_stdio(false)는 c++ iostream 버퍼와 c의 stdio 버퍼의 동기화에 대한 함수 : false설정시 동기화, iostream만의 버퍼를 만듬

  1-2) cin.tie(nullptr); : 없으면 무조건 cin이랑 cout 들어올 때 버퍼 비움.

 2) 문자열 함수인자로 받을때는 &을 꼭 이용 ( call by reference )
 3) int값을 함수인자로 받을때는 그냥 call by value
