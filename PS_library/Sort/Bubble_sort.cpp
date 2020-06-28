#include<bits/stdc++.h>
using namespace std;
const int n = 100;
int A[n+1]{};

void bubbleSort(){
    int tmp;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (A[j] > A[j + 1]) {
                tmp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = tmp;
            }
        }
	}
}
