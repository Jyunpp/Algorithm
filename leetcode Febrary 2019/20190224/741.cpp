// 20190224 16:43 ~ 17:39
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
    int dp[51][51][51]; // r1, c1, r2 (c2 = r1+c1-r2)
    int arr[51][51];
    int by, bx;

    int cherryPickup(vector<vector<int>>& grid) {
        by = grid.size(); bx = grid[0].size();
        rep(i, 1, 51) rep(j, 1, 51) rep(k, 1, 51) dp[i][j][k]= -1;
        rep(i, 0, grid.size()) rep(j, 0, grid[0].size()) arr[i+1][j+1] = grid[i][j];
        int ret = recur(1, 1, 1);
        if(ret<0) ret = 0;
        return ret;
    }
    int recur(int r1, int c1, int r2) {
        int c2 = r1+c1-r2;
        if(r1==by && r2==by && c1==bx && c2==bx) return arr[r1][c1];
        if(r1>by || r2>by || c1>bx || c2>bx) return -99999;
        if(arr[r1][c1] == -1 || arr[r2][c2] == -1) return -99999;
        
        int &ret = dp[r1][c1][r2];
        if(ret != -1) return ret;

        int restRet = max(max(max(recur(r1+1, c1, r2), recur(r1, c1+1, r2)), recur(r1+1, c1, r2+1)), recur(r1, c1+1, r2+1));
        int curr = arr[r1][c1] + arr[r2][c2];
        if(r1==r2) curr/=2;
        if(restRet < 0) return ret = -99999;
        else return ret = restRet + curr;
    }
};