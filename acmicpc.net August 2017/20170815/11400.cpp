//20170815 18:37 ~ 19:00
/*
	�׷��� => dfs���д� Ʈ�� ���� ��,
	a->b�湮 �Ҷ� �鸥 ������ ���������� ���� ����, 
	�� ���� �湮�� ���� ~ �� �Ŀ� �湮�ߴ� ������ 
	a->b���� �̿��� ��θ� ���� �̾����°��� ���� ����. �׷� ��ΰ� ���ٸ� ������.
	�ƿ﷯, b�� ���� �ٸ� �����鿡 ���� �� �ʿ䰡 ���� ������, a->b�� �ֱ� ������.
*/
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int V, E, discovered[100001];
int counter = 0;
vector<vector<int>> graph;
vector<pair<int, int>>edge;

//dfs���д� Ʈ���� ����鼭 ������ ���.
int dfs(int curr, int parent) {
	discovered[curr] = ++counter;
	int ret = discovered[curr];

	for (auto &i : graph[curr]) {
		if (i == parent) continue;
		if (!discovered[i]) {
			int low = dfs(i, curr);			//���� curr�� �ڽ� ��尡 �� �� �ִ�(�׷����󿡼�) ���� ����(dfs���д�Ʈ�� �󿡼�) ���
			if (low > discovered[curr]) {	//���� ������ �̹� curr���� �� �ʴٸ�, �ٸ� ��� ���鵵 curr���� �� �ʰ�, curr->par ���Ŀ� �����ִ� ��.
											//curr<->par�� ���ؼ��� �� �� �ִ� ������ ����. => ������
				edge.push_back({ min(curr,i),max(curr,i) });
			}
			ret = min(ret, low);
		}
		else
			ret = min(ret, discovered[i]);
	}
	return ret;
}

int main() {
	scanf("%d %d", &V, &E);
	graph.resize(V);
	for (int i = 1, a, b; i <= E; i++) {
		scanf(" %d %d", &a, &b); a--; b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(0, 0);

	sort(edge.begin(), edge.end(), [](pair<int, int> a, pair<int, int> b) {return (a.first != b.first ? a.first < b.first : a.second < b.second); });
	printf("%d\n", edge.size());
	for (auto &i : edge)
		printf("%d %d\n", i.first + 1, i.second + 1);
	//system("pause");
	return 0;
}