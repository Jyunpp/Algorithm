//20170524 �� ��� ���� �̵� ��Ű�� ���� �� ��ΰ� ���ٸ� �װ� ���̶�� �����ߴ�. 
//�׷��� ���� �߸���.. ���� �ּҰ��̸鼭 ������ΰ� �ƴ϶�.. �� �� ���� �� �ּҰ�.. ���� ������ �ʿ�..
//20170527 �ٱ����� 1������ �� ������ dp�� ������ ����ϱ��.
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
//�˼� �� ��, �ٱ����� �� ��. 2������ dp�� �� �� �����.=>3����
//dp���� ������ ���� �ٸ���, ���̰� ����Ǵ� ���� �ƴ϶�, �μ� ���� ���� ����.
int dp[3][102][102];
char arr[102][102];

vector<Pos>ans[2];

int main() {
	int tc;
	cin >> tc;
	for (; tc--;) {
		cin >> h >> w;
		//TEST CASE �����ϴ� ��� ���������� �ʱ�ȭ �����ִ� �� ��������!!��
		sy[0] = 0; sy[1] = 0;
		sx[0] = 0; sx[0] = 0;
		//dp�� arr �Է� �� �ʱ�ȭ.
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
		//�ٱ��κ� �ʱ�ȭ �� �� ����.
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
		//�� ���� ��� ���� BFS.
		for (int person = 0; person < 3; person++) {
			queue<Pos> q;
			q.push(Pos{ sy[person], sx[person]});
			dp[person][sy[person]][sx[person]] = 0;
			while (!q.empty()) {
				int y = q.front().y;
				int x = q.front().x;
				int numOfOpen = dp[person][y][x];
				q.pop();
				//�湮 ��, �� �湮 ���. ������ �ּ�ȭ�� �ƴ϶� ���� �� Ƚ���� �ּ�ȭ. ���� �� Ƚ���� ���غ���.
				for (int i = 0; i < 4; i++) {
					int ny = y + dy[i];
					int nx = x + dx[i];
					//�̵��� �� �ִ� ���� && ���� �ƴ� ���.
					if (((nx + 1)*(ny + 1) != 0) && (ny <= h + 1) && (nx <= w + 1) && (arr[ny][nx] != '*')) {
						int numOfOpen_past = dp[person][ny][nx];
						//���� ������ ����� �� ���.
						if (arr[ny][nx] == '#') {
							//�湮�� ���� ���� || ������ �湮���� �� ���� open Ƚ�� => �湮.
							if ((numOfOpen_past == -1) || (numOfOpen + 1 < numOfOpen_past)) {
								q.push(Pos{ ny, nx });
								dp[person][ny][nx] = dp[person][y][x] + 1;
							}
						}
						//�� �ʿ䰡 ���� ���. �ٸ� �˼��ڸ� or �� ����.
						else {
							//�湮�� ���� ���� || ������ �湮���� �� ���� open Ƚ�� => �湮.
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