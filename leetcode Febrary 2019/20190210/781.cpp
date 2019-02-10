//20190210 22:11 ~ 22:16
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int arr[1001] = {0};
    int ret = 0;
    int numRabbits(vector<int>& answers) {
        for(auto i : answers) {
            arr[i]++;
            // 같은 색 없으면 그 색은 한명
            ret += i == 0;
        }
        // 같은 색 x 명이라고 대답한게 y번 등장 => (x+1)번씩 그룹화 
        for(int i=1; i<=1000; i++) {
            ret += (arr[i] / (i+1)) * (i+1);
            if(arr[i] % (i+1)) ret += i+1;
        }
        cout<<ret<<endl;
        return ret;
    }
};

int main(){
    int n; cin>>n;
    vector<int> v;
    for(int i=1, a; i<=n; i++) {
        cin>>a; v.push_back(a);
    }
    Solution solution;
    solution.numRabbits(v);
    return 0;
}