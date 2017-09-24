//20170924 16:54 ~ 18:11
/*
	처음에 30입력 시 답을 보고 그만큼 연산을 해야하는가 싶어서 수학적으로 접근하려 했다.
	그러나, 그건 값일 뿐 연산 횟수가 아니었다.
	dp를 저렇게 잡으면, 최대연산 횟수는 30*60으로 1800번 밖에 되지 않는다.
	dp를 잘 잡도록 하자.
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
long long dp[31][61];	//dp[i][j] : 통 안에 i개의 반알, j개의 남은 일수

long long recur(int half, int remain){
	//dp
	long long &ret = dp[half][remain];
	//종료조건
	if (ret != -1) return ret;
	if (remain == 0) return 1;														//남은 일수가 없다면 1
	//recur
	if (half == 0) return ret = recur(1, remain - 1);								//남은게 모두 한알
	else if (half == remain) return ret = recur(half - 1, remain - 1);				//남은게 모두 반알
	else return ret = recur(half - 1, remain - 1) + recur(half + 1, remain - 1);	//두 가지 모두가능
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
