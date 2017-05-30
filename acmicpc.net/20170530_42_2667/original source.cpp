//20170530
//41_1012에서 섬의 크기 출력이 추가된 문제.
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, num;
char arr[26][26];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void dfs(int y, int x);

int main() {
	cin >> n;
	int ans = 0;
	vector<int> v;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] == '1') {
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
		cout << v[i] << endl;
	}
	/*cin >> n;*/
	return 0;
}

void dfs(int y, int x) {
	num++;
	arr[y][x] = '0';
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny > 0 && nx > 0 && ny <= n && nx <= n && arr[ny][nx] == '1') {
			dfs(ny, nx);
		}
	}
}