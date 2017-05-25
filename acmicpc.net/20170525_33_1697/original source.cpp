//20170525
#include <iostream>
#include <queue>
using namespace std;
#define INF 654321

int n, k;
int dp[100001];

int main() {
	cin >> n >> k;
	if (n == k) { cout << 0 << endl; return 0; }
	for (int i = 0; i < 100001; i++) {
		dp[i] = INF;
	}
	
	queue<int> q;
	q.push(n);
	dp[n] = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		//x-1
		if (x - 1 >= 0 && dp[x - 1] == INF) {
			dp[x - 1] = dp[x] + 1;
			q.push(x - 1);
			if (x - 1 == k) { break; }
		}
		//x+1
		if (x + 1 <= 100000 && dp[x + 1] == INF) {
			dp[x + 1] = dp[x] + 1;
			q.push(x + 1);
			if (x + 1 == k) { break; }
		}
		//2*x
		if (2 * x <= 100000 && dp[2 * x] == INF) {
			dp[2 * x] = dp[x] + 1;
			q.push(2 * x);
			if (2 * x == k) { break; }
		}
	}
	cout << dp[k] << endl;
	/*cin >> n;*/
	return 0;
}