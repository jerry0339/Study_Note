# *알고리즘 & 자료구조 시간복잡도*

**************************************************************************
## 알고리즘
> 시간복잡도의 log는 모두 log2(N)

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
> find  : O(lgN)
> Union : O(lgN)


**************************************************************************
### 알고리즘&자료구조 공부 계획
* 진행중 - LCA
1. new : SCC - Tarjan
2. 복습 : TSP, Bitmask
3. new : Bellman-Ford
4. new : Segment Tree lazy propagation
5. new : 병렬 이분탐색
6. new : Fenwick Tree
7. 복습 : Trie
8. 복습 : Network Flow
9. new : 이분매칭