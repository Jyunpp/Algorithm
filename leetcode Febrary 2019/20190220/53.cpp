// 20190220 21:00 ~ 21:07
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>
using namespace std;

#define sd(x) scanf(" %d", &x);
#define slld(x) scanf(" %lld", &x);
#define pb push_back
#define xx first
#define yy second
#define rep(i, l, r) for(int i=l; i<r; i++)
#define sortV(v, lambda) sort(v.begin(), v.end(), lambda)
#define powll(a, b) (ll) pow(a, b)

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sz = nums.size();
        vector<int> dp = vector<int>(sz, -1987654321);
        int ret = dp[0] = nums[0];
        rep(i, 1, sz) {
            dp[i] = max(dp[i-1] + nums[i], nums[i]);
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};

int main() {
    Solution sol;
    vector<int> v;
    int n;
    cin>>n;
    rep(i, 0, n) {
        int a; cin>>a; v.push_back(a);
    }
    cout<<sol.maxSubArray(v);
    return 0;
}