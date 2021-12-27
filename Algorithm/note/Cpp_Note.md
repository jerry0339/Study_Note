> 공부하면서 헷갈렸던 것들

> **마크다운 신경안쓰고 읽기용으로만 작성함**

# 0. 복습해볼 문제들 
> <물통> - BOJ_2251     : BFS
> <퇴사2> - BOJ_15486   : DP
> <합분해> - BOJ_2225   : DP (순서고려o)
> <Coins> - BOJ_3067    : DP (순서고려x - 조합)
> <크리보드> - BOJ_11058 : DP
> <뮤탈리스크> - BOJ_12869 : DP
> <벽 부수고 이동하기> - BOJ_2206
> <숨바꼭질 5> - BOJ_17071 : 위의 BOJ_2206처럼 다차원 방문을 통해 다른 경로를 탐색해야 하는 경우.
> <전구와 스위치> - BOJ_2138 : 그리디


# 1. Difference between vector <int> V[] and vector< vector<int> > V

> Using arrays are C-style coding, using vectors are C++-style coding.

> When you want to work with a fixed number of std::vector elements, you can use vector <int> V[].
> When you want to work with a dynamic array of std::vector, you can use vector< vector<int> > V.

> 초기 배열크기를 동적으로 생성하려면 vector를 이용. ex) vector<int> v(n);
> > vector<int> v[n]은 잘못된 표현. why? []는 C문법으로 fixed되어 있는 형태임


[출처](https://stackoverflow.com/questions/28712364/difference-between-vector-int-v-and-vector-vectorint-v)



**************************************************************************************************************************
# 2. STL sort()

> vector컨테이너를 sort 하려면? 그냥 sort이용
> list컨테이너를 sort 하려면? list<>().sort() 이용


**************************************************************************************************************************
# 3. 배열 초기화

> 일반 자료형의 배열값 초기화 방법
~~~cpp
int a[100];
memset(a,-1,sizeof(a));

char str[] = "almost every programmer should know memset!";
memset (str,'-',6);

// 위의 코드에서 char의 경우 인덱스0부터 6개의값이 '-'로 제대로 바뀌지만, 
// int배열의 경우 0 or -1이 아닌 값을 넣으면 이상한값이 들어감 (memset()은 byte기준으로 값초기화 해주기때문)
~~~

> vector 또는 list의 초기화 방법 예시
> > 1차원 : vector<int> v(100, -1);
> > 2차원 : vector<vector<int>> v(n); v[1].assign(100, -1);



**************************************************************************************************************************
# 4. DFS, BFS
- DFS
> `인자의 depth`는 어떠한 형태든 `탐색할 노드의 정보`가 , `dfs 함수내 for문`은 `노드안에 정해질 값을 탐색`한다고 생각하면 좋음.
> DFS는 상태공간을 나타낸 트리에서 바닥에 도달할 때까지 한 쪽 방향으로만 내려가는 방식이다.
>> 무한히 깊은곳을 찾아야 할때 효과적임.
> 미로찾기를 생각하면 쉽다. 한 방향으로 들어갔다가 막다른 길에 다다르면(=트리의 바닥에 도착) 왔던 길을 돌아가서 다른 방향으로 간다.

> 인접리스트 이용한 시간복잡도 : O(V+E) 
>> 인접리스트의 경우 정점V개 방문할때 각 정점에서 각각 다른 횟수탐색(각 정점에 이어진 간선개수만큼) 
> 인접행렬을 이용한 시간복잡도 : O(V*V)
>> 정점 V개를 방문하는데에 각 정점마다 모든정점에 대하여 연결되어 있는지 체크하므로.
> 시간복잡도 결론 : O(탐색할 노드개수 + 각노드에서 다음노드로의 탐색에 사용된 횟수의 총합)
>>             또는 O(탐색할노드개수*dfsFunc에서의 for문반복횟수)로 인식가능.

- BFS
> 큐를 써서 구현. 각 경우를 검사하면서 발생하는 새로운 경우를 큐에 집어넣고, 검사한 원소는 큐에서 뺀다.
> BFS는 모든 분기점을 다 검사하면서 진행하는 방식이다.
> 철수와 영희가 계단에서 가위바위보게임을 할때, 철수가 원하는 지점에 갈 수 있는 최소 승리 횟수는 얼마인가? 같은 문제에서 효과를 발휘
>> 이 경우 DFS는 깊이가 무한인 경우에 빠져나오지 못하며, 중복 방지를 한다고 치더라도 올바른 해를 찾는데 시간이 많이 걸린다.
> 공간 복잡도가 지수 스케일로 폭발하기 때문에 가지치기를 제대로 안하면 DFS보다 빨리 오버플로우에 다다를 수 있다.
> NxM 공간에서 하나하나의V에 대해 bfs로 탐색하면 NxM이 100x100일때 2초정도로 최대임.

* 주의할점
> DFS는 절대로 최단거리를 구해 주지 않습니다.
> BFS는 큐에서 뺀 다음이 아닌, 큐에 넣을 때 방문 체크를 해야 중복 방문이 일어나지 않습니다.

- DFS, BFS 코드

~~~cpp
// 출력(실행)후 방문확인, 이후 방문안된 정점번호가 작은노드 부터 방문
void dfs(vector<list<int>> &v, vector<bool> &vi, int st){ // v: sorted adjList, vi: isVisited, st: current node
    // 깊이의 끝까지 확인하기 때문에 return 조건이 없음
    cout<<st<<' ';
    vi[st] = true;
    for(int val : v[st]){
        if (!vi[val]) dfs(v,vi,val);
    }
}

// permutaion 출력에 사용된 dfs를 이용한 백트래킹 코드
void dfs2(int depth){
    if(depth == m){
        //print
        return;
    }

    for(int i=1; i<=n; i++){
        if(vi[i]) continue; // isVisited ?
        vi[i] = true;
        arr.push_back(i);
        dfs2(depth+1);

        // back tracking
        vi[i] = false; 
        arr.pop_back();
    }
}

// 큐에 먼저 넣고 방문확인, pop하기전 출력(실행), 
// pop된 노드와 연결된 노드중 방문안된 정점번호가 작은노드부터 queue에 삽입.
void bfs(vector<list<int>> &v, vector<bool> &vi, int st){ // v: sorted adjList, vi: isVisited, st: current node
    queue<int> q;
    q.push(st);
    vi[st] = true;
    while(!q.empty()){
        int n = q.front();
        cout<<n<<' ';
        q.pop();

        for(int val : v[n]){
            if(!vi[val]) {
                q.push(val);
                vi[val] = true;
            }
        }
    }
}
~~~
> 자세한건 1260참고



**************************************************************************************************************************
# 5. 백트래킹
[출처](https://namu.wiki/w/%EB%B0%B1%ED%8A%B8%EB%9E%98%ED%82%B9)
- 노드의 유망성을 점검하고 유망하지 않으면 그 노드의 부모 노드로 되돌아간 후 다른 자식의 노드탐색을 이어가는 방식.
- 즉, 비효율적인 경로를 차단하고 목표지점에 갈수있는 가능성이 있는 루트를 검사하는 방법.

> 백트래킹은 일종의 트리 탐색 알고리즘
> 백트래킹은 대부분 DFS로 구현한다. (경우의 수 구하기 같은 문제들)
> > 백트래킹알고리즘은 모든 경우의 수를 고려하기 때문에 BFS로 구현하면 큐가 터질 수도 있기때문
> DFS와 백트래킹의 다른점? -> DFS는 모든 경우를 탐색하기 때문에 백트래킹을 이용하면 더 빠르다. (가지치기 = Pruning)

- <BFS로 구현해야 하는 경우>
~~~
백트래킹 구현시 DFS를 절대로 쓰면 안되는 경우가 있는데, 트리의 깊이가 무한대가 될 때이다.
<미로찾기>에서 루프(회로)가 발생하는 경우, DFS는 이 가지를 탈출할 수 없게 된다.
물론 중복검사를 막기 위한 장치를 넣을 수도 있지만, 그럴 바에는 BFS가 편하다.
또 분기점 없이 길이만 죽어라 긴 길이 나타나면 스택 오버플로우가 발생할 수 있다.
<미로찾기>도 4방향(또는 8방향)중 마지막으로 진입하는 방향으로만 갔을 때 도착점이 있다거나 하면 DFS는 느리다. 
그리고 <최단거리 구하기> 에서는 BFS를 사용하는게 편리하다.
~~~

- <DFS로 구현하는 경우>
> DFS 수행 -> 유망한 노드 검토 -> 서브 트리 이동 -> 백트래킹 수행
1. DFS 수행 - 먼저 평소와 같이 깊이우선탐색인 DFS 를 수행하여 노드를 찾는다.
2. 유망한 노드 검토 - 방문한 노드를 포함해서 유망한 노드이면 서브트리로 이동하고 그렇지 않으면 백트래킹을 수행한다.
3. 방문한 노드의 하위 노드로 이동하여 다시 재귀를 통해 DFS 를 수행한다.
4. 백트래킹 수행 - 방문한 노드를 가지치기를 하고 상위 노드로 백트래킹 한 후 DFS 를 다시 수행한다.

- 대표문제 : [N-Queen - BOJ_9663](https://www.acmicpc.net/problem/9663)
> > N퀸의 정해는 Branch-and-Bound알고리즘을 이용하는것
- <코드> : BOJ_9663 참고



**************************************************************************************************************************
# 6. <Branch-and-Bound> 알고리즘 (B&B, BnB, or BB)
> 찾아본 이유: 백트래킹은 가지치기 인가..??

- [참고링크](https://cs.stackexchange.com/questions/5040/what-is-the-difference-between-bounding-and-pruning-in-branch-and-bound-algorith)
- 일반적으로 가지치기 하고 한다.
- 최적의 해 구하기위해 사용되는 알고리즘이다.
> 보통 검색 트리가 있을 때 검사해야 하는 가능한 해결책의 수를 줄이기 위해 사용되는 기술이다.

- <Bounding 과 Pruning의 구분>
> Both refer to a part of the same process where you determine that a subtree is irrelevant (= bounding) and then remove it (pruning).
> Bounding is the means of determining the bounds (lower bound or upper bound...)
> > bound란 ?? -> stl의 lower_bound, upper_bound 생각하면됨. (경계쯤으로 인식)

> Pruning is a technique needed to perform "branch and bound"-algorithms.
> >  최적의 해를 구하기 위해 bound를 판단 -> bounding
> >  bounding을 통해 판단된 유망하지 않은 노드 or 필요없는 노드를 삭제 -> pruning

- 즉, BackTracking과는 구분 되어야 함.
> 백트래킹과 B&B 모두 최적의 해를 구하기 위한 알고리즘이다.



**************************************************************************************************************************
# 7. STL next_permutation() 동작원리
- [참고링크](https://blog.naver.com/chogahui05/221292809519)

> v(1,2,3,4,5)의 next_permutation을 구할때 v(5,4,3,2,1)의 next순열은 없다. 즉 마지막
> v(3,1,5,4,2,6,8) next를 구할때 뒤에서부터 v[i] < v[j] 인 수의 쌍을 찾는다. 앞의 예시에서는 뒤에서부터 (6,8) , (1,5)의 쌍이 존재
> v[i] < v[j]를 찾았으면 v[i]보다 큰 수중에서 largest index인 수 L을 찾는다.

> v(3,1,7,6,5,4,2)을 예시로 들면,
> > (1,7)을 찾을 수 있고 v[i] = 1 이므로 1보다 큰 수중 largest index에 위치한 수 L을 찾는다. L = 2
> > v[i]와 L을 swap한다. v(3,1,7,6,5,4,2) -> v(3,2,7,6,5,4,1)
> > 그 다음 L다음부터 끝까지 reverse시킨다. v(3,2,7,6,5,4,1) -> v(3,2,1,4,5,6,7)
> > 따라서 v(3,1,7,6,5,4,2)의 next는 v(3,2,1,4,5,6,7)

> v(1,2,4,5,3)을 예시로 들면, (v[i] < v[j]) -> (4 < 5)
> > v[i] = 4 , L = 5 (여기서는 v[j]와 L이 같음)
> > swap하면 v(1,2,5,4,3)
> > reverse하면 v(1,2,5,3,4)
> > 따라서 v(1,2,4,5,3)의 next는 v(1,2,5,3,4)


**************************************************************************************************************************
# 8. next_permutation , prev_permutation
- 다음 순열로 바꿔주는 함수
- next_permutation은 오름차순, prev_permutation은 내림차순으로 정렬되어 있어야함
- 아래코드 참고(prev_permutation)

> vector를 이용한 경우
~~~cpp
// 그냥 사용법이 적힌 코드
reverse(arr.begin(),arr.end());
do{
    for(int i=0; i<n; i++)
        cout<<arr[i]<<' ';
    cout<<'\n';
} while(prev_permutation(arr.begin(), arr.end()));
~~~


> string을 이용한 경우
~~~cpp
// <다음수 구하기> - BOJ_2697
// 최대 80자리의 수가 들어갈 수 있으므로 정수형으로는 풀이가 불가능하다.
#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;

    while (n--) {
        string num; 
        cin >> num;
        if (next_permutation(num.begin(), num.end()))
            cout << num << '\n';
        else cout << "BIGGEST\n";

    }
}
~~~


**************************************************************************************************************************
# 9. next_permutation을 이용한 combination 구현하기
- next_permutation을 사용하는 방법은 review.md의 8을 참고

~~~cpp
// 이제 필요없음...
~~~



**************************************************************************************************************************
# 10. 재귀함수
> 주의할점 : return형이 있는경우, return값이 없는 경우가 생기지 않도록 유의한다...!!!
> >         이러한 오류는 IDE로 실행할 시에 오류가 생기지 않기때문에 더욱 유의하여 코딩해야함...!!!
> > 즉, 재귀함수를 사용할때는 `base condition`을 항상 먼저 생각해야 한다.

> 예시)
~~~cpp
int b_search(int start, int end) {
    long long sum=0;
    int mid = (start+end)/2;
    for(int i=0; i<n; i++) {
        int diff = t[i]- mid;
        if(diff>0) sum+= diff;
    }
    if(sum == m) {
        return mid;
    } else if(sum > m) {
        if(mid+1>start) return mid;
        return b_search(start,mid+1); // return을 안적어 주면 반환값이 없는 경우가 발생하여 런타임에러 발생!!
    } else { // sum < m
        if(mid-1 < end) return mid-1;
        return b_search(mid-1,end); // return을 안적어 주면 반환값이 없는 경우가 발생하여 런타임에러 발생!!
    }
}
~~~



**************************************************************************************************************************
# 11. C++의 클래스와 구조체
> 클래스와 구조체 속도차이는 같다.
> 구조체의 기본 접근자가 public, 클래스는 private인 것을 빼고는 100% 동일
> 사용방법에서의 차이점은 ? [참고](https://novemberfirst.tistory.com/32)



**************************************************************************************************************************
# 12. 1억 = 1초로 인식



**************************************************************************************************************************
# 13. 최단거리 = BFS , DFS는 느림 : depth순서대로 방문하기 때문. (가중치가 없으면 가능)



**************************************************************************************************************************
# 14. 다이나믹 프로그래밍 (메모이제이션 이용)
> dp_note로 정리하여 옮김.


**************************************************************************************************************************
# 15. if(a&b&c) 에서 a가 0이면 뒤에 b&c는 검사를 안함**


**************************************************************************************************************************
# 16. 배열의 인덱스를 정하는 과정에서 간단한 +1이나 -1같은 수학적 계산이 필요할때

~~~cpp
void func(){
    .....
    //if (flag) cnt[v[y][x]+1]++; 이거보다
    if (flag) cnt[++v[y][x]]++; // 이 코드가 빠름.
    // 즉, arr[a+1] 보다 arr[++a]가 더 빠르다.
    .....
}

~~~


**************************************************************************************************************************
# 17. 플로이드 와샬 & 다익스트라 알고리즘 ( +벨만포드와 다익스트라 간단비교 )
> 다익스트라 : `하나의 정점`에서 출발하여 `모든정점`으로의 최단경로 구하기
> > 다익스트라 정의: `음의 가중치가 없는` 그래프에서 한 노드에서 다른 모든 노드까지의 최단거리를 구하는 알고리즘 (DP가 이용된다.)
> > 다익스트라 알고리즘을 확장시킨 알고리즘으로 A*알고리즘이 있다.
> > > `그리디`하게 탐색하기때문에 음의 가중치가 있을땐 최단거리를 탐색하지 못함 (음의 가중치가 있을경우 `벨만-포드` 알고리즘 사용)
> > > [최단경로 : 다익스트라 & 벨만포드 비교](http://blog.naver.com/PostView.nhn?blogId=qbxlvnf11&logNo=221377612306&categoryNo=21&parentCategoryNo=0&viewDate=&currentPage=1&postListTopCurrentPage=1&from=postView)
~~~
<에츠허르 다익스트라>가 고안한 알고리즘으로, 그가 처음 고안한 알고리즘은 O(V^2)의 시간복잡도를 가졌다.
이후 우선순위 큐(=힙 트리)등을 이용한 더욱 개선된 알고리즘이 나오며, O((V+E)logV)의 시간복잡도를 가지게 되었다.
O((V+E)logV)의 시간복잡도를 가지는 이유는 각 노드마다 미방문 노드 중 출발점으로부터 현재까지 계산된 최단 거리를 가지는 노드를 찾는데에 
O(VlogV)의 시간이 필요하고, 각 노드마다 이웃한 노드의 최단 거리를 갱신할 때 O(ElogV)의 시간이 필요하기 때문이다.
* O(VlogV) + O(ElogV) = O((V+E)logV)
~~~
> [출처](https://namu.wiki/w/%EB%8B%A4%EC%9D%B5%EC%8A%A4%ED%8A%B8%EB%9D%BC%20%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98)


> 플로이드 와샬 : `모든정점`에서  `모든정점`으로의 최단경로 구하기 같은 문제에서 좋음
> > 완전탐색임. 모든 경로를 다 탐색함. (permutation생각하면 좋음)
> > 플로이드 와샬 정의: Floyd-Warshall 알고리즘은 그래프에서 가능한 모든 노드 쌍에 대해 최단 거리를 구하는 알고리즘이다.
> > 플로이드와샬 알고리즘은 DP기술에 의거한다.
> > `음의 가중치`를 가지는 그래프에서도 쓸 수 있다.
> > 시간복잡도는 O(V^3) 이다.


**************************************************************************************************************************
# 18. 단순덧셈 같은 경우 50억번의 연산은 운좋으면 2초안에 뚫을 수 있다. (TLE 맞을수도 있음)


**************************************************************************************************************************
# 19. 3항연산자보다 max()함수가 더 빠르다.


**************************************************************************************************************************
# 20. 파스칼의 삼각형
> nCr = n-1Cr-1 + n-1Cr
> ex)
~~~
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1
.....
~~~


**************************************************************************************************************************
# 21. 벡터 복사, vector.insert() 사용법

> 벡터 복사
>> v1=v2; 와 같이 바로 복사가능

> vector의 insert함수 사용 예시
>> res.insert(res.end(), tmp.begin(), tmp.end());


**************************************************************************************************************************
# 22. for_each 사용법
- for_each(begin(),end(),f);

- 사용법 예시
~~~cpp
set<int> s;
set<int> all;

void print(int n){
    cout<<n<<' ';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i=1; i<=10; i++) all.insert(i);
    s=all;
    for_each(s.begin(),s.end(),print);
}
//출력 : 1 2 3 4 5 6 7 8 9 10
~~~


**************************************************************************************************************************
# 23. find()함수 사용법, stl과 string의 find()차이
1. stl::find()
2. string::find()
> 둘 다 최악의 경우 O(n) 시간복잡도임. (n: 시작~끝)

~~~cpp
// stl find() 사용법
vector<int> v={1,2,3,1,2,3,1,2,3};
auto it = find(v.begin()+3,v.end(),3);
// 위코드에서 it에는 v.begin()+3 부터 v의 끝까지 탐색도중 처음 발견한 3이 있으면 그 iterator를 반환해줌. 
// it변수에는 v[5]의 iterator를 반환


// string find() 사용법
string str = "abcabcabc";
auto n1 = str.find("bc");
auto n2 = str.find("bc",2);
// 위 코드에서 n1에는 str처음부터 탐색도중 발견한"bc"문자열이 있으면 그 시작 인덱스를 반환해줌.
// n2에서는 str인덱스 2부터 탐색도중 발견한 "bc"문자열이 있으면 그 시작 인덱스를 반환해줌.
// 즉, n1에는 1이 n2에는 4가 반환됨.


// 차이점요약
stl::find(시작iter또는포인터, 끝, 탐색할value); -> iter or 포인터 반환. 없으면 end()반환
string::find("탐색할문자열", 탐색시작할Index); -> string의 index반환. 없으면 string::npos 반환

~~~


**************************************************************************************************************************
# 24. 연관 컨테이너 : set, map
* [참고링크](https://modoocode.com/224)

* 연관컨테이너 : key, value 구조를 갖음 -> 연관컨테이너(map,set) vs 시퀀스컨테이너(vector, list, deque)
> "abc"가 데이터에 존재하냐 ? = true           -> set or multiset
> 존재하면 이에 대응되는 값은 무엇이냐 ? = 123  -> map or multimap
* map : map, multimap
* set : set, multiset
* 위의 컨테이너의 자료구조는 모두 `RB tree`기반으로 구현되어 있음. 따라서 `랜덤 액세스`가 불가함
* [RB tree 참고](https://ko.wikipedia.org/wiki/%EB%A0%88%EB%93%9C-%EB%B8%94%EB%9E%99_%ED%8A%B8%EB%A6%AC)

* 특징
> 키는 중복 될 수 없음 -> count()함수가 있는 이유? : 연관컨테이너의 인터페이스가 모두 같으므로
> insert,erase사용시 자동 정렬 -> 객체를 map에 넣어줄경우 비교연산자를 만들어 주어야 함.
> list 나 vector보다 탐색속도가 빠르다 (자료구조가 이진트리이기 때문)
> 키와 값의 쌍들을 저장(map의 경우)
> find(), upper_bound(), lower_bound(), equal_range(), count() 같은 search함수들은 O(log(n))의 시간복잡도를 가진다.(RB tree이기때문)
> insert, erase의 경우도 O(log(n))의 시간복잡도를 가짐
> 주의할 점
>> 1) map의 경우 hashmap이 아니므로 호출이 O(1)이 아님!!
>> 2) 자동정렬 
> 구조체를 데이터로 사용시 구조체 안에는 operator()가 필수 (이건 아직 모름. 필요할때 찾아보기. 위의 링크참고)
> 선언및 함수 사용예시
~~~cpp
map<string,int> m; // key, value 순서
m.insert(make_pair("abc",123)); // 삽입시 pair 클래스 이용
m.insert({"bcd",456});
m.erase(m.begin()); // erase와 반복자를 이용해 데이터삭제
m.find("abc"); // 찾은 후 반복자를 반환. 찾는값이 없을 경우 end()를 반환
//아래와 같이 접근이 가능함
cout<<m["bcd"]; // "bcd"라는 키가 있으면 해당키의 value반환
~~~

* multimap 과 multiset
> set과 map에서는 중복된 키값이 들어올때 무시가 되었다면 멀티맵과 멀티셋은 중복값을 허용.
> map의 경우 중복된 키값을 그냥 find()를 통해 호출하면 중복된 키값에 해당하는 value아무것중 하나가 반환됨.
> 따라서 multimap과 multiset은 equal_range()라는 함수를 제공한다.
>> 사용예시
~~~cpp
// 키값이 5인 원소탐색하여 변수에 pair로 반환. first에는 중복값의 시작위치 반복자, second에는 끝위치 반복자가 저장되어 있음
auto mer = m.equal_range(5); 
for(auto it = mer.first; val!=mer.second; val++){
    cout<<it->first<<it->second<<' ';
}
~~~
> 그냥 vector로 저장한 후 sort(), equal_range(), distance()를 이용할 수 있는 상황이면 vector쓰는게 더빠름
>> stl sort가 퀵소트 기반이기때문

* unordered_set과 unordered_map
> C++11에 추가된 비교적 최근에 나온 컨테이너임
> unordered_map, unordered_multimap
> unordered_set, unordered_multiset
* 반복자로 출력시 정렬된 순서도 아닌 원소를 넣은 순서도 아닌 랜덤한 순서로 출력이 됨
* insert(), erase(), find()는 O(1)의 시간복잡도를 가짐
* 위의 unordered 컨테이너들은 Hash function(해시함수)의 자료구조를 가지고 있음
> 해시함수는 처음부터 많은 개수의 상자(메모리)를 사용할 수 없기 때문에(메모리낭비) 상자의 개수는 삽입되는 원소가
> 많아 질 수록 점진적으로 늘어남

> 해시함수의 상자 개수가 바뀌는 경우: 해시함수를 바꿔야 하기 때문에 모든 원소들을 처음부터 끝까지 다시 insert하게됨
> 이는 rehash라고 하며 O(N)을 필요로함

> 때문에 보통의 경우에는 그냥 안전하게 맵이나 셋을 사용, 만약에 최적화가 매우 필요한 작업일 경우에
> 해시 함수를 잘 설계(크기를 잘 설정)해서 unordered_set 과 unordered_map 을 사용


* <summary>

> 데이터의 존재 유무 만 궁금할 경우 → set
> 중복 데이터를 허락할 경우 → multiset (insert, erase, find 모두 O(logN). 최악의 경우에도O(logN))

> 데이터에 대응되는 데이터를 저장하고 싶은 경우 → map
> 중복 키를 허락할 경우 → multimap (insert, erase, find 모두 O(logN). 최악의 경우에도 O(logN))

> 속도가 매우매우 중요해서 최적화를 해야하는 경우 → unordered_set, unordered_map
> (insert, erase, find 모두 O(1). 최악의 경우엔 O(N) 그러므로 해시함수와 상자 개수를 잘 설정해야 한다!: why O(N)? -> 위설명 참고)


**************************************************************************************************************************
# 25. postfix/prefix increment(증가) 오버헤드
* postfix increment : it++ (it:반복자)
* prefix increment :  ++it (it:반복자)
* [참고](https://stackoverflow.com/questions/24901/is-there-a-performance-difference-between-i-and-i-in-c)
* 위의 내용을 보면 C++ 클래스의 객체가 아닌 경우에는 postfix/prefix increment에서 퍼포먼스 차이가 존재하지 않음.
* C++ 클래스의 객체일 경우 prefix increment(++it)와 달리 postfix increment(it++)는 해당 객체에 대한 임시 객체를 만드는 과정에서 
    복사 생성자가 호출되어 오버헤드가 발생되는 것으로 보임.

* 결론 : 그냥 prefix increment(++it)사용하자


**************************************************************************************************************************
# 26. equal_range(), distance()
* equal_range(시작, 끝, 탐색값);
> pair로 반환해줌. pair::first 에는 lower_bound, pair::second 에는 upper_bound반환 (타입은 반복자)
* distance(first, last);
> first, last는 반복자가 들어가고 반환값으로는 first와 last사이의 원소개수 반환
> 비교 -> stl의 unique() : 중복제거
>>        stl의 equal_range(): 중복길이 확인

1. 사용예시
~~~cpp
auto it = equal_range(sb.begin(), sb.end(), i);
ans += distance(it.first, it.second);
~~~


2. 시간복잡도
> std::equal_range()
>> 2*log2(n)) + O(1) 만큼 비교 (lower,upper bound비교에 log2(n)번씩 2번)
>> 랜덤액세스가 불가한 경우 시간복잡도는 2*N (lower,upper bound비교에 n번씩 2번)

> multiset::equal_range()
>> std::equal_range()와 같은 log2(n)  (multimap도 동일한 시간복잡도)

> std:: distance()
>> 랜덤액세스가 가능한 경우 O(1), 불가한 경우 O(n)



**************************************************************************************************************************
# 27. size()는 unsigned 형태로 반환되기 때문에 v.size()-1 같은 코드는 사용하지 말아야한다.
> v.size()-1 에서 size가 0일경우 v.size()에서 반환되는 값은 unsigned 자료형이기때문에 -1 계산시 엄청 큰 수가 나옴
> 예시)

~~~cpp
vector<int> v(0);
auto val = v.size();
val -=1;
cout<<val;
// val은 unsigned int이기때문에
// 출력값은 4294967295(unsigned int으로 MAX값)이 출력됨.
~~~



**************************************************************************************************************************
# 28. max(), min(), min_element(), max_element() 함수
> max() or min() 함수를 이용하여 max({a,b,c,d}) 이렇게 다수의 항을 {}로 max 또는 min값 반환 받을 수 있음
> 배열 or 컨테이너의 경우 min_element() or max_element()를 이용
>> int max = *max_element(v.begin(),v.end());
>> max_element()함수는 vector의 경우 반복자, 배열의 경우 포인터를 반환함



**************************************************************************************************************************
# 29. 시간 단축을 위한 다양한 방법 중 Pragma관련
> [휘님블로그](https://justicehui.github.io/etc/2019/08/29/Optimization/)

> 아래의 1,2,3은 "O2"보다 항상 빠른것이 아님.

1. #pragma GCC optimize("O3")
> 대부분의 온라인저지는 O2를 이용
> 메모리를 늘려서 최적화를 시킴
> 소스의 왜곡이 발생할 수 있다.

2. #pragma GCC optimize("Ofast")
> O3에서 사용하는 최적화에 몇가지 추가적인 최적화를 더 사용한다.
> 아슬아슬하게 TLE가 나면 Ofast넣어보자.

3. Loop Unrolling
> Loop Unrolling (또는 Loop Unwinding) 은 프로그램의 loop 로직을 조금 수정함으로써 속도를 향상시킬 수 있는 방법이다.
> loop 안의 내용을 일부 수작업으로 늘어놓는 일을 해야 하는데 이때 바이너리 코드가 약간 커질 수 있다. 즉 space 를 소비하여 time 을 절약
> Loop Unrolling 은 본문의 내용이 간략할 수록 효율이 좋아지게 된다.
> [LoopUnrolling](http://z3moon.com/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D/loop_unrolling)


**************************************************************************************************************************
# 30. 초기화는 할 수 있다면, -1로 하는것보다 0으로 하는것이 더 빠르다


**************************************************************************************************************************
# 31. 숏코딩 - 초기화
ex)
~~~cpp
int arr[15]{};
// 모든항 0으로 초기화

char str[2000]{};
// 모든항 '\0'으로 초기화
~~~
> 큰 크기의 배열을 초기화 하는경우,
>> memset이 가장 빠름
>> 그 다음 assign이 빠르고 , 그 다음 for문이 빠름
>> memset(str,'a',sizeof(str)) -> (char는 1byte라서 가능)



**************************************************************************************************************************
# 32. 최대값, 최소값 초기화 방법
~~~cpp
const int INF = 1e9;
int MIN = INF;
int MAX = -INF; // -INF하는거 꿀팁
~~~


**************************************************************************************************************************
# 33. sort()와 priority_queue의 비교연산 부등호
> 아래의 comp1을 통한 sort는 오름차순,
> 아래의 comp2를 통한 우선순위큐는 최대힙으로 내림차순의 결과를 보임
>> 우선순위큐의 비교연산은 (a < b)가 참인경우 swap한다고 인식.
>> 정렬로 생각할때 둘은 반대의 결과를 보인다고 생각하기.
> 우선순위 큐는 따로 operator안만들면 기본적으로 max heap임.
>> greater<int> 넣으면 min heap임.
> sort()에 greater<int>() 넣으면 내림차순임 -> 즉, 이것도 반대로 인식

~~~cpp
#include<bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()

vector<int> v(10);
bool comp1(int &a, int &b){
    return a<b;
}
struct comp2{
    bool operator()(int &a, int &b){
        return a<b;
    }
};

priority_queue<int, vector<int>, comp2> pq;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0; i<10; i++) v[i] = i+1;
    for(int i=0; i<10; i++) pq.push(v[i]);
    sort(all(v),comp1);

    for(int i=0; i<10; i++) cout<<v[i]<<' ';
    cout<<'\n';
    while(!pq.empty()){
        cout<<pq.top()<<' ';
        pq.pop();
    }
}
~~~



**************************************************************************************************************************
# 34. 피보나치
> 점화식 : dp[i] = d[i-2] + d[i-1];
> 46번째수는 2971215073으로 int범위를 초과함


**************************************************************************************************************************
# 35. 비트연산

~~~cpp
// or연산 예시
int flag = 0;
flag |= 1;
cout<<flag<<' ';
flag |= 2;
cout<<flag<<' ';
flag |= 4;
cout<<flag<<' ';
// 실행결과 : 1 3 7

// and연산 예시
int n1 = 5;
if(n1&1) cout<<"odd"<<' ';
int n2 = 10;
if(!n2&1) cout<<"even";
// 실행결과 : odd even
// 위와 같이 if(n&1)... 를 통해 2의 배수(짝수)인지 아닌지 알 수 있음.
~~~

> 비트마스크에서 더 알고 싶다면? [코딩도장출처](https://dojang.io/mod/page/view.php?id=184)


**************************************************************************************************************************
# 36. 쿼리 개수 입력되는 대로 받기 (EOF: cin이용)
> 예시)
~~~cpp
while(true){
        cin>>N>>M;
        if(cin.eof())break; // 위의 cin에서 입력값이 없으면 종료됨.
        cin>>arr[..]...
        ....
    }
    
// 또는

while(cin>>N){
    ......
}
~~~


**************************************************************************************************************************
# 37. 실수자료형(double, flaot) 
- double과 float의 차이점
> double이 float보다 정확도 2배

> float: 32비트
>> 지수길이: 8비트, 가수길이: 23비트
>> 소수 부분 7자리까지 오차없이 표현할 수 있음.

> double: 64비트
>> 지수길이: 11비트, 가수길이: 52비트
>> 소수 부분 15자리까지 오차없이 표현할 수 있음.


- 주의할점: [출처](https://www.acmicpc.net/blog/view/37)
> 1. float보다는 double형 변수를 사용하는것이 좋음(정확도 때문)
> 2. 정수가 들어있는 실수형 변수를 정수로 바로 캐스팅하면 안됨
>> ex) 1을 double 변수에 대입하면 0.9999... 같은 이상한 숫자. 이 변수를 그대로 정수로 캐스팅한다면 0이 됨
>>     보통의 경우에는 1e-6 ~ 1e-9 정도를 더해서 캐스팅하거나 정수형 변수만을 사용하여 연산
> 3. 비교 연산을 할 때는 등호사용X
>> 보통의 경우에는 abs(A-B) < EPS, EPS는 1e-6~1e-9 정도로 정함.
> 4. ..... 이해못함


**************************************************************************************************************************
# 38. long long, int 범위
> 2^32 = 4.29e+9(대략)
> 2^64 = 1.84e+19(대략)

> int형: 대략 -21... ~ 21... -> 10자리
> ll 형: 대략 -92... ~ 92... -> 19자리


**************************************************************************************************************************
# 39. RB tree (Red-Black Tree)의 시간복잡도
> set,map의 함수들은 시간복잡도가 기본적으로 log(n)이지만 
> RB-tree의 시간복잡도의 상수가 매우 커서 데이터가 많으면 시간초과가 날 수 있으므로
> 데이터를 적절히 분산할 필요가 있음 ->  ex) <정사각형> BOJ_9015


**************************************************************************************************************************
# 40. memset
> string.h에 있는 memory.h헤더에 포함되어 있다.
> memset에 초기화값을 넣어주면 1byte단위로 초기화 시키기때문에
> memset(adj,0x3f,sizeof(adj)); 와 같이 초기화할때 adj가 int라면,
> int의 4바이트에서 각비트당 0x3f를 할당하여 0x3f3f3f3f의 값이 int에 들어감
> 추가로, 0x3f3f3f3f: 약 10억6천 // 0x7f7f7f7f: 약 21억4천 // 0x01010101: 약 1680만
> 따라서 memset의 초기화수로 INF=0x3f정도가 적당(INF+INF까지 가능)
> -INF로 초기화 하려면 ? : '0xc0'으로 초기화
> long long 인 배열의 경우에도 memset(arr,0x3f,sizeof(arr)); 또는 0xc0(-INF인경우)로 초기화 해도 됨
> 최소값이 0x7f7f7f7f를 넘어갈 수 있는경우 0x3f3f3f3f사용 ex-> 플로이드와샬의 경우 adj[i][k]+adj[k][j] < adj[i][j]비교 같은거


**************************************************************************************************************************
# 41. 직사각형 4번째점 구하기
> 점3개가 주어졌을때, 4번째 점의좌표(x,y) =?
> x=(x1^x2^x3) , y=(y1^y2^y3)



**************************************************************************************************************************
# 42. inline 함수
- <오버헤드>
~~~
작은 크기의 함수를 호출하면, 함수 실행 시간에 비해,
호출을 위해 소요되는 부가적인 시간 오버헤드가 상대적으로 크다.
따라서 작은 크기의 함수를 많이 호출하게 되면( ex) 10000번) 오버헤드가 커져 프로그램의 속도가 떨어짐
그래서 필요한것이 inline함수
~~~
> 오버헤드로 인한 프로그램의 실행속도 저하를 막기 위해 도입된 기능
> 컴파일러는 인라인 함수를 호출하는 곳에 인라인 함수 코드를 그대로 삽입하여 함수 호출이 일어나지 않게 한다.
>> 매크로와 유사함.
>> 코드 확장 후 인라인 함수는 사라짐
> 함수 호출에 따른 오버헤드가 존재하지 않음

> 단점 ? : 함수호출이 빈번할수록 컴파일된 전체 코드 크기가 증가함
>> 통계적으로 최대30%증가.
>> 따라서 짧은 코드의 함수를 인라인처리하는것이 좋음



**************************************************************************************************************************
# 43. PI선언과 출력(with 소수점 출력방법)
> 아래와 같이 선언하여 PI선언
> const double PI = acos(-1);
> 소수점 출력방법 코드 예시

~~~cpp
const double PI = acos(-1)
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    double k = 123456.123456789;

    cout.precision(8); // 유효숫자(정수+소수) 8자리까지 출력(반올림 됨.)
    cout<<k<<'\n';
    cout<<fixed; // 소수점 고정( precision(8)이므로 소수점 8자리까지 출력한다는뜻. 반올림 됨.)
    cout<<k<<'\n';
    cout<<PI;
}
/* 출력 결과 */
// 123456.12
// 123456.12345679
// 3.14159265
~~~



**************************************************************************************************************************
# 44. push_back()과 emplace_back() 차이점
> L-value, R-value란 ? ex)
~~~cpp
string a = "abc"; // 여기서 =의 왼쪽에 있는 a는 L-value, 오른쪽에 있는 "abc"는 R-value
string b = a;     // 여기서는 b,a둘다 L-value
~~~
> 즉, R-value는 한번 쓰고 다시 안쓰는 변수(temporary, 코드에서 "abc")
>     L-value는 callable 변수(재정의 될 수 있는 변수임).
> 따라서 R-value를 push_back()하면 copy, L-value를 push_back()하면 move가 수행됨.


> cpp레퍼런스 정보 
>> std::vector<T,Allocator>::push_back 의 오버로딩 프로토타입
>> 1. void push_back(const T& value); -> 인자로 L-value
>> 2. void push_back(T&& value);      -> 인자로 R-value
>> 

* <정리>
> push_back()
>> L-value 레퍼런스가 들어오면 copy수행
>> R-value 레퍼런스가 들어오면 move(c+11부터)를 수행

> emplace_back()
>> 1. L-value: copy 수행
>> 2. R-value: move 수행
>> 3. 백터내에 move없이 바로 오브젝트를 생성하는것이 가능(construct) 
>>> ex) v.emplace_back(Info(dis,dir,y,x));
>> 속도: 3->2->1 순으로 3이 가장 빠름

* 결론 : emplace_back()만 쓰면 됨(가장 빠름)
* 참고동영상 : [push_back, emplace_back 차이](https://m.blog.naver.com/sorkelf/220825930008)



**************************************************************************************************************************
# 45. lower_bound() , upper_bound()
> lower_bound(v.begin(), v.end(), val, comp);
> upper_bound(v.begin(), v.end(), val, comp);

>> lower_bound : 이상 값
>> upper_bound : 초과 값

~~~cpp
int arr[10] = {1,2,3,3,3,4,6,6,6,10};
int val1 = lower_bound(arr,arr+10, 3) - arr;
int val2 = upper_bound(arr,arr+10, 3) - arr;
cout<<val1<<' '<<val2;

// 출력: 2 5
~~~


**************************************************************************************************************************
# 46. 2의 제곱수 판별 (정수로)
> if(n&(n-1)==0) 이면 n은 2의 제곱수
> 단, 0과 -1은 and하면 0나옴.



**************************************************************************************************************************
# 47. 비트마스킹
> 출처: https://mygumi.tistory.com/361
> 비트: 0 or 1
> 비트의 표현 ex)
~~~
{ 0, 1, 2, 3, 4 } => 11111
{ 1, 2, 3, 4 } => 11110
{ 1, 2, 4 } => 10110
{ 2, 4 } => 10100
{ 1 } => 00010
~~~

> 비트연산 : AND, OR, XOR, NOT, SHIFT
>> 1. AND : &
>> 1010 & 1111 = 1010
>> 2. OR : |
>> 1010 | 1111 = 1111
>> 3. XOR : ^
>> 1010 ^ 1111 = 0101
>> 4. NOT : ~
>> ~1010 = 0101
>> 5. SHIFT : >>, <<
>> 00001010 << 2 = 101000
>> 00001010 >> 2 = 000010 
>> 왼쪽 시프트는 A * 2^B 를 의미하고, 오른쪽 시프트는 A / 2^B 를 의미 (곱,나눗셈)


> 비트연산의 활용
>> 1. i번째 비트의 값을 1로 변경하는 방법 (i번째 비트에 1넣기)
>> 1010 | 1 << i
>> 즉, S |= (1 << j)

>> 2. i번째 비트의 값을 0로 변경하는 방법 (i번째 비트값 지우기)
>> 1110 & ~(1 << i)
>> 즉, S &= ~(1 << i)

>> 3. i번째 비트의 값을 알 수 있는 방법
>> 2번째 비트 ex - 1010 & (1 << 2) = 1010 & 0100 => 0
>> 3번째 비트 ex - 1010 & (1 << 3) = 1010 & 1000 => 1000
>> 즉 result != 0 이면 i번째는 1, result == 0 이면 i번째는 0

>> 4. N자리의 최대 이진수
>> (1 << N ) - 1

> 문제풀이 적용ex : BOJ_2098 외판원 순회(TSP 웰논)



**************************************************************************************************************************
# 48. P문제와 NP문제(NP-hard)
> https://wkdtjsgur100.github.io/P-NP/



**************************************************************************************************************************
# 49. for문에서의 earse iterator
> for문에서 해당 it를 지우게 되면 다음iterator(it++)를 인식하지 못함.
> lst.erase(it++)를 사용하면 미리 iterator를 복사하고 earse를 호출하기 때문에 깔끔하게 코딩가능

~~~cpp

map<int,set<int>> m;
set<int>::iterator tmp;

for(auto it = m.begin(); it != m.end(); ){ // ++it를 for문 조건에 넣지않음
    tmp = it->yy.begin();
    ans.push_back(*tmp);
    it->yy.erase(tmp++);
    
    // it++로 넣으면 반복자 복사를 먼저하고 erase하기 때문에 지우고 나서도 다음반복자 참조가능
    if(it->yy.size()==0) m.erase(it++); 
    else ++it; // 지우는게 아니라면 다음반복자를 참조 할 수 있도록 함
}
~~~


**************************************************************************************************************************
# 50. 람다식
> [참고](https://modoocode.com/196)

~~~cpp
//[개시자](파라미터) -> (type)반환 {코드}
[&](int i) -> int{return i}
~~~

> 예시
~~~cpp
sort(++v.begin(), v.end(), [&](Point a, Point b) -> bool {
    int ret = ccw(v[0], a, b);
    return ret > 0  || (ret==0 && a < b);
});
~~~


**************************************************************************************************************************
# 51. 언어별 입력속도 비교
[입력 속도 비교](https://www.acmicpc.net/blog/view/56)

~~~
순위 언어   입력방법                                                     속도
------------------------------------------------------------------------------
1	 C11	mmap                                                        0.043
2	 C11	fread                                                       0.0799
3	 C11    getchar	                                                    0.3496
4	 C++17	ios_base::sync_with_stdio(false); cin.tie(NULL);            0.5938
5	 C++17	ios_base::sync_with_stdio(false);                           0.6348
6	 Java	BufferedReader, Integer.parseInt                            0.6585
7	 C11	scanf                                                       0.9206
8	 PyPy	int(sys.stdin.readline())                                   0.9229
9	 PyPy	map(int,os.read(0, 100000000).split('\n'))                  1.1169
10	 PyPy3	map(int,os.read(0, 100000000).decode('utf-8').split('\n'))  1.5408
~~~

**************************************************************************************************************************
# 52. Segment Tree 참고링크

[Classic Segment Tree](http://codeforces.com/blog/entry/15890)
[Efficient Segment Tree](http://codeforces.com/blog/entry/18051)
[Data Structures](http://codeforces.com/blog/entry/15729)


**************************************************************************************************************************
# 53. 다익스트라

> "다익스트라는 음수 간선이 하나라도 존재하면 종료를 보장할 수 없습니다. 이는 사이클의 존재 여부와 관련이 없습니다."
> 이 명제는

> "max-heap으로 구현한 최장 경로 다익스트라는 양수 간선이 하나라도 존재하면 종료를 보장할 수 없습니다. 
> 이는 사이클의 존재 여부와 관련이 없습니다."

> 와 동치입니다.

**************************************************************************************************************************
# 54. 그래프를 이용한 알고리즘

> 최단거리 - 플로이드와샬, 다익스트라, 벨만포드
>> 다익스트라 알고리즘(Dijkstra Algorithm) : 한점 - 다수의점 (음수가중치X)
>> 벨만-포드 알고리즘(Bellman-Ford Algorithm) 한점 - 다수의점 (음수사이클X)
>> 플로이드-워셜 알고리즘(Floyd-Warshall Algorithm) 모든점 - 모든점

> 양방향 간선 = 사이클이 존재함

> 방향 비순환 그래프(directed acyclic graph, DAG)
>> DAG라고 부르며 **위상정렬** 이 있는 유향 그래프 라고 볼 수 있음.

**************************************************************************************************************************
# 55. 배열 or 벡터의 합(sum) std 함수
> std 함수 accumulate 사용

~~~cpp
// 아래 예시는 벡터지만, 배열도 가능 
// ex) int sum = accumulate(m, m+N, 0);

vector<int> v = { 1'000'000'000, 2'000'000'000 };
long long sum = accumulate(v.begin(), v.end(), 0LL); // 0LL은 초기화 값 (0부터 더함)
cout << sum << '\n';	
//출력: 3'000'000'000

~~~

**************************************************************************************************************************
# 56. Stable / Unstable sort
> 같은 key값을 가진 노드들에 대하여, 정렬이 수행된 후 순서가 유지가 되는가 ? : 되면 stable
> `선택`, `힙`, `퀵` -> Unstable 정렬
> 따라서 priority_queue도 Unstable 함
> 합병, 삽입, 버블 -> Stable

**************************************************************************************************************************
# 57. 함수에서 배열의 call by reference
> 잘못 알고 있었던 사실 -> 함수에서 아래와 같이 매개변수로 사용하면 call by reference임
> 백터는 ? -> void func(vector<int> &t){} 와 같이 &를 붙여서 사용

~~~cpp
#include<iostream>
using namespace std;

int m[101]{};

// 2차원배열은 arr[][N]
void func(int arr[]) {
    for (int i = 0; i < 5; i++) 
        arr[i] += 10;
}

int main() {
    for (int i = 0; i < 10; i++) m[i] = i + 1;
    for (int i = 0; i < 10; i++) cout << m[i] << ' ';
    cout << '\n';
    func(m);
    for (int i = 0; i < 10; i++) cout << m[i] << ' ';
}

// 출력
/*
1 2 3 4 5 6 7 8 9 10 
11 12 13 14 15 6 7 8 9 10
*/
~~~

**************************************************************************************************************************
# 58. 트리의 성질
> N개의 노드중 끊어진 그래프가 없고 간선이 모두 양방향일때,
> 아래의 조건중 하나에 해당된다면 해당 노드들은 트리구조를 가짐

1. 간선이 N-1개 있음
2. 사이클이 없음

**************************************************************************************************************************
# 59. 희소 테이블 (sparse table)
> 2의 거듭제곱인 범위의 구간값을 미리 계산(전처리)
> ex) O(logN)으로 탐색하는 LCA 코드 참고

**************************************************************************************************************************
# 60. 오프라인 알고리즘
> 오프라인 알고리즘은 풀고자 하는 문제의 모든 데이터를 가지고 시작해야만 문제를 해결
> ex) 병렬이분탐색 - 오프라인 쿼리를 이용 - [크루스칼의 공](https://www.acmicpc.net/problem/1396)


**************************************************************************************************************************
# 61. 산술, 비트 연산 속도
> 연산자 속도를 이용하여 시간복잡도 최적화에 큰 기여를 할 수 있는것은 아니지만 굳이 속도를 따져본다면,
>> 가장 간단한건 and, or, 비교연산
>> 그다음이 덧셈, 뺄셈, shift가 되며
>> 가장 복잡한 것이 곱셈, 나눗셈, MOD 연산.
>> 위의 연산중에서 나눗셈이 가장 무거움

**************************************************************************************************************************
# 61. DFS
> N이 10 이하인 경우 10!의 시간복잡도로 1초안에 들어옴

**************************************************************************************************************************
# 62. 그래프, 다익스트라 활용
1. 역방향 간선 그래프
> 단방향 간선 그래프에서 간선의 방향을 모두 역으로 저장한 후
> 한 노드 x에서 다른 노드까지의 최단거리를 구하면
> 모든 노드로들부터 노드 x까지의 최단거리를 구할 수 있다.
> 양방향 그래프 경우에는 역방향으로 저장안해도 위 내용이 성립

2. 시작점이 여러개인 다익스트라 알고리즘
> 시작점 여러개를 pq에 저장하고 다익스트라를 통해 얻은 최단거리정보는
> 어떤 시작점에서 출발하여 얻은 최단거리인지 알 수는 없다.
> 모든 시작노드들을 하나의 큰 집합노드라고 생각한다면,
>> '집합노드'로부터 다른 노드들까지의 최단거리 를 구할 수 있다.
>> 다른 노드들 중에서 '집합노드'로부터 가장 멀리 떨어져 있는 노드를 구할 수 있다. -> BOJ_17835, BOJ_5542

**************************************************************************************************************************
# 63. multimap과 priority_queue
> multimap/multiset을 priority_queue처럼 사용할 수 있다.
> 하지만 prioirty_queue가 더 빠른 성능을 보인다.
> multimap/multiset을 사용하면 min, max값을 같이 뽑아낼 수 있다는 장점이 있음

**************************************************************************************************************************
# 64. XOR 연산 (^)
> 수a에 k를 XOR연산할때 k를 짝수번 XOR하면 a가, 홀수번 XOR하면 a^k가 나옴
> ex1) a^a = 0,   a^0 = a
> ex2) a^k^k = a, a^k = a^k

~~~cpp
int main(){
    cout<<(2^4^7)<<' ';
    cout<<((2^4^7)^12)<<' ';
    cout<<((2^12)^(4^12)^(7^12))<<'\n';
    // 1 13 13

    cout<<(2^4^7^8)<<'\n';
    cout<<((2^4^7^8)^12)<<'\n';
    cout<<((2^12)^(4^12)^(7^12)^(8^12))<<'\n';
    // 9 5 9
}
~~~

**************************************************************************************************************************
# 65. 모듈러 연산 (음수조심)
> [BOJ_1280](https://www.acmicpc.net/problem/1280) 문제 이슈

> 모듈러 연산은 덧,뺄,곱에 대하여 모두 분배법칙이 성립하지만
> 뺄셈으로 인해 음수가 나올 수 있기 때문에 아래의 식은
> total = ((lcnt*t)%MOD - (lsum)%MOD)%MOD;
> total = ((total + rsum)%MOD - (rcnt*t)%MOD)%MOD;
> res = (res * total)%MOD;

> 아래와 같은 식으로 사용하는것이 옳다
> total = ((lcnt*t) - (lsum))%MOD;
> total = ((total + rsum) - (rcnt*t))%MOD;
> res = (res * total)%MOD;

> 또한, 위의 식에서 lcnt, total, rsum을 구하는 과정에 MOD가 있다면
> 그 값이 MOD연산에 의해 작아지고 뒤의 -연산에 의해 음수가 될 수 있기 때문에
> ltotal = ((lcnt*t) - lsum)%MOD;
> rtotal = (rsum - (rcnt*t))%MOD;
> total = (ltotal + rtotal)%MOD;
> res = (res * total)%MOD;

> 이렇게 식을 세우는 것이 옳고, lcnt, rsum을 구하는 식에서도 MOD연산을 빼주는것이 좋음