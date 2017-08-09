//20170806 17:29 ~ 18:16
/*
	ó����, bfs�� ���� ��带 ������ �� ����� �ڽĳ����� push���� �ʰ�
	�����ϴ� ����� ����ߴ�.
	=> �� ��� ������, ���� ����� �θ� leaf�� �Ǵ� ��츦 ��� ����Ŵ.

	=> �������� �����ϴ� ���� ������ִ���, ���ܸ� �� �������ִ��� ����..
*/
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int n, m, ans = 0;
int parent[50];
vector<vector<int>> child;

int main() {
	cin >> n;
	child.resize(n);
	int root;
	for (int i = 0, input; i < n; i++) {
		scanf("%d", &input);
		parent[i] = input;
		if (input == -1) root = i;
		else child[input].push_back(i);
	}
	cin >> m;
	queue<int> q;
	q.push(root);
	while (!q.empty()) {
		int currIdx = q.front();
		q.pop();
		if (currIdx == m) {
			if (parent[m] == -1)
				continue;
			if (child[parent[m]].size() == 1)
				ans++;
			continue;
		}
		if (child[currIdx].size() == 0) ans++;
		for (auto &i : child[currIdx])
			q.push(i);
	}
	cout << ans << endl;
	//system("pause");
	return 0;
}