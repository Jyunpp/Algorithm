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
int c[202][202];	// 1~100 : ����, 101~200 : ���
int d[202][202];
int f[202][202];
int S = 0, T = 201;
vector<int> adj[202];

int main() {
	scanf("%d %d", &n, &m);
	// ��� ~ ��ũ
	for (int i = 101; i <= 100 + n; i++) {
		scanf(" %d", &c[i][T]);
		adj[i].push_back(T);
		adj[T].push_back(i);
	}
	// �ҽ� ~ ����
	for (int i = 1; i <= m; i++) {
		scanf(" %d", &c[S][i]);
		adj[S].push_back(i);
		adj[i].push_back(S);
	}
	// ���� ~ ����
	for (int i = 1; i <= m; i++) {
		for (int j = 101; j <= 100 + n; j++) {
			scanf(" %d", &d[i][j]);
			d[j][i] = -d[i][j];		// ������ ��!
			c[i][j] = 987654321;
			adj[i].push_back(j);
			adj[j].push_back(i);
		}
	}
	int result = 0;					// �ּ� ���

	while (1) {
		int prev[202], dist[202];
		bool inQ[202];				// �ش� ������ ť �ȿ� �ִ°�?
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
				// �����뷮�� �ִ� ��� �� �ִ� ��θ� ã��
				// �ִ� ��θ� ã�� ����, ������ ī�������� �湮���� -> �Ÿ�(���) �˻�� �ٲ�
				if (c[curr][next] - f[curr][next] > 0 && dist[next] > dist[curr] + d[curr][next]) {
					dist[next] = dist[curr] + d[curr][next];
					prev[next] = curr;
					// next�� ť�� ������ ť�� ����.
					if (!inQ[next]) {
						q.push(next);
						inQ[next] = true;
					}
				}
			}
		}
		if (prev[T] == -1) break;

		// ��λ� �ּ��� rasidual ã��
		int flow = 987654321;
		for (int i = T; i != S; i = prev[i])
			flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);

		//��� �ֱ�
		for (int i = T; i != S; i = prev[i]) {
			result += flow * d[prev[i]][i];
			f[prev[i]][i] += flow;
			f[i][prev[i]] -= flow;	// ������ ��!
		}
	}

	printf("%d\n", result);
	//system("pause");
	return 0;
}