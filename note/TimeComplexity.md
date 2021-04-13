# *알고리즘 & 자료구조 간단 정리*

**************************************************************************
## 알고리즘
> 공부했던 알고리즘들

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

#### 1.Graph
* BFS, DFS
    > 인접리스트 이용시 : O(V+E)    
    > 인접행렬 이용시 : O(V^2)  

* 0-1 BFS
    > 가중치가 0 or 1 일때 사용 할 수 있는 최단경로 알고리즘

* Floyd-Warshall
    > 정점개수 V : O(V^3)   

* Dijkstra 
    > 최단거리-> min-Heap, 그리디, DP 이용  
    > O(VlogV) + O(ElogV) = O((V+E)logV)    

* Bellman-Ford - not yet

* Topology Sort
    > 방향 비순환 그래프(directed acyclic graph-> `DAG`)    
    > O(V+E)    

* MST(Minimum Spanning Tree)
    > Prim : O(N^2) (N은 정점의 개수, min-Heap 이용)    
    > Kruskal : O(NlogN) (N은 간선의 개수, 퀵정렬, Union-Find 이용)   

* Network Flow

* SCC - not yet

#### 2.Tree
* Tree Order
    > preorder postorder inorder    
    > O(N)  

* Binary Search Tree
    > O(logN)   

* LCA
    > O(logN)   
    > sparse table(희소배열) 이용   

* Segment Tree
    > Init : O(logN), 공간복잡도 -> 4N(재귀), 2N(비재귀)    
    > 값 update : O(logN)   
    > 구간쿼리 : O(logN)    

* BIT(Binary Indexed Tree : Fenwick)
    > Init : O(logN), 공간복잡도 -> N   
    > 값 update : O(logN)   
    > 구간쿼리 : O(logN)    
    > segment tree보다 상수값이 작아서 빠름 

* Heavy Light Decomposition(HLD) - not yet

#### 3.String
* manacher
    > Palindrome 문자열 찾기  
    > O(N)  

* Trie
* KMP - not yet
* Aho-Corasick - not yet


#### 4.Math
* 유클리드 호제법
* 에라토스테네스의 체
    > 소수(prime number)찾기, 소인수분해    
* Euler Pi 함수
* Pollard-Rho
    > 소인수분해 알고리즘

#### 5. DP
* Bitmask DP
    > 비트연산 : O(1)   
    > mask에서 1bit , 0bit 탐색이나 업데이트 모두 O(1)로 처리함     
    > 보통 mask(비트필드)를 이용한 DP으로 많이 활용하여 사용함  

* Knuth Optimization
    > 기억안남 -> 파일합치기 2

#### 6.Geometry
* ccw
    > O(1)  

* 다각형의 넓이
    > O(N) -> 점의개수 : N  

* 선분 교차판정

* 볼록다각형의 내부점 판별
    > 볼록다각형 점 N1 개   
    > 판별할 점 N2개 일때   
    > upper hull, lower hull을 이용하여 
    > O(N2*logN1)  

* Convex Hull(Graham Scan 이용)
    > 정렬 : O(NlogN)   
    > Scan : O(N)   
    > 따라서 O(NlogN)   

#### 7.Query
* Segment Tree
    > lazy seg, BIT, Merge Sort Tree 와 같은 알고리즘 모두 Query문제에서 효과적인 알고리즘임    
* Parallel Binary Search

#### 8.Sort
* Bubble Sort : O(N^2), Stable
* Insertion Sort : O(N^2), Stable
* Selection Sort : O(N^2), Unstable
* Merge Sort : O(NlogN), Stable
* Heap Sort : O(NlogN), Unstable
* Quick Sort : O(NlogN), Unstable
* Radix Sort : O(dN), Stable
    > d = 가장 긴 숫자의 길이   
* counting Sort : O(N), Unstable
    > prefix sum 이용하면 Stable    

#### 9.The Others
* LCS(Longest Common Subsequence)

* LIS (Longest Increasing Subsequence)
    > 이분탐색 or 세그먼트 트리 이용    
    > O(NlogN)  

* TSP
    > O(2^N * N^2)  
    > 마스크 탐색 : O(2^N)  
    > 마스크에서 -> 현재노드 탐색:O(N) * 이전노드 탐색:O(N) = O(N^2)  

* Two Pointer, Sliding Window
    > O(N)  

* Prametric Search
    > O(logN)   

**************************************************************************
## 자료구조
* Array, List
* Stack
    > LIFO  
    > push, pop : O(1)  

* Queue
    > FIFO  
    > push, pop : O(1)  

* Deque

* 이진 Heap
    > MAX Heap, Min Heap    
    > 이진트리로 구현됨     
    > push, pop : O(logN)

* Priority Queue
    > Heap 구조를 가짐  
    > push -> O(logN), pop -> O(1)  

* Union_find
    > Union 함수를 최적화 하면 (높이가 낮은 트리를 높은 트리 밑에 들어가도록)   
    > Find  : O(logN)   
    > Union : O(logN) 로 볼 수 있지만 (트리 이기때문)   
    > 실제 시간복잡도 : O(𝛼(N)) -> N이 2^65536 일때, 함수 값이 5 이므로 O(1)로 봐도 무방    
    > Find, Union : O(𝛼(N)) = O(1)  

* Splay Tree - not yet

**************************************************************************
