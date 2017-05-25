//20170525
#include <iostream>
#include <queue>
using namespace std;
#define INF 654321

int n, k;
int dp[100001];
int account = 0;

int main() {
	cin >> n >> k;
	if (n == k) { cout << 0 << endl; cout << 1 << endl; return 0; }
	for (int i = 0; i < 100001; i++) {
		dp[i] = INF;
	}

	queue<int> q;
	q.push(n);
	dp[n] = 0;
	bool meetBrother = false;
	while (!q.empty()) {
		if (meetBrother == true) { break; }
		int sizeOfQueue = q.size();
		while (sizeOfQueue--) {
			int x = q.front();
			q.pop();
			//x-1
			if (x - 1 >= 0 && dp[x - 1] >= dp[x] + 1) {
				dp[x - 1] = dp[x] + 1;
				q.push(x - 1);
				if (x - 1 == k) { meetBrother = true; account++; }
			}
			//x+1
			if (x + 1 <= 100000 && dp[x + 1] >= dp[x] + 1) {
				dp[x + 1] = dp[x] + 1;
				q.push(x + 1);
				if (x + 1 == k) { meetBrother = true; account++; }
			}
			//2*x
			if (2 * x <= 100000 && dp[2 * x] >= dp[x] + 1) {
				dp[2 * x] = dp[x] + 1;
				q.push(2 * x);
				if (2 * x == k) { meetBrother = true; account++; }
			}
		}
	}
	cout << dp[k] << endl;
	cout << account << endl;
	/*cin >> n;*/
	return 0;
}