// 20190527 03:00 ~ 04:30
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
#include <map>
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

int t;
int n, k;
int p[1001]; // position
int c[1001]; // color
vector<int> v[1001]; // positions per each color. cp[i] : positions of color i
int dp[2][1001];

int main() {
    cin>>t;
    rep(T, 1, t+1) {
        // clear, init
        rep(i, 1, 1001) v[i].clear(), dp[0][i] = dp[1][i] = 987654321;

        // input
        cin>>n>>k;
        rep(i, 1, n+1) cin>>p[i];
        rep(i, 1, n+1) cin>>c[i], v[c[i]].pb(p[i]);

        rep(i, 1, 1001) {
            if(v[i].empty()) continue;
            
            sort(v[i].begin(), v[i].end());
            for(int j=k-1; j>=0; j--) {
                int sz = v[i].size();
                rep(h, 0, sz) {
                    if(j+h+1 > k) break;
                    dp[0][j+h+1] = min(dp[0][j+h+1], dp[0][j] + 2*v[i][h]);
                    dp[1][j+h+1] = min(dp[1][j+h+1], dp[0][j] + v[i][h]);
                    dp[1][j+h+1] = min(dp[1][j+h+1], dp[1][j] + 2*v[i][h]);
                }
            }
        }
        cout<<"Case #"<<T<<": "<<dp[1][k]<<endl;
    }
    return 0;
}
