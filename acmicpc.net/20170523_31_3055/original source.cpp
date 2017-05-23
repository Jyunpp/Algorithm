//20170523
//다 짜고 보니까, 물을 먼저 이동 시키면 더 생각이 간단해질 것 같다.
//한 깊이 마다 Snapshot을 찍고 결과를 보고 싶다면, Queue를 두 개 사용하면 되는구나!★
//물의 이동도 Queue<Pos>형 배열을 이용해서 2개의 큐로 풀었을 땐 왜 메모리 초과가 나오는지 모르겠다.. 128MB제한인데 ..
#include <iostream>
#include <queue>
using namespace std;

#define INF 54321

struct Pos {
	int y, x;
};

int r, c, sy, sx, ey, ex;
//[52][52]로 해준 이유는, 이동할 곳이 물이 차는 것 계산할 때, out of range 방지를 위해서 Good!
int dp[52][52];
char arr[52][52];

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int main() {
	queue<Pos> q[2];//고슴도치의 이동 담당.
	queue<Pos> q2;//물의 이동 담당.
	cin >> r >> c;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'S') { sy = i; sx = j; }
			if (arr[i][j] == 'D') { ey = i; ex = j; }
			dp[i][j] = INF;
		}
	}
	dp[sy][sx] = 0;
	q[0].push(Pos{ sy, sx });
	//더 이상 고슴도치가 못 움직일 때. 즉, q[0],q[1] 모두 비었을 때 종료.
	int time = -1;
	while (!(q[0].empty() && q[1].empty())) {
		time++;
		int here = time % 2;
		int there = (time + 1) % 2;
		//고슴도치의 한 깊이 이동.
		while (!q[here].empty()) {
			int y = q[here].front().y;
			int x = q[here].front().x;
			q[here].pop();
			//네 방향별 이동
			//cout << "y == " << y << " && x == " << x << endl;//test!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				//cout << "ny == " << ny << " && nx == " << nx << endl; //test!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
				//이동할 수 있는 범위일 시
				if (ny*nx != 0 && ny <= r && nx <= c) {
					//이동할 곳이 물이 차있거나 돌이 있다면 skip
					if (arr[ny][nx] == '*' || arr[ny][nx] == 'X') { continue; }
					//이동할 곳이 다음 번에 물이 차도 skip
					//★이 떄! 물이 차는 곳이더라도 비버의 소굴(도착지. 물이 안참.)이라면 이동할 수 있다!
					bool isSubmerged = false;
					for (int j = 0; j < 4; j++) {
						if (arr[ny + dy[j]][nx + dx[j]] == '*' && /*★*/arr[ny][nx] != 'D') { isSubmerged = true; break; }
					}
					if (isSubmerged == true) { continue; }
					//이동할 수 있는 범위 && 물, 돌도 없고 물도 안찰 상황이다. 방문한 적이 없다면 방문하자.
					//cout << "I can move." << endl;//test!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
					if (dp[ny][nx] == INF) {
						dp[ny][nx] = dp[y][x] + 1;
						q[there].push(Pos{ ny, nx });
					}
				}
			}
		}
		//한 번 이동 했으니 물의 이동을 생각해보자. 돌 있는 부분은 이동 못시키는 것 고려할 것.
		//물의 이동은, 고슴도치의 한 스텝(BFS에서 한 깊이)가 마칠 때마다 이동해야 한다. 
		//q에서 pop 한 번 할 떄마다가 아니고, 한 깊이가 끝날 때마다임!! ★
		//물의 한 깊이 이동.
		for(int i=1; i<=r; i++){
			for (int j = 1; j <= c; j++) {
				if (arr[i][j] == '*') {
					//물의자리에서 인접한 네 방향이
					for (int k = 0; k < 4; k++) {
						int ny = i + dy[k];
						int nx = j + dx[k];
						//이동 가능하다면(즉, 돌이나 비버의 소굴이 없다면) 물이 채워질 공간이다. q2에 일단 넣어둔다.(지금 채우면 다음 루프에서 발견시 바로 또 이동하게 됨.)
						if (ny*nx != 0 && ny <= r && nx <= c && arr[ny][nx] != 'X' && arr[ny][nx] != 'D') {
							q2.push(Pos{ ny, nx });
						}
					}
				}
			}
		}
		//물의 이동을 arr에 표시 하기.
		while (!q2.empty()) {
			arr[q2.front().y][q2.front().x] = '*';
			q2.pop();
		}
/*
//dp test print
		cout << "[dp]" << endl;
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				int testDp = dp[i][j];
				if (testDp == INF) { cout << "-- "; }
				else { cout << testDp / 10 << testDp % 10 << " "; }
			}
			cout << endl;
		}
//arr test print
		cout << "[arr]" << endl;
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
//test end.
*/
	}
	int ans = dp[ey][ex];
	if (ans == INF) { cout << "KAKTUS" << endl; /*cin >> r;*/ return 0; }
	cout << ans << endl;
	/*cin >> r;*/
	return 0;
}