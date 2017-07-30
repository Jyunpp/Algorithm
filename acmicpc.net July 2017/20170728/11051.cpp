/*  2016.12.08
*   acmicpc.net 11050 ���װ��
*   2248 ������ ã�� ���� �̿��Ϸ��� ���� Ǭ ����
*
*/
//20170729 �ٽ� ����.
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