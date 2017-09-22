//20170921 22:51 ~ 23:53
//20170922 02:31 ~ 

//n이 클 때는 지수적 접근을 하자.
//int범위 안넘더라도, 그걸 가지고 연산해서 long long에 넣기전에 int범위를 넘을 수 있다면
//long long으로 저장하자!	★

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
	//전처리
	dp[0] = 1;
	dp[1] = 2;
	for (int i = 2; i <= 40; i++) {
		dp[i] = (dp[i - 1] * dp[i - 1]) % mod;		//여기 잘못해서 많이 헤맴.
	}
	//입력 및 계산
	long long ans = 0;
	cin >> n;
	for (int i = 1, C; i <= n; i++) {
		long long K;								//K를 long long으로 안해서 헤맴...
		scanf(" %d %lld", &C, &K);
		if (K == 0 || C == 0) { continue; }
		int currPower = K - 1;
		long long currNum = (K * C) % mod;			//currNum에 넣기 전에 K*C값이 int를 넘어설 수 있음.
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