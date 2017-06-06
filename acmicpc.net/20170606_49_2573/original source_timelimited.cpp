//20170604 22:28 ~ 20170605 01:23 시간초과로 멈춤..
//20170606 21:26 ~ 20170606 23:45 시간초과.. 시험공부나 하자.
#include <iostream>
#include <cstring>
using namespace std;

int n, m;
int arr[301][301];
int visited[301][301];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
int decrease[301][301];

void dfs(int y, int x);

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	int num = 1;
	int year = -1;
	while (num != 0) {
		year++;
		for (int i = 2; i <= n - 1; i++) {
			for (int j = 2; j <= m - 1; j++) {
				arr[i][j] -= decrease[i][j];
				visited[i][j] = -1;
				decrease[i][j] = 0;
			}
		}
		/*
		for (int i = 2; i <= n - 1; i++) {
		for (int j = 2; j <= m - 1; j++) {
		if (arr[i][j]) {

		arr[i][j] -= decrease[i][j];
		}
		}
		}
		*/
		/*
		memset(visited, -1, sizeof(visited));
		memset(decrease, 0, sizeof(decrease));
		*/
		int num = 0;
		for (int i = 2; i <= n - 1; i++) {
			for (int j = 2; j <= m - 1; j++) {
				if (arr[i][j] > 0 && visited[i][j] == -1) {
					num++;
					if (num >= 2) { cout << year << endl; /*cin >> n; */ return 0; }
					dfs(i, j);
				}
			}
		}
		////test print start

		//cout << "year : " << year+1 << endl;
		//for (int i = 1; i <= n; i++) {
		//	for (int j = 1; j <= m; j++) {
		//		if (arr[i][j] < 0) { cout << "0 "; }
		//		else { cout << arr[i][j] << " "; }
		//	}
		//	cout << endl;
		//}

		////test print end

	}
	cout << '0' << endl;
	/*cin >> n;*/
	return 0;
}

void dfs(int y, int x) {
	visited[y][x] = 1;
	if (arr[y + 1][x] > 0) {
		if (visited[y + 1][x] == -1)
			dfs(y + 1, x);
	}
	else { decrease[y][x]++; }

	if (arr[y - 1][x] > 0) {
		if (visited[y - 1][x] == -1)
			dfs(y - 1, x);
	}
	else { decrease[y][x]++; }

	if (arr[y][x + 1] > 0) {
		if (visited[y][x + 1] == -1)
			dfs(y, x + 1);
	}
	else { decrease[y][x]++; }

	if (arr[y][x - 1] > 0) {
		if (visited[y][x - 1] == -1)
			dfs(y, x - 1);
	}
	else { decrease[y][x]++; }
	//arr[y][x] -= decrease[y][x];
}