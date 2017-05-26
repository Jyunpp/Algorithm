#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INF 654321

int n, k;
int dp[100001];

int main() {
	cin >> n >> k;
	//�������� �������� ���
	if (n == k) { cout << 0 << endl; cout << n << endl; return 0; }
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
	vector<int> v;
	v.push_back(k);
	int next = dp[k];
	for (int i = 0; i < dp[k]; i++) {
		int here = v.back();
		next -= 1;
		//x+1 : x-1�ؼ� �� ���.
		if ((here != 100000) && (dp[here + 1] == dp[here] - 1)) {
			v.push_back(here + 1);
		}
		//x-1 : x+1�ؼ� �� ���.
		else if ((here != 0) && (dp[here - 1] == dp[here] - 1)) {
			v.push_back(here - 1);
		}
		//x/2 : 2*x�ؼ� �� ���. ����������..�ε� ��� ���� �� ��� �ش� �ȵŸ� ������ *2�ؼ� �� ��.
		else {
			v.push_back(here / 2);
		}
	}
	cout << dp[k] << endl;
	int vs = v.size();
	for (int i = vs - 1; i >= 0; i--) {
		cout << v[i] << " ";
	}
	cout << endl;
	/*cin >> n;*/
	return 0;
}