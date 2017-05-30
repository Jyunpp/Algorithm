//20170530 ~ 20170531 넘어가는 새벽
//42_2667 에서 입력방식을 바꾼 형태.
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int m, n, k, num;
int arr[101][101];//이지만 0~100으로 하자.
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void dfs(int y, int x);

int main() {
	cin >> m >> n >> k;
	int ans = 0;
	int x1, x2, y1, y2;
	vector<int> v;
	for (int i = 0; i < k; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = y1; j < y2; j++) {
			for (int k = x1; k < x2; k++) {
				arr[j][k] = 1;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0) {
				ans++;
				num = 0;
				dfs(i, j);
				v.push_back(num);
			}
		}
	}
	cout << ans << endl;
	sort(v.begin(), v.end());
	int sz = v.size();
	for (int i = 0; i < sz; i++) {
		cout << v[i] << " ";
	}
	/*cin >> n;*/
	return 0;
}

void dfs(int y, int x) {
	num++;
	arr[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= 0 && nx >= 0 && ny < m && nx < n && arr[ny][nx] == 0) {
			dfs(ny, nx);
		}
	}
}