//20170602 22:20 ~ 23:56
#include <iostream>
#include <queue>
using namespace std;

int n, m, sy, sx, sd, ey, ex, ed;
int arr[102][102];
int visited[101][101][5];
int dy[5] = { NULL, 0, 0, 1, -1 };//동서남북 순.. 남쪽이 +방향.. 이것때매 30분 ..★★★★★
int dx[5] = { NULL, 1, -1, 0, 0 };
int direction[4] = { 1, 3, 2, 4 };

struct Pos {
	int y;
	int x;
	int d;
};

int main() {
	//입력 및 초기화
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			for (int k = 1; k <= 4; k++) {
				visited[i][j][k] = -1;
			}
		}
	}
	cin >> sy >> sx >> sd >> ey >> ex >> ed;
	//예외처리 해 줄 필요 없네 밑에 while 조건 바꾸니까!
	//if (sy == ey && sx == ex && sd == ed) { cout << 0 << endl; return 0; }
	//BFS
	queue<Pos> q;
	q.push(Pos{ sy,sx,sd });
	visited[sy][sx][sd] = 0;
	while (visited[ey][ex][ed] == -1) {
		int y = q.front().y;
		int x = q.front().x;
		int d = q.front().d;
		int indexOfDirection;
		for (int i = 0; i < 4; i++) {
			if (direction[i] == d) { indexOfDirection = i; break; }
		}
		q.pop();
		int ny = y;
		int nx = x;
		//현재 방향 이동.
		for (int i = 0; i < 3; i++) {
			ny += dy[d];
			nx += dx[d];
			if (ny > 0 && nx > 0 && ny <= n && nx <= m && arr[ny][nx] == 1) { break; }//막혀 있으면 더 이상 못간다.★
			if (ny > 0 && nx > 0 && ny <= n && nx <= m && visited[ny][nx][d] == -1) {
				q.push(Pos{ ny,nx,d });
				visited[ny][nx][d] = visited[y][x][d] + 1;
			}
		}
		//시계 방향 회전. => direction index를 1 증가.
		int cwd = direction[(indexOfDirection + 1) % 4];
		if (visited[y][x][cwd] == -1) {
			q.push(Pos{ y, x,cwd });
			visited[y][x][cwd] = visited[y][x][d] + 1;
		}
		int ccwd = direction[(indexOfDirection + 3) % 4];
		//반시계 방향 회전. => direction index를 1 감소. 가 아니라 + 3을 해야 하네!!! mod 생각 ★★
		if (visited[y][x][ccwd] == -1) {
			q.push(Pos{ y, x,ccwd });
			visited[y][x][ccwd] = visited[y][x][d] + 1;
		}
	}
	cout << visited[ey][ex][ed] << endl;
	/*cin >> n;*/
	return 0;
}