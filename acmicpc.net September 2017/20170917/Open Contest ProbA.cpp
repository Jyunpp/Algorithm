//20170917 02:00 ~ 
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
#include <string>
#include <memory.h>
#include <algorithm>
using namespace std;

int m, n; //m¿Ã ºº∑Œ
int arr[251][251];
int dy[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int visited[251][251];

void dfs(int y, int x) {
	visited[y][x] = 1;
	for (int i = 0; i < 8; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny*nx == 0 || ny > m || nx > n || visited[ny][nx] == 1 || arr[ny][nx] == 0) continue;
		else {
			dfs(ny, nx);
		}
	}
}

int main() {
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++){
			scanf(" %d", &arr[i][j]);
		}
	}
	int ans = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] == 1 && visited[i][j] == 0) {
				dfs(i, j);
				ans++;
			}
		}
	}
	cout << ans << endl;
	//system("pause");
	return 0;
}