// 20190310 15:50 ~ 
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

int n, k;
vector<int> v, cnt; // cnt[i] : max # of member for team that is containing i's member as a lowest skill level 

int main() {
    cin >> n >> k;
	v = vector<int>(n);
    cnt = vector<int>(n);

    rep(i, 0, n) cin>>v[i];
	sort(v.begin(), v.end());

    rep(i, 0, n) {
        while(i + cnt[i] < n && v[i+cnt[i]] - v[i] <= 5) {
            cnt[i]++;
        }
    }
	vector<vector<int>> dp(n + 1, vector<int>(k + 1));
    rep(i, 0, n) {
        rep(j, 0, k+1) {
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            if(j+1 <=k) {
                dp[i+cnt[i]][j+1] = max(dp[i+cnt[i]][j+1], dp[i][j] + cnt[i]);
            }
        }
    }
	cout << dp[n][k] << endl;
	return 0;
}