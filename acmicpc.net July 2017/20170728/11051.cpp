/*  2016.12.08
*   acmicpc.net 11050 이항계수
*   2248 이진수 찾기 에서 이용하려고 먼저 푼 문제
*
*/
//20170729 다시 해줌.
int binoDp[1001][1001];
int MOD = 10007;
#include <iostream>
using namespace std;

int bino(int n, int r);

int main() {
	int N, K;
	cin >> N >> K;
	cout << bino(N, K);
	system("pause");
	return 0;
}

int bino(int n, int r) {
	int &ret = binoDp[n][r];
	if (ret) return ret;
	if (n == r || r == 0) return 1;
	return ret = ((bino(n - 1, r - 1) + bino(n - 1, r)) % MOD);
}