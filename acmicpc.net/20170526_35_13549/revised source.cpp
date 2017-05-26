//20170525 ~ 20170526 
#include <iostream>
#include <queue>
using namespace std;
#define INF 654321

int n, k;
int dp[100001];

int main() {
	cin >> n >> k;
	//������ = ������ �� ���.
	if (n == k) { cout << 0 << endl; return 0; }
	//����?�� �Ÿ���ŭ �ð��� �ʿ�. �ܼ�������� ������.
	if (n > k) { cout << n - k << endl; return 0; }
	for (int i = 0; i < 100001; i++) {
		dp[i] = INF;
	}
	queue<int> q;
	q.push(n);
	dp[n] = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		//2*x 
		//����켱���� ���, (��ȣ)�ȿ� �� �־�����!!��
		//(i != 0) �κ��� ���ٸ� �Է¿� ���� ���ѷ��� ������ �� ����!! ��
		for (int i = x * 2; (i <= 100000) && (i != 0); i *= 2) {
			if (dp[i] > dp[x]) {
				dp[i] = dp[x];
				q.push(i);
			}
		}
		//x-1
		if (x - 1 >= 0 && dp[x - 1] > dp[x] + 1) {
			dp[x - 1] = dp[x] + 1;
			q.push(x - 1);
		}
		//x+1
		if (x + 1 <= 100000 && dp[x + 1] > dp[x] + 1) {
			dp[x + 1] = dp[x] + 1;
			q.push(x + 1);
		}
	}
	cout << dp[k] << endl;
	/*cin >> n;*/
	return 0;
}