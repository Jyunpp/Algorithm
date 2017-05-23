//20170523
//�� ¥�� ���ϱ�, ���� ���� �̵� ��Ű�� �� ������ �������� �� ����.
//�� ���� ���� Snapshot�� ��� ����� ���� �ʹٸ�, Queue�� �� �� ����ϸ� �Ǵ±���!��
//���� �̵��� Queue<Pos>�� �迭�� �̿��ؼ� 2���� ť�� Ǯ���� �� �� �޸� �ʰ��� �������� �𸣰ڴ�.. 128MB�����ε� ..
#include <iostream>
#include <queue>
using namespace std;

#define INF 54321

struct Pos {
	int y, x;
};

int r, c, sy, sx, ey, ex;
//[52][52]�� ���� ������, �̵��� ���� ���� ���� �� ����� ��, out of range ������ ���ؼ� Good!
int dp[52][52];
char arr[52][52];

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int main() {
	queue<Pos> q[2];//����ġ�� �̵� ���.
	queue<Pos> q2;//���� �̵� ���.
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
	//�� �̻� ����ġ�� �� ������ ��. ��, q[0],q[1] ��� ����� �� ����.
	int time = -1;
	while (!(q[0].empty() && q[1].empty())) {
		time++;
		int here = time % 2;
		int there = (time + 1) % 2;
		//����ġ�� �� ���� �̵�.
		while (!q[here].empty()) {
			int y = q[here].front().y;
			int x = q[here].front().x;
			q[here].pop();
			//�� ���⺰ �̵�
			//cout << "y == " << y << " && x == " << x << endl;//test!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				//cout << "ny == " << ny << " && nx == " << nx << endl; //test!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
				//�̵��� �� �ִ� ������ ��
				if (ny*nx != 0 && ny <= r && nx <= c) {
					//�̵��� ���� ���� ���ְų� ���� �ִٸ� skip
					if (arr[ny][nx] == '*' || arr[ny][nx] == 'X') { continue; }
					//�̵��� ���� ���� ���� ���� ���� skip
					//���� ��! ���� ���� ���̴��� ����� �ұ�(������. ���� ����.)�̶�� �̵��� �� �ִ�!
					bool isSubmerged = false;
					for (int j = 0; j < 4; j++) {
						if (arr[ny + dy[j]][nx + dx[j]] == '*' && /*��*/arr[ny][nx] != 'D') { isSubmerged = true; break; }
					}
					if (isSubmerged == true) { continue; }
					//�̵��� �� �ִ� ���� && ��, ���� ���� ���� ���� ��Ȳ�̴�. �湮�� ���� ���ٸ� �湮����.
					//cout << "I can move." << endl;//test!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
					if (dp[ny][nx] == INF) {
						dp[ny][nx] = dp[y][x] + 1;
						q[there].push(Pos{ ny, nx });
					}
				}
			}
		}
		//�� �� �̵� ������ ���� �̵��� �����غ���. �� �ִ� �κ��� �̵� ����Ű�� �� ����� ��.
		//���� �̵���, ����ġ�� �� ����(BFS���� �� ����)�� ��ĥ ������ �̵��ؾ� �Ѵ�. 
		//q���� pop �� �� �� �����ٰ� �ƴϰ�, �� ���̰� ���� ��������!! ��
		//���� �� ���� �̵�.
		for(int i=1; i<=r; i++){
			for (int j = 1; j <= c; j++) {
				if (arr[i][j] == '*') {
					//�����ڸ����� ������ �� ������
					for (int k = 0; k < 4; k++) {
						int ny = i + dy[k];
						int nx = j + dx[k];
						//�̵� �����ϴٸ�(��, ���̳� ����� �ұ��� ���ٸ�) ���� ä���� �����̴�. q2�� �ϴ� �־�д�.(���� ä��� ���� �������� �߽߰� �ٷ� �� �̵��ϰ� ��.)
						if (ny*nx != 0 && ny <= r && nx <= c && arr[ny][nx] != 'X' && arr[ny][nx] != 'D') {
							q2.push(Pos{ ny, nx });
						}
					}
				}
			}
		}
		//���� �̵��� arr�� ǥ�� �ϱ�.
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