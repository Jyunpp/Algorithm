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

int n, m, h[50001];	   //���� h, height ���� depth �ǹ�..
int maxH;
int parent[50001][20]; //parent[i][j] : i����� 2^j��° �θ���
vector<vector<int>> edge;

//1���� ��Ʈ���� �ϴ� tree�� �ٲ��ָ�, height�� �����ش�.
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
	for (int j = 0; j <= maxH; j++) {//�����
		for (int i = 1; i <= n; i++) {//���� �ٲ㼭 �ᰡ���� 10�ð� ������......................................
			int pparent = parent[parent[i][j]][j];	//i�� 2^j�� ° �θ��� 2^j�� ° �θ��
			parent[i][j + 1] = pparent;				//i�� 2^(j+1)�� ° �θ��̴�
		}
	}
}

int lca(int a, int b) {
	//���̰� �ٸ��� ���̸� ������.
	if (h[a] != h[b]) { 
		//h[b]>=h[a] ���¿��� b�� ���������� ���� ���̸� ����.
		if (h[a] > h[b])
			swap(a, b);
		
		for (int i = maxH; i >= 0; i--) {
			//b�� a�� �������ų� �� �Ʒ����� �� ��� �ö� => �ᱹ ������.
			if (h[parent[b][i]] >= h[a])
				b = parent[b][i];
		}
	}
	int lca = a;
	//���̸� ���� ���̶�� �ٽ� �÷���.
	if (a != b) {
		for (int i = maxH; i >= 0; i--) {
			//�ؿ� �ټ����� �����ϳ�.
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
	//�Է�
	scanf("%d", &n);
	edge.resize(n + 1);
	maxH = (int)floor(log2(n));
	for (int i = 1, a, b; i < n; i++) {
		scanf("%d %d", &a, &b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	//treeȭ, height ��ó��
	dfs(1, 0, 1);	
	
	//parent ��ó��
	fillParent();
	//����
	scanf("%d", &m);
	for (int i = 1, a, b; i <= m; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", lca(a, b));
	}
	//system("pause");
	return 0;
}