// <가장 큰 수>
// https://programmers.co.kr/learn/courses/30/lessons/42746
// string, 정렬

#include <vector>
#include <string>
#include <algorithm>
using namespace std;
 
 // 문자열 (12 와 121) 또는 (33433와 334333) 어떤것이 앞으로 와야 가장 큰 수를 만들 수 있을까?
 // -> (문자열a + 문자열b) 와 (문자열b + 문자열a) 중 큰 문자열이 앞으로 오도록 정렬하면 됨.
bool comp(string a, string b) {
    return a + b > b + a;
}
 
string solution(vector<int> nb) {
    string ans = "";
    vector<string> t;
    for (auto num : nb)
        t.push_back(to_string(num));
    sort(t.begin(), t.end(), comp);
        if (t.at(0) == "0") return "0";
    for (auto val : t)
        ans += val;
    return ans;
}