//20170602 03:14 ~ 03:26 한 방!
#include <iostream>
using namespace std;

int n, m;
char arr[251][251];
int sheep = 0, wolf = 0;
int tempSheep, tempWolf;

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void dfs(int y, int x);

int main() {
	//입력 및 초기화
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	//찾고 찾을때마다 dfs 돌리기
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] != '#') {
				tempSheep = 0;
				tempWolf = 0;
				dfs(i, j);
				tempSheep > tempWolf ? sheep += tempSheep : wolf += tempWolf;
			}
		}
	}
	cout << sheep << " " << wolf << endl;
	/*cin >> n;*/
	return 0;
}

void dfs(int y, int x) {
	//재방문 금지
	char here = arr[y][x];
	if (here == 'v') { tempWolf++; }
	else if (here == 'k') { tempSheep++; }
	arr[y][x] = '#';
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny > 0 && nx > 0 && ny <= n && nx <= m && arr[ny][nx] != '#') {
			dfs(ny, nx);
		}
	}
}