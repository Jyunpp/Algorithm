//20170810 16:00 ~ 20170811 03:50
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, h[50001];	   //쓰긴 h, height 지만 depth 의미..
int maxH;
int parent[50001][20]; //parent[i][j] : i노드의 2^j번째 부모노드
vector<vector<int>> edge;

//1번을 루트노드로 하는 tree로 바꿔주며, height를 구해준다.
void dfs(int currIdx, int parentIdx, int height) {
	parent[currIdx][0] = parentIdx;
	h[currIdx] = height;
	int len = edge[currIdx].size();
	int i = 0;
	while(len--){
		if (edge[currIdx][i] == parentIdx) {
			edge[currIdx].erase(edge[currIdx].begin() + i);
		}
		else {
			dfs(edge[currIdx][i], currIdx, height + 1);
			i++;
		}
	}
}

void fillParent() {
	for (int j = 0; j <= maxH; j++) {//여기랑
		for (int i = 1; i <= n; i++) {//여기 바꿔서 써가지고 10시간 날린듯......................................
			int pparent = parent[parent[i][j]][j];	//i의 2^j번 째 부모의 2^j번 째 부모는
			parent[i][j + 1] = pparent;				//i의 2^(j+1)번 째 부모이다
		}
	}
}

int lca(int a, int b) {
	//높이가 다르면 높이를 맞춰줌.
	if (h[a] != h[b]) { 
		//h[b]>=h[a] 상태에서 b를 조상쪽으로 보내 높이를 맞춤.
		if (h[a] > h[b])
			swap(a, b);
		
		for (int i = maxH; i >= 0; i--) {
			//b가 a와 같아지거나 그 아래있을 때 계속 올라감 => 결국 같아짐.
			if (h[parent[b][i]] >= h[a])
				b = parent[b][i];
		}
	}
	int lca = a;
	//높이만 같은 것이라면 다시 올려줌.
	if (a != b) {
		for (int i = maxH; i >= 0; i--) {
			//밑에 다섯줄이 굉장하네.
			if (parent[a][i] != parent[b][i]){
				a = parent[a][i];
				b = parent[b][i];
			}
			lca = parent[a][i];
		}
	}
	return lca;
}

int main() {
	//입력
	scanf("%d", &n);
	edge.resize(n + 1);
	maxH = (int)floor(log2(n));
	for (int i = 1, a, b; i < n; i++) {
		scanf("%d %d", &a, &b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	//tree화, height 전처리
	dfs(1, 0, 1);	
	
	//parent 전처리
	fillParent();
	//쿼리
	scanf("%d", &m);
	for (int i = 1, a, b; i <= m; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", lca(a, b));
	}
	//system("pause");
	return 0;
}