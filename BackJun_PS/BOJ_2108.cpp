// <통계학> - 2108
// math클래스 : round() 함수(반올림)사용 , vector클래스 : erase(), size(), unique() 함수 사용 ( unique()는 중복제거함수)
#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<n; i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N;
	cin>>N;
	vector<int> cMode(8001, 0);
	vector<int> arr(N);
	vector<int> mStack;
	double sum = 0;
	int mid, range, mode=0;
	rep(i, 0, N) {
		cin>>arr[i];
		sum += arr[i];
		cMode[arr[i]+4000]++;
	}

	int mean = round(sum/N);
	//int mean = floor(sum/N + 0.5);
	//int mean = sum/N + 0.5; // 이렇게하면 정확한값 안나옴. floor이용해야함. or round()사용
	sort(arr.begin(), arr.end());
	mid = arr[N/2];
	range = arr[N-1] - arr[0];

    auto n = unique(arr.begin(),arr.end());
    arr.erase(n, arr.end());

	rep(i, 0, arr.size()){
		if(cMode[arr[i]+4000]> mode) {
			mStack.clear();
			mStack.push_back(arr[i]);
			mode = cMode[arr[i]+4000];
		} else if(cMode[arr[i]+4000]==mode){
			mStack.push_back(arr[i]);
		}
	}

	cout<<mean<<"\n";
	cout<<mid<<"\n";
	if(mStack.size()>1) cout<<mStack[1]<<"\n";
	else cout<<mStack[0]<<"\n";
	cout<<range<<"\n";

}