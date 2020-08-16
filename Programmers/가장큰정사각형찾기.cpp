// <가장 큰 정사각형 찾기>
// https://programmers.co.kr/learn/courses/30/lessons/12905
// DP

/*
a b
c ?
a,b,c의 최솟값 +1 을하여 (?)를 구함
-> (?)에서 만들 수 있는 최대 크기의 정사각형
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board)
{
    
    int rsz = board.size();
    int csz = board[0].size();
    int maxn=0;
    for(int j=0; j<csz; j++){
        if(board[0][j]) {maxn=1; break;}
    }
    for(int i=1; i<rsz; i++){
        for(int j=1; j<csz; j++){
            if(board[i][j]){
                board[i][j] = min({board[i-1][j-1],board[i-1][j],board[i][j-1]}) + 1;
                maxn = max(maxn, board[i][j]);
            }
        }
    }

    return maxn*maxn;
}