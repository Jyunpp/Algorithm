//20170831 09:27 ~ 10:11
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

int d[2004][2004];
int f[2004][2004];
int c[2004][2004];
int main() {
	int v, e;
	while (scanf("%d %d", &v, &e) != EOF) {
		//입력 및 초기화
		int S = 1, T = v;
		memset(d, 0, sizeof(d));
		memset(f, 0, sizeof(f));
		memset(c, 0, sizeof(c));
		vector<int> adj[2004];
		for (int i = 1, ai, bi, ci; i <= e; i++) {
			scanf(" %d %d %d", &ai, &bi, &ci);
			//경로가 겹치지 않게 하기 위해서 정점 내부에서 분리 후 용량을 1로 제한한다.
			//ai -> ai_ -> bi
			c[ai][1000 + ai] = 1;
			c[1000 + ai][bi] = 1;
			d[1000 + ai][bi] = ci;
			d[bi][1000 + ai] = -ci;
			adj[ai].push_back(1000 + ai);
			adj[1000 + ai].push_back(ai);
			adj[bi].push_back(1000 + ai);
			adj[1000 + ai].push_back(bi);
		}
		c[S][1000 + S] = 987654321;			//시작점은 c가 무한
		//mcmf
		int result = 0;

		for (int t = 1; t <= 2; t++) {
			int prev[2004], dist[2004];
			bool inQ[2004];
			queue<int> q;
			fill(prev, prev + 2004, -1);
			fill(dist, dist + 2004, 987654321);
			fill(inQ, inQ + 2004, false);
			dist[S] = 0;
			inQ[S] = true;
			q.push(S);

			while (!q.empty()) {
				int curr = q.front();
				q.pop();
				inQ[curr] = false;
				for (auto &next : adj[curr]) {
					if (c[curr][next] - f[curr][next] > 0 && dist[next] > dist[curr] + d[curr][next]) {
						dist[next] = dist[curr] + d[curr][next];
						prev[next] = curr;
						if (!inQ[next]) {
							q.push(next);
							inQ[next] = true;
						}
					}
				}
			}
			//모든 c가 1이라서 flow는 그냥 1.
			for (int i = T; i != S; i = prev[i]) {
				result += d[prev[i]][i];
				f[prev[i]][i] += 1;
				f[i][prev[i]] -= 1;
			}
		}
		printf("%d\n", result);
	}
	//system("pause");
	return 0;
}