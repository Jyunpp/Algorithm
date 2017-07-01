#include<iostream>
#include<algorithm>
using namespace std;

int dp[1001], arr[1001], n, ans;

int main() {
	cin >> n;
	arr[0] = 1001;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		for (int j = 0; j <= i; j++) {
			if (arr[j] > arr[i])
				dp[i] = max(dp[i], 1 + dp[j]);
		}
	}
	for (int i = 1; i <= n; i++)
		ans = max(ans, dp[i]);
	cout << ans << endl;
	/*system("pause");*/
	return 0;
}