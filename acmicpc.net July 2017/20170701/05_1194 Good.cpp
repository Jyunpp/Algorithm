//20170701 16:34 ~ 17:42
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, ans;
int sy, sx;
char arr[51][51];
int visited[51][51][1<<6];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

struct Pos {
	int y, x;
	int key; // 비트
};

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == '0') {
				sy = i; sx = j;
			}
		}
	}
	queue<Pos> q;
	q.push({ sy, sx, 0 });
	visited[sy][sx][0] = 1;
	while (!q.empty()) {
		ans++;
		int sz = q.size();
		while (sz--) {
			int y = q.front().y;
			int x = q.front().x;
			int key = q.front().key;
			//cout << "현재, " << ans << "번 째 이동. (" << y << ", " << x << ", " << key << ") 에서 출발!!" << endl;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				int nk = key;
				char next = arr[ny][nx];
				//범위 내 & 방문한 적 없다면.
				if (nx*ny != 0 && ny <= n && nx <= m && visited[ny][nx][key] == 0) {
					//벽
					if (next == '#') continue;
					//도착
					else if (next == '1') {
						cout << ans << endl;
						//system("pause");
						return 0;
					}
					//키 획득
					else if (next >= 'a' && next <= 'f') {
						nk = key | 1 << (next - 'a');
						//arr[ny][nx] = '.';
					}
					//키 사용을 넣을 필요가 없다. 여러 번 사용 가능.
					//else if (next >= 'A' && next <= 'F' && key & 1 << (next - 'A'))
					//	nk = key & ~(1 << (next - 'A'));

					//키가 없다.
					else if (next >= 'A' && next <= 'F' && !( key & 1 << (next - 'A') ))
						continue;
					//방문.
					q.push(Pos{ ny, nx, nk });
					visited[ny][nx][key] = 1;//키 획득 전의 상태로 방문 했던 것.★
				}
			}
		}
	}
	cout << -1 << endl;
	//system("pause");
	return 0;
}