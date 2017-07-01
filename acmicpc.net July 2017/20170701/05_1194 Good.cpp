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
	int key; // ��Ʈ
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
			//cout << "����, " << ans << "�� ° �̵�. (" << y << ", " << x << ", " << key << ") ���� ���!!" << endl;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				int nk = key;
				char next = arr[ny][nx];
				//���� �� & �湮�� �� ���ٸ�.
				if (nx*ny != 0 && ny <= n && nx <= m && visited[ny][nx][key] == 0) {
					//��
					if (next == '#') continue;
					//����
					else if (next == '1') {
						cout << ans << endl;
						//system("pause");
						return 0;
					}
					//Ű ȹ��
					else if (next >= 'a' && next <= 'f') {
						nk = key | 1 << (next - 'a');
						//arr[ny][nx] = '.';
					}
					//Ű ����� ���� �ʿ䰡 ����. ���� �� ��� ����.
					//else if (next >= 'A' && next <= 'F' && key & 1 << (next - 'A'))
					//	nk = key & ~(1 << (next - 'A'));

					//Ű�� ����.
					else if (next >= 'A' && next <= 'F' && !( key & 1 << (next - 'A') ))
						continue;
					//�湮.
					q.push(Pos{ ny, nx, nk });
					visited[ny][nx][key] = 1;//Ű ȹ�� ���� ���·� �湮 �ߴ� ��.��
				}
			}
		}
	}
	cout << -1 << endl;
	//system("pause");
	return 0;
}