//20170807 17:46 ~ 19:44 왜틀렸단거야 ㅡㅡ

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
int dp[2][10001]; //dp[0][i] : i행의 최저 열, dp[1][i] : i행의 최고 열
int column = 1;
int rootIdx;

//inorder로 순회하며 열을 기록, 아울러 각 행의 최저 최고 열 갱신.
void inorder(int rootNode) {
	if (arr[rootNode].leftIdx != -1)
		inorder(arr[rootNode].leftIdx);

	//중위 순회로 기록.
	arr[rootNode].column = column++;
	//이번 column이 최저라면 최저 열 갱신.
	dp[0][arr[rootNode].row] = min(dp[0][arr[rootNode].row], arr[rootNode].column);
	//이번 column이 최고라면 최고 열 갱신
	dp[1][arr[rootNode].row] = max(dp[1][arr[rootNode].row], arr[rootNode].column);

	if (arr[rootNode].rightIdx != -1)
		inorder(arr[rootNode].rightIdx);
}

int main() {
	//n입력
	cin >> n;
	//dp초기화, arr초기화
	for (int i = 1; i <= n; i++) {
		dp[0][i] = 987654321;
		dp[1][i] = 0;
		arr[i].leftIdx = arr[i].rightIdx = -1;
		parentIdx[i] = 0;
	}
	//입력
	for (int i = 1, a, b, c; i <= n; i++) {
		scanf("%d %d %d", &a, &b, &c);
		arr[a].leftIdx = b;
		arr[a].rightIdx = c;
		parentIdx[b] = a;
		parentIdx[c] = a;
	}
	//루트노드 찾기
	for (int i = 1; i <= n; i++) {
		if (parentIdx[i] == 0) {
			rootIdx = i;
			break;
		}
	}
	//bfs로 행을 기록해 준다. 아울러 최고 행을 기록해준다. => 답 찾을 때 이용.
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
	//reculsive inorder traversal 을 이용해 열을 기록하며 dp를 갱신 시켜준다.
	inorder(rootIdx);
	//순회하며 답을 찾음
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
