//20170530
#include <iostream>
#include <queue>
using namespace std;

int t, I, sy, sx, ey, ex, ans;
int dy[8] = { 2, 2, 1, -1, -2, -2, -1, 1 };
int dx[8] = { -1, 1, 2, 2, 1, -1, -2, -2 };
int dp[301][301];

int main() {
	cin >> t;
	while (t--) {
		ans = 0;
		bool find;
		cin >> I >> sy >> sx >> ey >> ex;
		for (int i = 0; i < I; i++) {
			for (int j = 0; j < I; j++) {
				dp[i][j] = 0;
			}
		}
		queue<pair<int, int>> q;
		q.push({ sy, sx });
		dp[sy][sx] = 0;
		while (!q.empty()) {
			find = false;
			int sz = q.size();
			while (sz--) {
				int y = q.front().first;
				int x = q.front().second;
				int nowdp = dp[y][x];
				q.pop();
				if (y == ey && x == ex) { find = true; break; }
				for (int i = 0; i < 8; i++) {
					int ny = y + dy[i];
					int nx = x + dx[i];
					if (ny >= 0 && nx >= 0 && ny < I && nx < I && (dp[ny][nx] == 0 || dp[ny][nx] > nowdp + 1)) {
						dp[ny][nx] = nowdp + 1;
						q.push({ ny, nx });
					}
				}
			}
			if (find == true) { break; }
			ans++;
		}
		cout << ans << endl;
	}
	/*cin >> I;*/
	return 0;
}