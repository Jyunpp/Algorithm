//20170809 21:10 ~ (잠시 다른 문제 21:50 ~ 22:30) ~ 23:00
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, ans;
int visited[100001];
int dp[100001][17];
vector<vector<int>> tree;	//tree[i] = idx i 와 연결된 idx 들.
							//dfs 호출 후, tree구조로 바뀜.

void dfs(int idx) {
	visited[idx] = 1;
	int len = tree[idx].size();
	int i = 0;
	while (len--){
		if (visited[tree[idx][i]] == 1)
			tree[idx].erase(tree[idx].begin() + i);
		else {
			dfs(tree[idx][i]);
			i++;
		}
	}
}

int solve(int idx, int used) {//used : 바로 직전에 사용한 숫자.
	int &ret = dp[idx][used];
	if (ret) return ret;
	int tempRet = 987654321;

	for (int i = 1; i <= 17; i++) {
		if (i == used)continue;
		int temp = i;
		for (auto &j : tree[idx]) {
			temp += solve(j, i);
		}
		tempRet = min(tempRet, temp);
	}

	return ret = tempRet;
}

int main() {
	//입력
	scanf("%d", &n);
	tree.resize(n + 1);
	for (int i = 2, a, b; i <= n; i++){
		scanf("%d %d", &a, &b);
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	//dfs로 트리만들기. => node1 이 root node가 됌.
	dfs(1);
	//solve
	ans = solve(1, 0);
	cout << ans << endl;
	//system("pause");
	return 0;
}