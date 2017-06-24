//20170624 14:48 ~ 15:16
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int dp[1000001];
int n;

int main() {
	cin >> n;
	queue<int> q;
	q.push(n);
	int here;
	while (!q.empty()) {
		here = q.front();
		q.pop();
		// /3
		if (here % 3 == 0 && !dp[here / 3]) { dp[here / 3] = dp[here] + 1; q.push(here / 3); }
		// /2
		if (here % 2 == 0 && !dp[here / 2]) { dp[here / 2] = dp[here] + 1; q.push(here / 2); }
		// -1
		if (!dp[here - 1]) { dp[here - 1] = dp[here] + 1; q.push(here - 1); }
		if (dp[1]) { break; }
	}

	cout << dp[1] << endl;

	stack<int> bt;
	bt.push(1);
	for (int i = dp[1]-1; i >= 1; i--) {
		here = bt.top();
		if (here * 3 < 1000000) {
			if (dp[here * 3] == i) { bt.push(here * 3); continue; }
		}
		if (here * 2 < 1000000) {
			if (dp[here * 2] == i) { bt.push(here * 2); continue; }
		}
		if (here + 1 < 1000000) {
			if (dp[here + 1] == i) { bt.push(here + 1); continue; }
		}
	}

	cout << n;
	while (!bt.empty()) {
		cout << " " << bt.top();
		bt.pop();
	}
	/*cin >> n;*/
	return 0;
}