// <이진 검색 트리> - BOJ_5639
// upper_bound 분할정복을 이용한 Binary Search Tree
// test 케이스에 대하여 분할되는 방법은 코드 아래에 작성했음.

#include <bits/stdc++.h>
using namespace std;

int tree[10001];

void postOrder(int s, int e) {
	if (s >= e) return;
	int pivot = upper_bound(tree + s + 1, tree + e, tree[s]) -tree;
	
	postOrder(s+1, pivot);
	postOrder(pivot , e);
	cout<<tree[s]<<'\n'; // postOrder
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int idx = 1, tmp;
	while (cin >> tmp) {
		tree[idx++] = tmp;
	}

	postOrder(1, idx);
}

/*
50
30
24
5
28
45
98
52
60

<위의 케이스에 대하여 분할되는 인덱스를 트리로 표현>,
>> 인덱스로 표기, 
>> 0~8인덱스, 9는 end를 표현
>> if (s >= e) return; 에 해당하는 리프노드는 표현하지 않았음.
					 (0)
			(1~6)		     (6~9)
	   (2~5)	 (5~6)  (7~9) 	  ()
   (3~4)  (4~5) ()   ()()	(8~9)
  ()   ()()   ()           ()   ()

즉,
	 0
   1   6
 2  5 7
3 5    8

과 같이 형성됨.
*/