// 삼분탐색(ternary_search)

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll arr[100001]{};

ll ternary_search(ll st, ll en){
    // arr[st] ~ arr[en-1] 중 최솟값 리턴
    ll l = st, r = en;
    while(r-l>=3) {
        ll range = (r-l)/3;
        ll mid1 = l + range;
        ll mid2 = r - range;
        if(arr[mid1] < arr[mid2]) r = mid2;
        else l = mid1;
    }
    ll ret = arr[l];
    for(ll i=l+1; i<r; i++)
        ret = min(ret, arr[i]);
    return ret;
}

// 출처: https://www.weeklyps.com/entry/검색-Search#d3 [weekly ps]