// 20190318 studied tutorial
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

int n;
ll res, ans;
vector<int> cost;
vector<ll> sum;
vector<vector<int>> edge;

void dfs(int curr, int prev = -1, int depth = 0) {
    res += depth * 1ll * cost[curr];
    sum[curr] = cost[curr];

    for(auto next : edge[curr]) {
        if(next == prev) continue;
        dfs(next, curr, depth+1);
        sum[curr] += sum[next];
    }
}

void go(int curr, int prev = -1) {
	ans = max(ans, res);
    for(auto next : edge[curr]) {
        if(next == prev) continue;
        res -= sum[next];
        sum[curr] -= sum[next];
        res += sum[curr];
        sum[next] += sum[curr];
        go(next, curr);
        sum[next] -= sum[curr];
        res -= sum[curr];
        sum[curr] += sum[next];
        res += sum[next];
    }
}

int main() {
	cin >> n;
	cost = vector<int>(n);
	sum = vector<ll>(n);
	edge = vector<vector<int>>(n);
    rep(i, 0, n) cin >> cost[i];
	rep(i, 0, n-1) {
		int x, y;
        cin>>x>>y;
        --x;
        --y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	
	dfs(0);
	go(0);
	cout << ans << endl;
	return 0;
}
