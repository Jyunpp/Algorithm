//20170731 03:58 ~ 04:34 ~ 05:08 
//�� Ǯ�����.. �ð��ʰ� �߱淡 �̰� ���̾ȵŴµ�.. �ʹٰ� cin, cout�� 10������ �ϴϱ� �ߴ±���.. �ϰ� ���޾Ҵ�..!
#include <iostream>
#include <stdio.h>
using namespace std;

int k, c, m, n;
int dp[1001][1001];

void solve() {
	for (int i = 0; i <= k; i++)
		dp[i][i] = 1;
	for (int i = 0; i <= k; i++) {
		for (int j = 0; j <= k; j++) {
			//i�� i-1���� i�Ǵ� ���� ���� ��, j���� �ִ� ���� �� k-i+1.
			//=> (k-i+1) + j ���� i�� ���Ѱ� �Ǵ� ���� ������ ����. i-1�� ���Ѵ� ���� �Ұ���.
			if (i > j && !(k - i + 1 + j < i - 1)) {
				dp[i][j] = 1; continue;
			}
			//j�� j-1���� j�Ǵ� ���� ���� ��, i���� �ִ� ���� �� k-j
			//=> (k-j) + i ���� j�� ���Ѱ� �Ǵ� ���� ������ ����, j-1�� ���Ѵ� ���� �Ұ���.
			if (i < j && !(k - j + i < j - 1))
				dp[i][j] = 1;
		}
	}
	return;
}

int main() {
	cin >> k >> c;
	solve();
	for (int i = 1; i <= c; i++) {
		scanf("%d %d", &m, &n);
		printf("%d\n", dp[m][n]);
	}
	//system("pause");
	return 0;
}