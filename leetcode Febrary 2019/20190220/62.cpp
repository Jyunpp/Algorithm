// 20190220 21:31 ~ 21:37
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
    int dp[101][101];
    int uniquePaths(int m, int n) {
        rep(i, 1, m+1) dp[i][1] = 1;
        rep(i, 1, n+1) dp[1][i] = 1;
        rep(i, 2, m+1) {
            rep(j, 2, n+1) {
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
        return dp[m][n];
    }
};

int main() {
    Solution sol;
    int m, n;
    cin>>m>>n;
    cout<<sol.uniquePaths(m, n);
    return 0;
}