# *알고리즘 & 자료구조 시간복잡도*

**************************************************************************
## 알고리즘

### 분류
1. Graph Theory
2. Tree
3. Math
4. Geometry
5. Sort
6. The others

#### 1.Graph Theory
* BFS, DFS
> 인접리스트 이용시 : O(V+E)
> 인접행렬 이용시 : O(V^2)

* Floyd-Warshall
> 정점개수 V : O(V^3)

* Dijkstra 
> 최단거리-> min-Heap, 그리디, DP 이용
> O(VlogV) + O(ElogV) = O((V+E)logV)

* Bellman-Ford

* MST(Minimum Spanning Tree)
> Prim : O(N^2) (N은 정점의 개수, min-Heap 이용)
> Kruskal : O(NlogN) (N은 간선의 개수, 퀵정렬, Union-Find 이용)

* TSP
> O(2^N * N^2)
> 마스크 탐색 : 2^N
> 마스크에서 -> 현재노드 탐색N * 이전노드 탐색N = N^2

* SCC

#### Tree
* Binary Search Tree
> O(logN)
* Tree Order
* LCA
* Segment Tree
> 

#### Geometry
* Convex Hull(Graham Scan 이용)
> 정렬 : O(NlogN)
> Scan : O(N)

#### Sort
* Bubble : O(N^2), Stable
* Insertion : O(N^2), Stable
* Selection : O(N^2), Unstable
* Merge : O(NlogN), Stable
* Heap : O(NlogN), Unstable
* Quick : O(NlogN), Unstable

* Radix : O(dN), Stable
> d = 가장 긴 숫자의 길이
* counting : O(N), Unstable
> prefix sum 이용하면 Stable

#### The Others
* Two Pointer, Sliding Window
> O(N)

* Prametric Search & Binary Search
> O(logN)

* LIS
> 이분탐색 or 세그먼트 트리 이용
> O(NlogN)

* Bitmask
> O(1)
> mask에서 1bit , 0bit 탐색이나 업데이트 모두 O(1)로 처리
> mask(비트필드)를 이용한 DP으로 많이 사용함

**************************************************************************
## 자료구조
* Stack
> LIFO : O(1)

* Queue
> FIFO : O(1)

* Priority Queue
> Heap 구조
> push -> O(logN), pop -> O(1)

* Union_find
> Union 함수를 최적화 하면 (높이가 낮은 트리를 높은 트리 밑에 들어가도록)
> find  : O(logN)
> Union : O(logN) 로 볼 수 있지만 (트리 이기때문)
> 실제 시간복잡도 : O(𝛼(N)) -> N이 2^65536 일때, 함수 값이 5 -> O(1)로 봐도 무방

**************************************************************************
### 알고리즘&자료구조 공부 계획
1. new : SCC - Tarjan
2. 복습 : 구현문제
3. new : Bellman-Ford(SPFA로)
4. new : Segment Tree lazy propagation
5. new : 병렬 이분탐색
6. new : Fenwick Tree
7. new : PST (persistent segment tree)
8. 복습 : Trie
9. 복습 : Network Flow
10. new : 이분매칭