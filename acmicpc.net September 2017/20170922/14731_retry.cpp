//20170921 22:51 ~ 23:53
//20170922 02:31 ~ 

//n�� Ŭ ���� ������ ������ ����.
//int���� �ȳѴ���, �װ� ������ �����ؼ� long long�� �ֱ����� int������ ���� �� �ִٸ�
//long long���� ��������!	��

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#define xx first
#define yy second
#define mod 1000000007

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>
using namespace std;

int n;
long long dp[41];

int main() {
	//��ó��
	dp[0] = 1;
	dp[1] = 2;
	for (int i = 2; i <= 40; i++) {
		dp[i] = (dp[i - 1] * dp[i - 1]) % mod;		//���� �߸��ؼ� ���� ���.
	}
	//�Է� �� ���
	long long ans = 0;
	cin >> n;
	for (int i = 1, C; i <= n; i++) {
		long long K;								//K�� long long���� ���ؼ� ���...
		scanf(" %d %lld", &C, &K);
		if (K == 0 || C == 0) { continue; }
		int currPower = K - 1;
		long long currNum = (K * C) % mod;			//currNum�� �ֱ� ���� K*C���� int�� �Ѿ �� ����.
		int idx = 1;
		while (currPower) {
			if (currPower % 2) {
				currNum *= dp[idx];
				currNum %= mod;
			}
			currPower /= 2;
			idx++;
		}
		ans += currNum;
		ans %= mod;
	}
	cout << ans << endl;
	//system("pause");
	return 0;
}