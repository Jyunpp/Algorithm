//20170909 09:58 ~ 10:09
/*
	아이디어, 구현 모두 깔끔!!
	판교로 떠나 봅시다~
*/
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
using namespace std;

int arr[101];
int dp[102];	// there are w+1 spaces
int hap[102];
int ans[101];
int w, p;

int main() {
	//input & fill dp. (dp : each space between bars, the number of dp : p+1)
	scanf("%d %d", &w, &p);
	int prev = 0;
	for (int i = 1; i <= p; i++) {
		scanf(" %d", &arr[i]);
		dp[i] = arr[i] - prev;
		prev = arr[i];
	}
	dp[p + 1] = w - prev;
	//partial sum
	for (int i = 1; i <= p + 1; i++) {
		hap[i] = hap[i - 1] + dp[i];
	}
	//fill ans
	for (int i = 1; i <= p + 1; i++) {
		for (int j = i; j <= p + 1; j++) {
			int idx = hap[j] - hap[j - i];
			ans[idx] = 1;
		}
	}
	for (int i = 1; i <= 100; i++) {
		if (ans[i]) printf("%d ", i);
	}
//	system("pause");
	return 0;
}