// 20190218 22:07 ~ 22:21
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
    int dy[4] = {0, 0, 1, -1};
    int dx[4] = {1, -1, 0, 0};
    int ans = 0;

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        rep(i, 0, grid.size()) {
            rep(j, 0, grid[i].size()) {
                if(!grid[i][j]) continue;
                int tempAns = 0;
                queue<P> q; // y, x
                q.push({i, j}); grid[i][j] = 0;
                while(!q.empty()) {
                    int y = q.front().xx;
                    int x = q.front().yy;
                    q.pop(); tempAns++;
                    rep(k, 0, 4) {
                        int ny = y + dy[k];
                        int nx = x + dx[k];
                        if(ny<0 || nx <0 || ny>=grid.size() || nx >= grid[i].size() ) continue;
                        if(!grid[ny][nx]) continue;
                        q.push({ny, nx});
                        grid[ny][nx] = 0;
                    }
                }
                ans = max(ans, tempAns);
            }
        }
        cout<<ans<<endl;
        return ans;
    }
};

int main() {
    Solution solution;
    int n, m;
    vector<vector<int>> v;
    cin>>n>>m;
    rep(i, 0, n) {
        vector<int> currV = vector<int>(m);
        rep(j, 0, m) {
            int a ; cin>>a;
            currV.push_back(a);
        }
        v.push_back(currV);
    }

    solution.maxAreaOfIsland(v);
    return 0;
}