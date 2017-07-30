#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> point;
point wall[1001]; int n;
point cctv[1001]; int m;
int costArr[1001];
int dp[1001][1001];
point visibleRange[1001];
vector<int> visible[1001];
point operator+(const point &a, const point &b) {
	return point(a.first + b.first, a.second + b.second);
}
point operator-(const point &a, const point &b) {
	return point(a.first - b.first, a.second - b.second);
}
long long ccw(const point a, const point b, const point c) {
	point p1 = b - a;
	point p2 = c - a;
	return p1.first*p2.second - p1.second*p2.first;
}
int prev(int x) {
	return (x + n - 1) % n;
}
int next(int x) {
	return (x + 1) % n;
}
point findBoundary(const point &p) {
	//classified
}
int solve(int s_index, int e_index, int cost) {
	//classified
	return ret;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> wall[i].first >> wall[i].second;
	for (int i = 0; i < m; i++) {
		cin >> cctv[i].first >> cctv[i].second >> costArr[i];
		//classified
	}
	if (n == 1) {
		//classified
	}
	else if (n == 2) {
		//classified
	}
	int ans = 987654321;
	for (int i = 0; i < visible[0].size(); i++) {
		//classified
	}
	if (ans >= 987654321)
		cout << -1 << endl;
	else
		cout << ans << endl;
	return 0;
}