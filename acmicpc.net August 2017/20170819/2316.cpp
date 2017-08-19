//20170819 21:20 ~ 
/*
	1, 2�� �Դٰ��� �ϴ� Ƚ���� (�Դٵ� 1��, ���ٵ� 1������ ĥ ��)
	1->2�� �� �� �ִ� ����� ��. �� ��, ������ �� ������ ���.
	1->?, ?->2 ���� ��� ������ capacity�� 1�� ����. 
	������ �ϳ��� ������ �� �������� ����, capacity�� 1�� ���� => ���� �� ���� ��밡��
	   �� ��!! i->i�� c[i][i]�� ������������, ���ο� ���� �׳� ������ ��!
	   ���ƿ� �� �ֵ��� !!!! �ڡ�
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
int c[801][801];		//���� 400����������, �� a�� a�� a+400�� ����.
int f[801][801];		//�׻� a->b �̵� ���ؼ��� a -> a+400 ->b�� �Ѵ�.
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
		c[1][401] = c[401][i] = c[400 + i][2] = 987654321;	//����� 1�� ��쵵 ���ܾ�����.
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
