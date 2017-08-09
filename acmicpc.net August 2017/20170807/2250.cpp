//20170807 17:46 ~ 19:44 ��Ʋ�ȴܰž� �Ѥ�

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
	int leftIdx;
	int rightIdx;
	int row;
	int column;
};

int n;
Node arr[10001];
int parentIdx[10001];
int dp[2][10001]; //dp[0][i] : i���� ���� ��, dp[1][i] : i���� �ְ� ��
int column = 1;
int rootIdx;

//inorder�� ��ȸ�ϸ� ���� ���, �ƿ﷯ �� ���� ���� �ְ� �� ����.
void inorder(int rootNode) {
	if (arr[rootNode].leftIdx != -1)
		inorder(arr[rootNode].leftIdx);

	//���� ��ȸ�� ���.
	arr[rootNode].column = column++;
	//�̹� column�� ������� ���� �� ����.
	dp[0][arr[rootNode].row] = min(dp[0][arr[rootNode].row], arr[rootNode].column);
	//�̹� column�� �ְ��� �ְ� �� ����
	dp[1][arr[rootNode].row] = max(dp[1][arr[rootNode].row], arr[rootNode].column);

	if (arr[rootNode].rightIdx != -1)
		inorder(arr[rootNode].rightIdx);
}

int main() {
	//n�Է�
	cin >> n;
	//dp�ʱ�ȭ, arr�ʱ�ȭ
	for (int i = 1; i <= n; i++) {
		dp[0][i] = 987654321;
		dp[1][i] = 0;
		arr[i].leftIdx = arr[i].rightIdx = -1;
		parentIdx[i] = 0;
	}
	//�Է�
	for (int i = 1, a, b, c; i <= n; i++) {
		scanf("%d %d %d", &a, &b, &c);
		arr[a].leftIdx = b;
		arr[a].rightIdx = c;
		parentIdx[b] = a;
		parentIdx[c] = a;
	}
	//��Ʈ��� ã��
	for (int i = 1; i <= n; i++) {
		if (parentIdx[i] == 0) {
			rootIdx = i;
			break;
		}
	}
	//bfs�� ���� ����� �ش�. �ƿ﷯ �ְ� ���� ������ش�. => �� ã�� �� �̿�.
	int maxRow = 0;
	queue<Node> q;
	arr[rootIdx].row = 1;
	q.push(arr[rootIdx]);
	while (!q.empty()) {
		int l = q.front().leftIdx;
		int r = q.front().rightIdx;
		int currRow = q.front().row;
		maxRow = max(maxRow, currRow);
		q.pop();
		if (l != -1) {
			arr[l].row = currRow + 1;
			q.push(arr[l]);
		}
		if (r != -1) {
			arr[r].row = currRow + 1;
			q.push(arr[r]);
		}
	}
	//reculsive inorder traversal �� �̿��� ���� ����ϸ� dp�� ���� �����ش�.
	inorder(rootIdx);
	//��ȸ�ϸ� ���� ã��
	int level = 1, width = 1;
	for (int i = 1; i <= maxRow; i++) {
		int temp = dp[1][i] - dp[0][i] + 1;
		if (width < temp) {
			level = i;
			width = temp;
		}
	}
	cout << level << " " << width << endl;
	//system("pause");
	return 0;
}
