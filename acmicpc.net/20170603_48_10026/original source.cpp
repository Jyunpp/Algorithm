//20170603 22:53 ~ 23:10 
#include <iostream>
using namespace std;

char arr[2][101][101];
int n;
int dy[4] = { 1, -1, 0 , 0 };
int dx[4] = { 0, 0, -1, 1 };
int ans[2] = { 0, 0 };

void dfs(int k, int y, int x, char here);

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[0][i][j];
			arr[1][i][j] = arr[0][i][j];
			if (arr[1][i][j] == 'R') { arr[1][i][j] = 'G'; }
		}
	}
	for (int k = 0; k < 2; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				char here = arr[k][i][j];
				if (here != 'x') {
					dfs(k, i, j, here);
					ans[k] ++;
				}

			}
		}
	}
	cout << ans[0] << " " << ans[1] << endl;
	/*cin >> n;*/
	return 0;
}
void dfs(int k, int y, int x, char here) {
	arr[k][y][x] = 'x';
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny > 0 && nx > 0 && ny <= n && nx <= n && arr[k][ny][nx] == here) {
			dfs(k, ny, nx, here);
		}
	}
}