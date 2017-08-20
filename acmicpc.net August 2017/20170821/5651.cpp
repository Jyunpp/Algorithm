//20170821 05:38 ~ 
/*
	�ִ�� ������ ������� ��,
	��� ����(a->b)�� ���ؼ� a���� b�� ������ ��� ���� �� ���ٸ� ī��Ʈ.
	�߿䰣���� ã�� ���� ������ ������ �������� �ʴ´�.
*/

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int k, n, m;
int c[301][301];
int f[301][301];

int main() {
	scanf("%d", &k);
	while (k--) {
		scanf(" %d %d", &n, &m);
		vector<vector<int>> adj(n + 1);
		vector<pair<int, int>> edge;
		memset(c, 0, sizeof(c));
		memset(f, 0, sizeof(f));
		for (int i = 1, a, b, cap; i <= m; i++) {
			scanf(" %d %d %d", &a, &b, &cap);
			adj[a].push_back(b);
			adj[b].push_back(a);
			c[a][b] += cap;
			edge.push_back({ a,b });
		}

		//int total = 0; //���󵵉�
		int S = 1, T = n;
		while (1) {
			vector<int> prev(n + 1, -1);
			queue<int> q;
			q.push(S);

			while (!q.empty() && prev[T] == -1) {
				int curr = q.front();
				q.pop();

				for (auto &i : adj[curr]) {
					if (c[curr][i] - f[curr][i] > 0 && prev[i] == -1) {
						q.push(i);
						prev[i] = curr;
					}
				}
			}
			if (prev[T] == -1) break;

			int flow = 987654321;
			for (int i = T; i != S; i = prev[i])
				flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
			
			for (int i = T; i != S; i = prev[i]) {
				f[prev[i]][i] += flow;
				f[i][prev[i]] -= flow;
			}
			//total += flow; //���󵵉�
		}
		int ans = 0;
		for (auto &i : edge) {
			int s = i.first;
			int t = i.second;

			vector<int> prev(n + 1, -1);
			queue<int> q;
			q.push(s);

			while (!q.empty() && prev[t] == -1) {
				int curr = q.front();
				q.pop();

				for (auto &i : adj[curr]) {
					if (c[curr][i] - f[curr][i] > 0 && prev[i] == -1) {
						prev[i] = curr;
						q.push(i);
					}
				}
			}
			//ã�� �� �߰� ���� ��������� ����, �Ǵܸ� ���ش�.
			if (prev[t] == -1) ans++;
		}
		printf("%d\n", ans);
	}
	//system("pause");
	return 0;
}