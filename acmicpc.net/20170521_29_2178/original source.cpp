#include <iostream>
#include <queue>
using namespace std;

struct Pos {
	int y, x;
};

int n, m, dp[101][101];
char arr[101][101];
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,-1,1 };

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	queue<Pos> q;
	q.push(Pos{ 1, 1 });
	dp[1][1] = 1;
	
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			//맵 범위에 해당 && 첫 방문 && 이동 가능한 자리 => 방문해본다.
			if (ny*nx != 0 && ny <= n && nx <= m && dp[ny][nx] == 0 && arr[ny][nx] == '1') {
				q.push(Pos{ ny, nx });
				dp[ny][nx] = dp[y][x] + 1;
				//도착 시 바로 종료.
				if (ny == n&&nx == m) {
					break;
				}
			}
		}
	}
	cout << dp[n][m];
	//cin >> n;
	return 0;
}