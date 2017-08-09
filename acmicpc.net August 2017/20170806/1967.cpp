//20170806 15:33 ~ 17:22
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>
using namespace std;

pair<int, int> parent[10000];
vector<vector<pair<int,int>>> child;	//두 번째 인자 : 가중치
int n, visited[10000];

//sNodeIdx에서 시작해서 가장 먼 노드, 그 길이 반환.
pair<int, int> dfs(int sNodeIdx) {
	pair<int, int> ret = { sNodeIdx, 0 };
	visited[sNodeIdx] = 1;
	stack<pair<int, int>> s;			//두 번째 인자 : 가중치
	s.push({ sNodeIdx,0 });
	
	while (!s.empty()) {
		int currNode = s.top().first;
		int currDistance = s.top().second;
		if (currDistance > ret.second)	//가장 먼 노드 갱신.
			ret = { currNode, currDistance };
		s.pop();
		//부모노드 있을 시 고려
		if (parent[currNode].first != -1 && visited[parent[currNode].first] != 1) {
			s.push({ parent[currNode].first,currDistance + parent[currNode].second });
			visited[parent[currNode].first] = 1;
		}
		//모든 자녀노드 고려.
		//for (auto i = child[currNode].begin(); i != child[currNode].end(); i) {
		for(auto &i : child[currNode]){
			if (visited[i.first] != 1) {
				s.push({ i.first, currDistance + i.second });
				visited[i.first] = 1;
			}
		}
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	child.resize(n);
	for (int i = 1, a, b, c; i < n; i++) {
		scanf("%d %d %d", &a, &b, &c);
		parent[b - 1] = { a - 1,c };			//idx는 0부터!!
		child[a - 1].push_back({ b - 1,c });	//idx는 0부터!!
	}
	parent[0] = { -1,-1 };
	//두 번의 visited초기화 , dfs 를 통해 트리의 지름을 구한다.
	for (int i = 0; i < n; i++)
		visited[i] = 0;
	int edgeIdx = dfs(0).first;
	for (int i = 0; i < n; i++)
		visited[i] = 0;
	int ans = dfs(edgeIdx).second;
	cout << ans << endl;
	//system("pause");
	return 0;
}