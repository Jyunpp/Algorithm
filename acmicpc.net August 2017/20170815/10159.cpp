//20170815 05:18 ~ 05:52
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
using namespace std;

int n, m;
int dp[101][101];	//dp[i][j] : 0 �񱳺Ұ�// 1 i���� j�� ����

int main() {
	//n, m �Է� �� dp �ʱ�ȭ
	cin >> n;
	cin >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) dp[i][j] = 3;
			else dp[i][j] = 0;
		}
	}
	//�� �Է� �� dp ����
	for (int i = 1, a, b; i <= m; i++) {
		scanf(" %d %d", &a, &b);	//weight : a>b
		dp[a][b] = 1;
	}
	//�÷��̵� �ͼ�?�� dpä���
	for (int k = 1; k <= n; k++) {	//�÷��̵� �ͼ� k�� �߽����� ���� �� �߿��
									//�׷���, �������� �ϼ�, ���žȵǰ� ���� ���Ÿ���Ű�� ��찡 ����.
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;
				//dp[i][j]�� ä���.
				if (dp[i][k] == dp[k][j] && dp[i][k])
					dp[i][j] = dp[i][k];
			}
		}
	}
	//�� ���
	for (int i = 1; i <= n; i++) {
		int ans = 0;
		for (int j = 1; j <= n; j++)
			if (dp[i][j] || dp[j][i])ans++;
		printf("%d\n", n - ans);
	}
	//system("pause");
	return 0;
}