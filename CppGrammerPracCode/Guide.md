- 1억연산은 일반적인경우 1초에 수행한다고 인식 (단순 덧셈의 경우 운이좋으면, 50억연산을 2초정도에 수행 가능)
- 스택영역에 할당되는 변수(지역변수)의 크기는 보통 1M로 제한이 되어 있다. (1,048,576 바이트)
- 지역변수로 1M가 넘는 크기의 변수를 생성하면 stack overflow가 나기때문에 동적할당을 통해 힙역영에 할당해야한다.(전역변수 생성도OK)
- 백만byte는 대략 1MB차지 -> arr[10000][10000] 이차원 배열은 400MB차지함(정확히 381.4MB).
- 데이터의 접근만 하는경우 배열사용이 좋고, 데이터의 update(추가)와 delete(삭제)가 필요한 경우 list가 좋다. : 리스트와 배열의 차이점 장단점

[알고리즘 길라잡이](https://ryute.tistory.com/m/33 "류트님 블로그")
[알고리즘 공부순서](https://baactree.tistory.com/14 "박트리님 블로그")

# 알고리즘을 공부하면서 가장 중요한것..
# 답을 계속보면 답에 의존하게 되어서 코딩실력 안늘어난다 -> X
# 응용은 모방에서 오기때문에 한두시간 고민하다 안되면
# 무조건 답을 보고 익히는것이 맞다.

# stl 컨테이너
<vector> : 가변배열
<queue> : FIFO(First In First Out) 선입선출 자료구조
<deque> : 덱(앞뒤로 넣고빼는 큐)
<list> : 양방향 연결리스트
<stack> : FILO(First In Last Out) 선입후출 자료구조
<map> : 이진탐색트리 기반 / 자동정렬 / key - value pair로 구성
<set> : 이진탐색트리 기반 / 자동정렬 / key 만 저장함
<string> : 문자열


# stl 함수
> 1. [find()](#9.1)
> 2. [binary_search()](#9.2)
> 3. [lower_bound(), upper_bound()](#9.3)
> 4. [sort()](#9.4)
> 5. [unique()](#9.6)

* 나중에 필요할때
<unordered_map> : 정렬되지않은 map
<unordered_set> : 정렬되지 않은 set
<priority_queue> : 우선순위큐 힙기반임

* include<bits/stdc++.h>
* 깃허브
* slack - 아이디만 만들어 놓기
* [백준](https://www.acmicpc.net/) 가입,학교등록
* [솔브드](https://solved.ac/)

* 한문제에 1시간 ~ 2시간 넘어가면 답보기
* BOJ_1260 풀고나서 백트래킹 문제풀기 (1260 필수로 풀기)
* 다이나믹 프로그래밍 문제들은 나중에...
