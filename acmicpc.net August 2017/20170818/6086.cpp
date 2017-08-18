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
	int N;							//���� ��
	int c[MAX_V][MAX_V] = { 0 };	//i->j �뷮
	int f[MAX_V][MAX_V] = { 0 };	//i->j ����
	vector<int> adj[MAX_V];			//���� ����Ʈ

	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		char u, v;
		int ui, vi;
		int w;
		scanf(" %c %c %d", &u, &v, &w);
		ui = CtoI(u); vi = CtoI(v);
		c[ui][vi] += w;				//���� ���� ���� �� �Է� ����.
		adj[ui].push_back(vi);
		adj[vi].push_back(ui);		//�����⵵ �� �߰��϶��ϴ�..
	}

	int total = 0, S = CtoI('A'), T = CtoI('Z');
	//�带 �� �ִ� path�� ���� �� ���� path ã��.
	while (1) {
		int prev[MAX_V];
		fill(prev, prev + MAX_V, -1);
		queue<int> Q;
		Q.push(S);
		//bfs �� �带 �� �ִ� �� path ã��
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
		//ã�� path �� ���ٸ� break
		if (prev[T] == -1) break;
		//path �󿡼� �带 �� �ִ� �ִ븸ŭ
		int flow = INF;
		for (int i = T; i != S; i = prev[i])
			flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
		//����ش�.
		for (int i = T; i != S; i = prev[i]) {
			f[prev[i]][i] += flow;
			f[i][prev[i]] -= flow;	//�����⵵ �� !!!!
		}
		total += flow;				//�� ���� ��.
	}
	printf("%d\n", total);
	//system("pause");
	return 0;
}