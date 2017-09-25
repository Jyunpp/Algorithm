//20170925 13:25 ~ 13:42
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#define xx first
#define yy second

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>
using namespace std;

char arr[1001][1001];
int visited[1001][1001];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int R, C;	//R이 행 C가 열
queue<pair<int, int>> q;
queue<pair<int, int>> fq;

int main() {
	scanf(" %d %d", &R, &C);
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			scanf(" %c", &arr[i][j]);
			if (arr[i][j] == 'J') { q.push({ i, j }); visited[i][j] = 1; }
			if (arr[i][j] == 'F') { fq.push({ i, j }); }
		}
	}
	int t = 0;
	while (!q.empty()) {
		int fsz = fq.size();
		while (fsz--) {
			int fy = fq.front().xx;
			int fx = fq.front().yy;
			fq.pop();
			for (int i = 0; i < 4; i++) {
				int ny = fy + dy[i];
				int nx = fx + dx[i];
				if (nx*ny != 0 && nx <= C && ny <= R&&arr[ny][nx] != '#' && arr[ny][nx] != 'F') {
					arr[ny][nx] = 'F';
					fq.push({ ny, nx });
				}
			}
		}
		t++;
		int sz = q.size();
		while (sz--) {
			int y = q.front().xx;
			int x = q.front().yy;
			if (x == 1 || y == 1 || x == C || y == R) {
				cout << t << endl; 
				//system("pause");
				return 0;
			}
			q.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (nx*ny != 0 && nx <= C && ny <= R&&arr[ny][nx] == '.' && !visited[ny][nx]) {
					q.push({ ny, nx });
					visited[ny][nx] = 1;
				}
			}
		}
	}
	cout << "IMPOSSIBLE" << endl;
	//system("pause");
	return 0;
}