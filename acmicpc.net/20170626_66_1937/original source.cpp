//20170626
#include <iostream>
#include <algorithm>
using namespace std;

int arr[502][502];
int dp[502][502];
int n;
int ans;
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int dfs(int y, int x);

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ans = max(ans, dfs(i, j));
		}
	}
	cout << ans << endl;
	/*system("pause");*/
	return 0;
}

int dfs(int y, int x) {
	int &ret = dp[y][x];
	if (ret) { return ret; }
	int here = arr[y][x];
	for (int i = 0; i < 4; i++) {
		int there = arr[y + dy[i]][x + dx[i]];
		if (there > here) {
			ret = max(ret, dfs(y + dy[i], x + dx[i]));
		}
	}
	ret++;
	return ret;
}