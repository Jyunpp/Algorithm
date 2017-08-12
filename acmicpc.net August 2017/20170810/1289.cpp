//20170810 02:49 ~ 15:52
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

#define mod 1000000007

using namespace std;

typedef long long ll;

int n;
ll dp[100001];
vector<vector<pair<int, int>>> adj;

inline ll multi(ll a, ll b) { return a*b%mod; }
inline ll sum(ll a, ll b) { return (a + b) % mod; }

//초기 호출 시, idx에는 rootNode index 넣기.
ll dfs(int idx, int parent) {						//parent를 인자로 받아서 tree 형태로만 재귀호출 할 수 있도록.
	ll ret = 0;										//for문이 모두 끝나면, idx를 루트노드로 하는 서브트리의 가중치의 합이 된다.
													//classified
	return ret;
}

int main() {
	scanf("%d", &n);
	adj.resize(n + 1);
	for (int i = 1, a, b, c; i < n; i++) {
		scanf("%d %d %d", &a, &b, &c);

		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}
	
	printf("%lld\n", dfs(1, -1));					//idx1 값이 루트노드 값이라는 보장이 있나?
	//system("pause");
	return 0;
}