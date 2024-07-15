# 알고리즘 & 자료구조
> 공부했던 알고리즘들의 특징 및시간복잡도 정리

<br><br>


## 알고리즘

### 분류
1. Graph
2. Tree
3. String
4. Math
5. DP
6. Geometry
7. Query
8. Sort
9. The others

<br>

### 1. Graph
* BFS, DFS
  * 인접리스트 이용시 : $O(V+E)$
  * 인접행렬 이용시 : $O(V^2)$
* 0-1 BFS
  * 가중치가 0 or 1 일때 사용 할 수 있는 최단경로 알고리즘
* Floyd-Warshall - $O(V^3)$
* Dijkstra
  * 최단거리 -> min-Heap, 그리디, DP 이용
  * $O(V\log{V})$ + $O(E\log{V})$ = $O((V+E)\log{V})$
* Bellman-Ford : $O(NE)$
* Topology Sort
  * 방향 비순환 그래프 (directed acyclic graph - DAG)
  * $O(V+E)$
* MST(Minimum Spanning Tree)
  * Prim : $O(N^2)$ (N은 정점의 개수, min-Heap 이용)
  * Kruskal : $O(E\log{E})$ (E는 간선의 개수, 퀵정렬, Union-Find 이용)
* Network Flow
  * Maximum Flow : $O(VE^2)$ (Edmonds-Karp 알고리즘)
  * 이분매칭(Bipartite Matching) : $O(VE)$
* SCC : todo

<br>

### 2. Tree
* Tree Order - $O(N)$ : pre, in, post
* Binary Search Tree : $O(\log{N})$
* LCA
  * $O(\log{N})$
  * sparse table(희소배열) 이용
* Segment Tree
  * Init : $O(\log{N})$, 공간복잡도 - 4N(재귀), 2N(비재귀)
  * 값 update : $O(\log{N})$
  * 구간쿼리 : $O(\log{N})$
* BIT(Binary Indexed Tree : Fenwick)
  * Init : $O(\log{N})$, 공간복잡도 N
  * 값 update :  $O(\log{N})$
  * 구간쿼리 :  $O(\log{N})$
  * segment tree보다 상수값이 작아서 빠름 
* Heavy Light Decomposition(HLD) : todo

<br>

### 3. String
* manacher
  * Palindrome 문자열 찾기
  * $O(N)$
* Trie
  * $O(M)$ : 문자열의 길이 M
  * $O(M\log{N})$
* KMP : $O(N+M)$
* Aho-Corasick : $O(N+M1+M2+..+Mk)$

<br>

### 4. Math
* 유클리드 호제법
* 에라토스테네스의 체
  * 소수(prime number)찾기
  * 소인수분해
* Euler Pi 함수
* Pollard-Rho
  * 소인수분해 알고리즘

<br>

### 5. DP
* DP의 시간복잡도는 일반적으로 캐싱 배열의 크기와 같음
* LCS (Longest Common Subsequence)
* LIS (Longest Increasing Subsequence)
  * 브루트포스로 구현 - $O(N^2)$
  * 이분탐색 or 세그트리로 구현 - $O(N\log{N})$
* Bitmask DP
  * 비트연산 : $O(1)$
  * mask에서 1bit , 0bit 탐색이나 업데이트 모두 $O(1)$로 처리함
  * mask(비트필드)를 이용한 DP으로 많이 활용

<br>

### 6. Geometry
* ccw : $O(1)$
* 다각형의 넓이 : $O(N)$ - 점의개수 N
* 선분 교차판정
* 볼록다각형의 내부점 판별
  * 볼록다각형 점이 X개이고 판별할 점이 Y개일때
    * upper hull, lower hull을 이용하면 - $O(Y\log{X})$
* Convex Hull(Graham Scan 이용)
  * 정렬 : $O(N\log{N})$
  * Scan : $O(N)$
  * 총 시간복잡도 $O(N\log{N})$
* Rotating Calipers
  * 볼록 다각형의 지름 구하기
  * Convex Hull, 정렬 : $O(N\log{N})$
  * 지름 구하는 과정 : $O(N)$
  * 총 시간복잡도 : $O(N\log{N})$

<br>

### 7. Query
* Segment Tree
  * lazy seg, BIT, Merge Sort Tree 와 같은 알고리즘 모두 Query문제에서 효과적인 알고리즘
* Parallel Binary Search(PBS)

<br>

### 8. Sort
* Bubble Sort : $O(N^2)$, Stable
* Insertion Sort : $O(N^2)$, Stable
* Selection Sort : $O(N^2)$, Unstable
* Merge Sort : $O(N\log{N})$, Stable
* Heap Sort : $O(N\log{N})$, Unstable
* Quick Sort : $O(N\log{N})$, Unstable
* Radix Sort : $O(dN)$, Stable
  * d - 가장 긴 숫자의 길이
* counting Sort : $O(N)$, Unstable
  * prefix sum 이용하면 Stable

<br>

### 9. The Others
* TSP - 외판원 순회
  * 마스크 탐색 : $O(2^N)$
  * 마스크에서 - 현재노드 탐색:$O(N)$ * 이전노드 탐색:$O(N)$ = $O(N^2)$
  * 총 시간복잡도 : $O(2^N * N^2)$
* Two Pointer, Sliding Window : $O(N)$
* Prametric Search 
  * 이분탐색 이용
  * $O(\log{N})$

<br><br>

## 자료구조
* Array
  * Create Update Delete - $O(N)$
  * Read - $O(1)$
    * 캐시히트율에 따라 다름
    * 배열 크기가 커질수록 느려짐
    * C++17 기준 배열 크기 500만 이상이면 느려짐
* List
  * Create Update Delete - $O(1)$
  * Read - $O(N)$
* Stack
  * LIFO  
  * push, pop : $O(1)$
* Queue
  * FIFO  
  * push, pop : $O(1)$
* Deque
* 이진 Heap
  * MAX Heap, Min Heap
  * 이진트리로 구현
  * push & pop : $O(\log{N})$
* Priority Queue
  * Heap 구조를 가짐  
  * push - $O(\log{N})$, pop - $(1)$
* Union_find
  * Union 함수를 최적화 하면 (높이가 낮은 트리를 높은 트리 밑에 들어가도록)
  * Find  : $O(\log{N})$
  * Union : $O(\log{N})$ 로 볼 수 있지만 (트리 이기때문)
  * N이 $2^{65536}$ 이하일때 아커만 함수$𝛼()$ 에 의하면 값이 5 미만이므로 상수 시간복잡도를 가짐
  * Find, Union : $O(𝛼(N))$ = $O(1)$
