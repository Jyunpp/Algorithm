//20170731 03:58 ~ 04:34 ~ 05:08 
//다 풀어놓고.. 시간초과 뜨길래 이게 말이안돼는데.. 싶다가 cin, cout을 10만번씩 하니까 뜨는구나.. 하고 깨달았다..!
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
			//i가 i-1에서 i되는 순간 끝난 것, j에게 최대 남은 판 k-i+1.
			//=> (k-i+1) + j 점이 i를 못넘게 되는 순간 까지는 가능. i-1를 못넘는 것은 불가능.
			if (i > j && !(k - i + 1 + j < i - 1)) {
				dp[i][j] = 1; continue;
			}
			//j가 j-1에서 j되는 순간 끝난 것, i에게 최대 남은 판 k-j
			//=> (k-j) + i 점이 j를 못넘게 되는 순간 까지는 가능, j-1를 못넘는 것은 불가능.
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