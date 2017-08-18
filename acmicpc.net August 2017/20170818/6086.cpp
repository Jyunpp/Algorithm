//20170818 21:44 ~ 23:11
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX_V = 52;
const int INF = 987654321;

inline int CtoI(char c) {
	if (c <= 'Z') return c - 'A';
	return c - 'a' + 26;
}

int main() {
	int N;							//간선 수
	int c[MAX_V][MAX_V] = { 0 };	//i->j 용량
	int f[MAX_V][MAX_V] = { 0 };	//i->j 유량
	vector<int> adj[MAX_V];			//인접 리스트

	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		char u, v;
		int ui, vi;
		int w;
		scanf(" %c %c %d", &u, &v, &w);
		ui = CtoI(u); vi = CtoI(v);
		c[ui][vi] += w;				//같은 간선 여러 번 입력 가능.
		adj[ui].push_back(vi);
		adj[vi].push_back(ui);		//역방향도 꼭 추가하랍니다..
	}

	int total = 0, S = CtoI('A'), T = CtoI('Z');
	//흐를 수 있는 path가 없을 때 까지 path 찾기.
	while (1) {
		int prev[MAX_V];
		fill(prev, prev + MAX_V, -1);
		queue<int> Q;
		Q.push(S);
		//bfs 로 흐를 수 있는 곳 path 찾기
		while (!Q.empty()) {
			int curr = Q.front();
			Q.pop();
			for (auto &next : adj[curr]) {
				if (c[curr][next] - f[curr][next] > 0 && prev[next] == -1) {
					Q.push(next);
					prev[next] = curr;
					if (next == T) break;
				}
			}
		}
		//찾은 path 가 없다면 break
		if (prev[T] == -1) break;
		//path 상에서 흐를 수 있는 최대만큼
		int flow = INF;
		for (int i = T; i != S; i = prev[i])
			flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
		//흘려준다.
		for (int i = T; i != S; i = prev[i]) {
			f[prev[i]][i] += flow;
			f[i][prev[i]] -= flow;	//역방향도 꼭 !!!!
		}
		total += flow;				//총 유량 값.
	}
	printf("%d\n", total);
	//system("pause");
	return 0;
}