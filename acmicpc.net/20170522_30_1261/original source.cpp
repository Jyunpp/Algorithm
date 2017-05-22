#include <iostream>
#include <queue>
using namespace std;

#define INF 987654321

struct Pos {
	int y, x;
};

int n, m;
char arr[101][101];
int dp[101][101];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int main() {
	cin >> m >> n;//입력 순서 잘보자.. 가로 세로 순으로 입력 받음.
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			dp[i][j] = INF;
		}
	}
	queue<Pos>q;
	q.push(Pos{ 1, 1 });
	dp[1][1] = 0;
	
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			//이동 가능한 범위라면.
			if (nx*ny != 0 && ny <= n && nx <= m) {
				int needBreak = (arr[ny][nx] == '1' ? 1 : 0); //이동을 위해 부술 필요가 있다면 1
				if (dp[ny][nx] > dp[y][x] + needBreak) {
					//cout << "dp[" << ny << "][" << nx << "] = " << dp[y][x] + needBreak << endl;
					dp[ny][nx] = dp[y][x] + needBreak;
					q.push(Pos{ ny, nx });
				}
			}
		}
	}
/* test 하려고 출력한 부분.
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
*/
	cout << dp[n][m] << endl;
	/*cin >> n;*/
	return 0;
}