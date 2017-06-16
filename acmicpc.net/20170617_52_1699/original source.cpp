//20170617. 2294 동전2 문제와 비슷.
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int main() {
	int dp[100001] = { 0, };
	int n, r;
	cin >> n; r = pow(n, 0.5);
	for (int i = 1; i <= n; i++) dp[i] = 987654;
	for (int i = 0; i <= r; i++) {
		for (int j = i*i; j <= n; j++)
			dp[j] = min(dp[j], dp[j - i*i] + 1);
	}
	cout << dp[n] << endl;
	//cin >> n;
	return 0;
}