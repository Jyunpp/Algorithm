// 20190221 01:47 ~ 01:51
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
    ll uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<ll>> dp(m, vector<ll>(n, 0));
        if(obstacleGrid[0][0]) return 0;

        dp[0][0] = 1;
        rep(i, 1, m) dp[i][0] = !obstacleGrid[i][0] && dp[i-1][0];
        rep(i, 1, n) dp[0][i] = !obstacleGrid[0][i] && dp[0][i-1];
        rep(i, 1, m) {
            rep(j, 1, n) {
                if(obstacleGrid[i][j]) continue;
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
        return dp[m-1][n-1];
    }
};

int main() {
    Solution sol;
    int m, n;
    cin>>m>>n;
    vector<vector<int>> v;
    rep(i, 0, m){
        vector<int> curr = vector<int>(n);
        rep(j, 0, n){
            cin>>curr[j];
        }
        v.push_back(curr);
    }
    cout<<sol.uniquePathsWithObstacles(v);
    return 0;
}