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

//�ʱ� ȣ�� ��, idx���� rootNode index �ֱ�.
ll dfs(int idx, int parent) {						//parent�� ���ڷ� �޾Ƽ� tree ���·θ� ���ȣ�� �� �� �ֵ���.
	ll ret = 0;										//for���� ��� ������, idx�� ��Ʈ���� �ϴ� ����Ʈ���� ����ġ�� ���� �ȴ�.
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
	
	printf("%lld\n", dfs(1, -1));					//idx1 ���� ��Ʈ��� ���̶�� ������ �ֳ�?
	//system("pause");
	return 0;
}