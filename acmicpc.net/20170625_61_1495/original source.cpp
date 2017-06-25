//20170625 
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int arr[101],visited[101][1001], n, m, s, ans = -1;

int main() {
	cin >> n >> s >> m;
	for (int i = n; i >= 1; i--) {
		cin >> arr[i];
	}
	queue<int> q;
	q.push(s);
	while (!q.empty()&&n>1) {
		int sz = q.size();
		while ((sz--)) {
			int delta = arr[n];
			int here = q.front();
			q.pop();
			if (here + delta <= m && visited[n][here + delta] == 0) {
				q.push(here + delta);
				visited[n][here + delta] = 1;
			}
			if (here - delta >= 0 && visited[n][here - delta] == 0) {
				q.push(here - delta);
				visited[n][here - delta] = 1;
			}
		}
		n--;
	}
	int delta = arr[1];
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		if (here + delta <= m) {
			ans = max(ans, here + delta);
		}
		if (here - delta >= 0) {
			ans = max(ans, here - delta);
		}
	}
	if (ans == -1) {
		cout << -1 << endl;
	}
	else {
		cout << ans << endl;
	}
	/*system("pause");*/
	return 0;
}