//20170815 18:37 ~ 19:00
/*
	그래프 => dfs스패닝 트리 만든 후,
	a->b방문 할때 들른 간선이 단절선인지 보기 위해, 
	그 전에 방문했 노드들 ~ 그 후에 방문했던 노드들이 
	a->b간선 이외의 경로를 통해 이어지는가에 대해 본다. 그런 경로가 없다면 단절선.
	아울러, b로 오는 다른 간선들에 대해 볼 필요가 없는 이유는, a->b가 있기 때문에.
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

//dfs스패닝 트리를 만들면서 단절선 기록.
int dfs(int curr, int parent) {
	discovered[curr] = ++counter;
	int ret = discovered[curr];

	for (auto &i : graph[curr]) {
		if (i == parent) continue;
		if (!discovered[i]) {
			int low = dfs(i, curr);			//정점 curr의 자식 노드가 갈 수 있는(그래프상에서) 가장 빠른(dfs스패닝트리 상에서) 노드
			if (low > discovered[curr]) {	//가장 빠른게 이번 curr보다 더 늦다면, 다른 모든 노드들도 curr보다 더 늦고, curr->par 이후에 몰려있는 것.
											//curr<->par를 통해서만 갈 수 있는 노드들이 존재. => 단절선
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