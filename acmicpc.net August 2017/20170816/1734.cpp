//20170816 04:54 ~ 23:38
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int V, E, Q;
int cnt = 0;
vector<vector<int>> edge;
//classified
vector<vector<int>> child;

void dfs(int curr, int parent, int d) {
	//classified
}

//classified

//classified

int main() {
	//입력 및 vector들 크기 조정.
	scanf("%d %d", &V, &E);
	edge.resize(V);
	discover = finish = lowlink = depth = vector<int>(V, -1);
	child.resize(V);
	for (int i = 1, a, b; i <= E; i++) {
		scanf(" %d %d", &a, &b); --a; --b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	//classified

	//쿼리
	for (scanf(" %d", &Q); Q--;) {
		int opt, a, b, c, d;
		scanf(" %d %d %d %d", &opt, &a, &b, &c); --a; --b; --c;
		
		if (opt == 1) {
			//classified
		}
		
		else{
			//classified
			}
		}
	}
	//system("pause");
	return 0;
}