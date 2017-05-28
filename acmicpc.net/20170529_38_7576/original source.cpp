#include <iostream>
#include <utility>
#include <queue>

using namespace std;
int previous;
int total;
int riped = 0;
int ans = 0;
int n, m;
int arr[1001][1001];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int main() {
	cin >> m >> n;
	total = m*n;
	queue<pair<int, int>> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) { q.push({ i, j }); riped++; }
			else if (arr[i][j] == -1) { total--; }
		}
	}
	if (riped == 0) { cout << -1 << endl; return 0; }
	while (!q.empty()) {
		int qsize = q.size();
		if (total == riped) { break; }
		previous = riped;
		//while 안에서 주변에 익게되면 riped값 바꿈.
		while (qsize--) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if ((nx*ny != 0) && (ny <= n) && (nx <= m) && (arr[ny][nx] == 0)) {
					arr[ny][nx] = 1;
					q.push({ ny, nx });
					riped++;
				}
			}
		}
		//그대로면 다 익힐 수 없단 소리.
		if (previous == riped) { cout << -1 << endl; return 0; }
		ans++;
	}
	cout << ans << endl;
	/*cin >> m;*/
	return 0;
}