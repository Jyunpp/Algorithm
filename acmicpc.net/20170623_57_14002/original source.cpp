//20170623
#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001], dp[1001], ans, N;
int bt[1001];
int previous;
int last; 
int main() {
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> arr[i];
		int here = 0;
		for (int j = 1; j < i; ++j) {
			if (arr[i] > arr[j])
				here = max(here, dp[j]);
		}
		dp[i] = here + 1;
		if (ans < dp[i]) {
			ans = dp[i];
			previous = bt[1] = arr[i];
			last = i;
		}
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
	ans--;
	int btIndex = 2;
	for (int i = last-1; i >= 1; i--) {
		if (dp[i] == ans && arr[i] < previous) {
			previous = bt[btIndex++] = arr[i];
			ans--;
		}
	}
	cout << bt[--btIndex];
	for (int i = btIndex -1; i >= 1; i--) {
		cout << " " << bt[i];
	}
	/*cin >> N;*/
	return 0;
}