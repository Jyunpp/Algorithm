//20170827 02:11 ~ 02:47
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

int n, m;			
int c[202][202];	// 1~100 : 서점, 101~200 : 사람
int d[202][202];
int f[202][202];
int S = 0, T = 201;
vector<int> adj[202];

int main() {
	scanf("%d %d", &n, &m);
	// 사람 ~ 싱크
	for (int i = 101; i <= 100 + n; i++) {
		scanf(" %d", &c[i][T]);
		adj[i].push_back(T);
		adj[T].push_back(i);
	}
	// 소스 ~ 서점
	for (int i = 1; i <= m; i++) {
		scanf(" %d", &c[S][i]);
		adj[S].push_back(i);
		adj[i].push_back(S);
	}
	// 서점 ~ 사이
	for (int i = 1; i <= m; i++) {
		for (int j = 101; j <= 100 + n; j++) {
			scanf(" %d", &d[i][j]);
			d[j][i] = -d[i][j];		// 역방향 꼭!
			c[i][j] = 987654321;
			adj[i].push_back(j);
			adj[j].push_back(i);
		}
	}
	int result = 0;					// 최소 비용

	while (1) {
		int prev[202], dist[202];
		bool inQ[202];				// 해당 정점이 큐 안에 있는가?
		queue<int> q;
		fill(prev, prev + 202, -1);
		fill(dist, dist + 202, 987654321);
		fill(inQ, inQ + 202, false);
		dist[S] = 0;
		inQ[S] = true;
		q.push(S);

		while (!q.empty()) {
			int curr = q.front();
			q.pop();
			inQ[curr] = false;
			for (auto &next : adj[curr]) {
				// 여유용량이 있는 경로 중 최단 경로를 찾음
				// 최단 경로를 찾기 위해, 에드몬드 카프에서의 방문여부 -> 거리(비용) 검사로 바뀜
				if (c[curr][next] - f[curr][next] > 0 && dist[next] > dist[curr] + d[curr][next]) {
					dist[next] = dist[curr] + d[curr][next];
					prev[next] = curr;
					// next가 큐에 없으면 큐에 넣음.
					if (!inQ[next]) {
						q.push(next);
						inQ[next] = true;
					}
				}
			}
		}
		if (prev[T] == -1) break;

		// 경로상 최소의 rasidual 찾기
		int flow = 987654321;
		for (int i = T; i != S; i = prev[i])
			flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);

		//흘려 주기
		for (int i = T; i != S; i = prev[i]) {
			result += flow * d[prev[i]][i];
			f[prev[i]][i] += flow;
			f[i][prev[i]] -= flow;	// 역방향 꼭!
		}
	}

	printf("%d\n", result);
	//system("pause");
	return 0;
}