//20170807 16:30 ~ 16:54

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int v;
vector<vector<pair<int, int>>> edge;
int visited[100000];
int ans;

//startNodeNum���κ��� ���� �� ����, �� �Ÿ� ��ȯ.
pair<int, int> bfs(int startNodeNum) {
	pair<int, int> ret = { startNodeNum, 0 };
	queue<pair<int, int>>q;
	q.push({ startNodeNum, 0 });
	visited[startNodeNum] = 1;
	while (!q.empty()) {
		int currNode = q.front().first;
		int currDistance = q.front().second;
		if (currDistance > ret.second) {
			ret.first = currNode;
			ret.second = currDistance;
		}
		q.pop();
		for (auto &i : edge[currNode]) {
			if (visited[i.first] != 1) {
				visited[i.first] = 1;
				q.push({ i.first, currDistance + i.second });
			}
		}
	}
	return ret;
}

int main() {
	cin >> v;
	edge.resize(v);
	//�Է�
	for (int i = 0; i < v; i++) {
		int nodeNum, nodeNum2, distance;
		scanf("%d", &nodeNum);
		scanf("%d", &nodeNum2);
		while (nodeNum2!=-1) {
			scanf("%d", &distance);
			edge[nodeNum - 1].push_back({ nodeNum2 - 1, distance });//vector idx start from 0!!
			edge[nodeNum2 - 1].push_back({ nodeNum - 1, distance });
			scanf("%d", &nodeNum2);
		}
	}
	//�� ���� bfs
	for (int i = 0; i < v; i++)
		visited[i] = -1;
	int endOfDiameterNode = bfs(0).first;
	for (int i = 0; i < v; i++)
		visited[i] = -1;
	ans = bfs(endOfDiameterNode).second;
	
	cout << ans << endl;
	//system("pause");
	return 0;
}