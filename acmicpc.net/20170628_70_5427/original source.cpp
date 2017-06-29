//20170628 15:08 ~ 15:58
#include <iostream>
#include <queue>
using namespace std;

char arr[1002][1002];
int visited[1002][1002];
int tc, w, h, ans;
pair<int, int> s;
queue<pair<int, int>> fire;
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int main() {
	cin >> tc;
	while (tc--) {
		//test case별로 입력과 초기화. 
		cin >> w >> h;
		ans = 0;
		while (!fire.empty()) { fire.pop(); }
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == '@') { s.first = i; s.second = j; }
				if (arr[i][j] == '*') { fire.push({ i, j }); }
				visited[i][j] = -1;
			}
		}
		//bfs 돌리기
		queue<pair<int, int>> q;
		q.push(s);
		int escape = 0;
		while (!q.empty()) {
			ans++;
			//@ 칸에 불이 옮겨옴과 동시에 다른 칸으로 이동할 수 있다.
			//@의 이동.
			int sz = q.size();
			while (sz-- && !escape) {
				int y = q.front().first;
				int x = q.front().second;
				q.pop();
				for (int i = 0; i < 4; i++) {
					int ny = y + dy[i];
					int nx = x + dx[i];
					int canMove = 1;
					for (int j = 0; j < 4; j++) {
						int nny = ny + dy[j];
						int nnx = nx + dx[j];
						if (arr[nny][nnx] == '*' && nny*nnx != 0 && nny <= h && nnx <= w) {
							canMove = 0;
							break; 
						}
					}
					if (!canMove) {
						continue;
					}
					if (ny*nx == 0 || ny > h || nx > w) {
						escape = 1;
						break;
					}
					else if (arr[ny][nx] != '#' && arr[ny][nx] != '*' && visited[ny][nx] == -1) {
						visited[ny][nx] = 1;
						q.push({ ny, nx });
					}
				}
			}
			//탈출 여부 확인
			if (escape) { break; }
			//불의 이동.
			int fireNum = fire.size();
			while (fireNum--) {
				int y = fire.front().first;
				int x = fire.front().second;
				fire.pop();
				for (int i = 0; i < 4; i++) {
					int ny = y + dy[i];
					int nx = x + dx[i];
					if (ny*nx != 0 & ny <= h && nx <= w && arr[ny][nx] != '#' && arr[ny][nx] != '*') {
						arr[ny][nx] = '*';
						fire.push({ ny, nx });
					}
				}
			}
		}
		if (escape) { cout << ans << endl; }
		else { cout << "IMPOSSIBLE" << endl; }
	}
	/*system("pause");*/
	return 0;
}