//20170908 21:09 ~ 21:44 (소방차 와서..)
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int dp[1000001];

int main() {
	int n, t = 0;
	long long ans;
	for (int i = 5; i <= 1000000; i *= 5) {
		for (int j = 1; 1; j++) {
			long long curr = j*i;
			if (curr > 1000000) { break; }
			dp[curr]++;
		}
	}
	while (1) {
		t++;
		scanf("%d", &n);
		if (!n) break;
		ans = 0;
		for (int i = 1; i <= n; i++) {
			ans += dp[i];
		}
		cout << "Case #" << t << ": " << ans << endl;
	}
	//system("pause");
	return 0;
}