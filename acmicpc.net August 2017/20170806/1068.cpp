//20170806 17:29 ~ 18:16
/*
	처음에, bfs중 삭제 노드를 만나면 그 노드의 자식노드들을 push하지 않고
	무시하는 방법을 사용했다.
	=> 그 노드 삭제시, 삭제 노드의 부모가 leaf이 되는 경우를 고려 못시킴.

	=> 귀찮더라도 삭제하는 것을 고려해주던지, 예외를 잘 생각해주던지 하자..
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