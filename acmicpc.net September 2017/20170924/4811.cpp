//20170924 16:54 ~ 18:11
/*
	ó���� 30�Է� �� ���� ���� �׸�ŭ ������ �ؾ��ϴ°� �; ���������� �����Ϸ� �ߴ�.
	�׷���, �װ� ���� �� ���� Ƚ���� �ƴϾ���.
	dp�� ������ ������, �ִ뿬�� Ƚ���� 30*60���� 1800�� �ۿ� ���� �ʴ´�.
	dp�� �� �⵵�� ����.
*/
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#define xx first
#define yy second

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

long long ans[31];
long long dp[31][61];	//dp[i][j] : �� �ȿ� i���� �ݾ�, j���� ���� �ϼ�

long long recur(int half, int remain){
	//dp
	long long &ret = dp[half][remain];
	//��������
	if (ret != -1) return ret;
	if (remain == 0) return 1;														//���� �ϼ��� ���ٸ� 1
	//recur
	if (half == 0) return ret = recur(1, remain - 1);								//������ ��� �Ѿ�
	else if (half == remain) return ret = recur(half - 1, remain - 1);				//������ ��� �ݾ�
	else return ret = recur(half - 1, remain - 1) + recur(half + 1, remain - 1);	//�� ���� ��ΰ���
}

int main() {
	//dp preprocessing
	for (int i = 0; i <= 30; i++) {
		for (int j = 0; j <= 60; j++) {
			dp[i][j] = -1;
		}
	}
	//fill dp
	dp[0][2] = 1;
	for (int i = 1; i <= 30; i++)
		dp[i][i] = 1;
	dp[1][3] = dp[0][2] + dp[2][2];
	recur(0, 60);
	//fill ans
	for (int i = 1; i <= 30; i++)
		ans[i] = dp[0][i * 2];
	//do query
	while (1) {
		int n;
		cin >> n;
		if (n == 0) break;
		cout << ans[n] << endl;
	}
//	system("pause");
	return 0;
}
