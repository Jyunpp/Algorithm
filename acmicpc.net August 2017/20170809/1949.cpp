//20170809 20:35 ~ 21:05
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
	int num;
	vector<int> edge;
};

vector<Node> graph;
vector<Node> tree;
int n, ans, visited[10001], dp[10001][2];

//tree ä���
void dfs(int here, int parent) {
	visited[here] = 1;
	tree[parent].edge.push_back(here);
	for (auto &i : graph[here].edge) {
		if (visited[i] != 1)
			dfs(i, here);
	}
}

int solve(int idx, int opt) {
	int &ret = dp[idx][opt];
	if (ret) return ret;
	ret = 0;
	if (opt) {//�̹� �� ������ ���.
		ret += tree[idx].num;
		for (auto &i : tree[idx].edge)
			ret += solve(i, 0);
	}
	else {
		for (auto &i : tree[idx].edge) {
			//max�� �ϸ�, ��� �ϳ��� '��� ����'�� �����ϴ� ��츸 ���Եȴ�!!
			ret += max(solve(i, 0), solve(i, 1));
		}
	}
	return ret;
}

int main() {
	//�Է�
	scanf("%d", &n);
	graph.resize(n + 1);
	tree.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &graph[i].num);
		tree[i].num = graph[i].num;
		visited[i] = -1;
	}
	for (int i=2, a, b; i<=n; i++) {
		scanf("%d %d", &a, &b);
		graph[a].edge.push_back(b);
		graph[b].edge.push_back(a);
	}
	//dfs�� tree �����
	dfs(1, 0);
	//solve
	int x = solve(1, 0);
	int y = solve(1, 1);
	printf("%d", max(x, y));
//	system("pause");
	return 0;
}