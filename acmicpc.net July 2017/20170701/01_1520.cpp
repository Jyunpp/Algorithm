//20170701 02:45 ~ 03:00
#include <iostream>
using namespace std;

int m, n, arr[501][501], dp[501][501];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int visited[501][501];
int solve(int y, int x);

int main() {
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			visited[i][j] = -1;
		}
	}
	cout << solve(m, n);
	//system("pause");
	return 0;
}

int solve(int y, int x) {
	int &ret = dp[y][x];
	if (ret || visited[y][x] != -1) return ret;
	if (y == 1 && x == 1) return 1;
	int here = arr[y][x];
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny*nx == 0 || ny > m || nx > n) continue;
		int prev = arr[ny][nx];
		if (prev > here) {
			ret += solve(ny, nx);
		}
	}
	visited[y][x] = 1;
	return ret;
}