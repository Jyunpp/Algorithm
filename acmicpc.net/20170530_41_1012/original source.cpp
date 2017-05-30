//20170530
//ó���� ������ �߸� ����.. ������ �Ѹ����� �����¿��� �ټ�ĭ�� ������ �ִ� ��..
//�� ���� ��� �Դٰ��� �� �� �ִٴ� �ǹ�.

#include <iostream>
using namespace std;

int n, m, k, t;
int arr[50][50];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void dfs(int y, int x);

int main() {
	cin >> t;
	while (t--) {
		cin >> m >> n >> k;
		int x, y, ans = 0;
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			arr[y][x] = 1;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 1) {
					ans++;
					dfs(i, j);
				}
			}
		}
		cout << ans << endl;
	}
	/*cin >> t;*/
	return 0;
}

void dfs(int y, int x) {
	arr[y][x] = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= 0 && nx >= 0 && ny < n && nx < m && arr[ny][nx] == 1) {
			dfs(ny, nx);
		}
	}
}