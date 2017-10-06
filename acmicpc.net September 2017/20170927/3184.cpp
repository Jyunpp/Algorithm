//20170927 21:19 ~ 21:37
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#define sd(x) scanf(" %d", &x);
#define slld(x) scanf(" %lld", &x);
#define sc(x) scanf(" %c", &x);
#define ll long long
#define pb push_back
#define xx first
#define yy second
#define mod 1000000007

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

int R, C;
char arr[251][251];
int visited[251][251];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

pair<int, int> bfs(int y, int x) {
	visited[y][x] = 1;
	int sheep = arr[y][x] == 'o';
	int wolf = arr[y][x] == 'v';
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (nx*ny != 0 && ny <= R && nx <= C && arr[ny][nx] != '#' && !visited[ny][nx]) {
			pair<int, int> recur = bfs(ny, nx);
			sheep += recur.xx;
			wolf += recur.yy;
		}
	}
	return{ sheep, wolf };
}

int main() {
	sd(R); sd(C);
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			sc(arr[i][j]);
			if (arr[i][j] == '#') visited[i][j] = 1;
		}
	}

	int sheepAns = 0, wolfAns = 0;

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (visited[i][j] == 0) {
				pair<int, int> here = bfs(i, j);
				if (here.xx > here.yy) sheepAns += here.xx;
				else wolfAns += here.yy;
			}
		}
	}
	cout << sheepAns << " " << wolfAns << endl;
	//system("pause");
	return 0;
}