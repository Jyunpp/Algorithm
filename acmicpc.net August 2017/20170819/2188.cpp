//20170819 20:15 ~ 
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int n, m;			//n, m������ ���� 200 ���� ����, back flow�� ����ؼ�
int c[402][402];	//����ȣ�� 1~400 ����Ѵ�. 1~200��, 201~400���
int f[402][402];
int S = 0;			//S�� 0
int T = 401;		//T�� 401
vector<int> adj[402];

int main() {
	scanf(" %d %d", &n, &m);
	memset(c, 0, sizeof(c));
	memset(f, 0, sizeof(f));
	for (int i = 1, a; i <= n; i++) {
		scanf(" %d", &a);
		for (int j = 1, b; j <= a; j++) {
			scanf(" %d", &b);
			b += 200;
			c[i][b] = 1;
			adj[i].push_back(b);
			adj[b].push_back(i);
		}
		c[S][i] = 1;
		adj[S].push_back(i);
		adj[i].push_back(S);
	}
	for (int i = 201; i <= 200 + m; i++) {
		c[i][T] = 1;
		adj[i].push_back(T);
		adj[T].push_back(i);
	}
	int total = 0;
	while (1) {
		int prev[402];
		fill(prev, prev + 402, -1);
		queue<int> q;
		q.push(S);
		while(!q.empty()) {
			int curr = q.front();
			q.pop();
			for (auto &next : adj[curr]) {
				if (c[curr][next] - f[curr][next] > 0 && prev[next] == -1) {
					q.push(next);
					prev[next] = curr;
					if (next == T)break;
				}
			}
		}
		if (prev[T] == -1) break;

		int flow = 1;
		for (int i = T; i != S; i = prev[i]) {
			f[prev[i]][i] += flow;
			f[i][prev[i]] -= flow;
		}

		total += flow;

	}
	printf("%d\n", total);
	//system("pause");
	return 0;
}
