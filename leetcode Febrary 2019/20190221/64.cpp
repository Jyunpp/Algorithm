// 20190221 02:32 ~ 02:36
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
    int minPathSum(vector<vector<int>>& grid) {
        rep(i, 1, grid.size()) grid[i][0]+=grid[i-1][0];
        rep(i, 1, grid[0].size()) grid[0][i]+=grid[0][i-1];
        rep(i, 1, grid.size())
            rep(j, 1, grid[0].size())
                grid[i][j]+= min(grid[i][j-1], grid[i-1][j]);
        return grid[grid.size()-1][grid[0].size()-1];
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
    cout<<sol.minPathSum(v);
    return 0;
}