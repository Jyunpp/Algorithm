//20170901 08:59 ~ 11:14 (���������)
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int T, W;
int dp[31][1001][3];	//dp[i][j][k] : ���� Ƚ���� i��, ���� j��, k�� �Ʒ� �� �� �ִ� �Դ� ����
int arr[1001];

int main() {
	scanf("%d %d", &T, &W);
	for (int i = 1; i <= T; i++)
		scanf(" %d", &arr[i]);
	dp[W][1][1] = (arr[1] == 1);
	dp[W][1][2] = 0;
	dp[W - 1][1][2] = (arr[1] == 2);
	//i�� �� ��
	for (int i = 2; i <= T; i++) {
		int curr = arr[i];
		int other = 3 - curr;
		//j�� ������ ���� ä��� ���ؼ�
		for (int j = W; j >= 0; j--) {
			//�̵����� ���� ����
			dp[j][i][curr] = max(dp[j][i][curr], dp[j][i - 1][curr] + 1);
			dp[j][i][other] = max(dp[j][i][other], dp[j][i - 1][other]);
			//�̵��� ��츦 ���.
			if (j + 1 <= W) {
				dp[j][i][curr] = max(dp[j][i][curr], dp[j + 1][i - 1][other] + 1);
				dp[j][i][other] = max(dp[j][i][other], dp[j + 1][i - 1][curr]);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= W; i++)
		ans = max(max(ans, dp[i][T][1]), dp[i][T][2]);
	printf("%d\n", ans);
	//system("pause");
	return 0;
}