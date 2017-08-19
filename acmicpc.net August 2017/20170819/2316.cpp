//20170819 21:20 ~ 
/*
	1, 2를 왔다갔다 하는 횟수는 (왔다도 1번, 갔다도 1번으로 칠 때)
	1->2로 갈 수 있는 경로의 수. 이 때, 정점은 한 번씩만 사용.
	1->?, ?->2 제외 모든 간선의 capacity를 1로 설정. 
	★정점 하나를 내부의 두 정점으로 연결, capacity를 1로 설정 => 정점 한 번만 사용가능
	   이 때!! i->i를 c[i][i]로 생각하지말고, 새로운 점을 그냥 만들어야 함!
	   돌아올 수 있도록 !!!! ★★
*/
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

int N, P;
int c[801][801];		//점이 400개이하지만, 점 a를 a와 a+400로 생각.
int f[801][801];		//항상 a->b 이동 위해서는 a -> a+400 ->b로 한다.
vector<int> adj[801];

int main() {
	scanf(" %d %d", &N, &P);
	memset(c, 0, sizeof(c));
	memset(f, 0, sizeof(f));
	for (int i = 1, a, b; i <= P; i++) {
		scanf(" %d %d", &a, &b);
		c[a][a + 400] = c[b][b + 400] = c[a + 400][b] = c[b + 400][a] = 1;//test
		adj[a + 400].push_back(b);
		adj[b + 400].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		c[1][401] = c[401][i] = c[400 + i][2] = 987654321;	//출발지 1의 경우도 예외없도록.
		adj[i].push_back(i + 400);
	}

	int total = 0;
	while (1) {
		int prev[801];
		fill(prev, prev + 801, -1);
		queue<int> q;
		q.push(1);
		while (!q.empty()) {
			int curr = q.front();
			q.pop();
			for (auto &next : adj[curr]) {
				if (c[curr][next] - f[curr][next] > 0 && prev[next] == -1) {
					q.push(next);
					prev[next] = curr;
					if (next == 2) break;
				}
			}
		}
		if (prev[2] == -1) break;

		int flow = 1;
		for (int i = 2; i != 1; i = prev[i]) {
			f[prev[i]][i] += flow;
			f[i][prev[i]] -= flow;
		}
		total += flow;

	}
	printf("%d\n", total);
//	system("pause");
	return 0;
}
