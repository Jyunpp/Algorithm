//20170531
//1260문제에서 루프를 돌려서 실행.
#include <iostream>
using namespace std;

int n;
int arr[2][101][101];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void dfs(int y, int x);

int main() {
	cin >> n;
	int maxHeight = 0;
	int ans = 0;
	for(int i=1; i<=n; i++){
		for (int j = 1; j <= n; j++) {
			cin >> arr[0][i][j];
			maxHeight = (maxHeight > arr[0][i][j] ? maxHeight : arr[0][i][j]);
		}
	}
	for (int h = 0; h < maxHeight; h++) {
		int tempans = 0;
		//매 시행 시 초기화.
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				arr[1][i][j] = arr[0][i][j] - h;
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (arr[1][i][j] > 0) {
					tempans++;
					dfs(i, j);
				}
			}
		}
		ans = (tempans > ans ? tempans : ans);
	}
	cout << ans << endl;
	/*cin >> n;*/
	return 0;
}

void dfs(int y, int x) {
	arr[1][y][x] = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny > 0 && nx > 0 && ny <= n && nx <= n && arr[1][ny][nx] > 0) {
			dfs(ny, nx);
		}
	}
}