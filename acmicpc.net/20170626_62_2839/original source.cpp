//20170626 07:38 ~ 07:51
#include <iostream>
#include <algorithm>
using namespace std;
#define INF 54321

int n;
int dp[5000];

int main() {
	cin >> n;
	dp[3] = dp[5] = 1; dp[1] = dp[2] = dp[4] = INF;
	for (int i = 5; i <= n; i++)
		dp[i] = min(dp[i - 3], dp[i - 5]) + 1;
	if (dp[n] >= INF) cout << -1 << endl;
	else cout << dp[n] << endl;
	/*system("pause");*/
	return 0;
}