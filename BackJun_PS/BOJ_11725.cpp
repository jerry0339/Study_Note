//<트리의 부모찾기> - 11725
#include <bits/stdc++.h>
#define rep(i, x, n) for (int i = x; i < n; i++)
using namespace std;

class node {
   public:
    int num = 0;
    vector<int> arr;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, n;
    cin >> N;
    vector<vector<int>> node(N);
    vector<int> queue;
    vector<int> parent(N);
    parent[0] = -1;

    n = N - 1;
    while (n--) {
        int a, b;
        cin >> a >> b;
        node[a - 1].push_back(b - 1);  // 인덱스로 노드번호 들어감
        node[b - 1].push_back(a - 1);
    }

    //bfs 이용함
    queue.push_back(0);  // 인덱스로 노드번호 큐에 넣기
    while (!queue.empty()) {
        int num = *(queue.begin());
        queue.erase(queue.begin());
        for (auto it = node[num].begin(); it != node[num].end(); it++) {
            if ((*it) != parent[num]) {
                queue.push_back(*it);
                parent[*it] = num;
            }
        }
    }

    rep(i, 1, N)
            cout
        << parent[i] + 1 << "\n";
}
/* 
intput(1)의 데이터에서 node에 저장된 값들. (실제 값은 인덱스로 저장되어있어서 -1해주면됨)
1: 6 4
2: 4
3: 6 5
4: 1 2 7
5: 3
6: 1 3
7: 4

*/

/*
<트리의 부모찾기> - 11725
input(1) :
7
1 6
6 3
3 5
4 1
2 4
4 7

ouput(1) : 
4
6
1
3
1
4

-------------------------------------
input(2) :
12
1 2
1 3
2 4
3 5
3 6
4 7
4 8
5 9
5 10
6 11
6 12

output(2) : 
1
1
2
3
3
4
4
5
5
6
6

*/