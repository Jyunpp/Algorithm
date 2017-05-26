//20170524 두 사람 각각 이동 시키고 열고 온 경로가 같다면 그게 답이라고 생각했다. 
//그러나 논리가 잘못됌.. 각각 최소값이면서 같은경로가 아니라.. 둘 다 빼낼 때 최소값.. 많은 수정이 필요..
//20170527 바깥에서 1명포함 총 세명의 dp를 돌려서 계산하기로.
#include <iostream>
#include <queue>
using namespace std;

struct Pos {
	int y, x;
};

int h, w;
int sy[3], sx[3];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
//죄수 두 명, 바깥에서 한 명. 2차원의 dp를 세 개 만든다.=>3차원
//dp에는 보통의 경우와 다르게, 깊이가 저장되는 것이 아니라, 부순 문의 갯수 저장.
int dp[3][102][102];
char arr[102][102];

vector<Pos>ans[2];

int main() {
	int tc;
	cin >> tc;
	for (; tc--;) {
		cin >> h >> w;
		//TEST CASE 존재하는 경웨 다음과같이 초기화 시켜주는 것 잊지말자!!★
		sy[0] = 0; sy[1] = 0;
		sx[0] = 0; sx[0] = 0;
		//dp와 arr 입력 및 초기화.
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				cin >> arr[i][j];
				dp[0][i][j] = -1;
				dp[1][i][j] = -1;
				dp[2][i][j] = -1;
				if (arr[i][j] == '$') {
					if (sy[0]) { sy[1] = i; sx[1] = j; }
					else { sy[0] = i; sx[0] = j; }
				}
			}
		}
		//바깥부분 초기화 할 것 남음.
		for (int person = 0; person < 3; person++) {
			for (int i = 0; i <= w + 1; i++) {
				arr[0][i] = '.'; dp[person][0][i] = -1;
				arr[h + 1][i] = '.'; dp[person][h + 1][i] = -1;
			}
			for (int i = 0; i <= h + 1; i++) {
				arr[i][0] = '.'; dp[person][i][0] = -1;
				arr[i][w + 1] = '.'; dp[person][i][w + 1] = -1;
			}
		}
		sy[2] = 0; sx[2] = 0;
		//세 명의 사람 각각 BFS.
		for (int person = 0; person < 3; person++) {
			queue<Pos> q;
			q.push(Pos{ sy[person], sx[person]});
			dp[person][sy[person]][sx[person]] = 0;
			while (!q.empty()) {
				int y = q.front().y;
				int x = q.front().x;
				int numOfOpen = dp[person][y][x];
				q.pop();
				//방문 시, 재 방문 허용. 깊이의 최소화가 아니라 문을 연 횟수의 최소화. 문을 연 횟수를 비교해보자.
				for (int i = 0; i < 4; i++) {
					int ny = y + dy[i];
					int nx = x + dx[i];
					//이동할 수 있는 범위 && 벽이 아닌 경우.
					if (((nx + 1)*(ny + 1) != 0) && (ny <= h + 1) && (nx <= w + 1) && (arr[ny][nx] != '*')) {
						int numOfOpen_past = dp[person][ny][nx];
						//문을 만나서 열어야 할 경우.
						if (arr[ny][nx] == '#') {
							//방문한 적이 없다 || 과거의 방문보다 더 적은 open 횟수 => 방문.
							if ((numOfOpen_past == -1) || (numOfOpen + 1 < numOfOpen_past)) {
								q.push(Pos{ ny, nx });
								dp[person][ny][nx] = dp[person][y][x] + 1;
							}
						}
						//열 필요가 없는 경우. 다른 죄수자리 or 빈 공간.
						else {
							//방문한 적이 없다 || 과거의 방문보다 더 적은 open 횟수 => 방문.
							if ((numOfOpen_past == -1) || (numOfOpen < numOfOpen_past)) {
								q.push(Pos{ ny, nx });
								dp[person][ny][nx] = dp[person][y][x];
							}
						}
					}
				}
			}
		}
		int ans = 54321;
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				int temp = 0;
				char here = arr[i][j];
				if (here == '*') { continue; }
				temp += dp[0][i][j];
				temp += dp[1][i][j];
				temp += dp[2][i][j];
				if (here == '#') { temp -= 2; }
				ans = (ans > temp ? temp : ans);
			}
		}
		/*
		//test print start.
		for (int person = 0; person < 3; person++) {
			cout << person << " person" << endl;
			for (int i = 0; i <= h + 1; i++) {
				for (int j = 0; j <= w + 1; j++) {
					if (dp[person][i][j] == -1) { cout << dp[person][i][j] << " "; }
					else { cout << " " << dp[person][i][j] << " "; }
				}
				cout << endl;
			}
			cout << endl;
		}
		//test print end.
		*/

		//answer
		cout << ans << endl;
	}
	/*cin >> h;*/
	return 0;
}