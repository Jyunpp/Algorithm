//20170525 ~ 20170526 
#include <iostream>
#include <queue>
using namespace std;
#define INF 654321

int n, k;
int dp[100001];

int main() {
	cin >> n >> k;
	//시작지 = 목적지 인 경우.
	if (n == k) { cout << 0 << endl; return 0; }
	//후진?은 거리만큼 시간이 필요. 단순계산으로 끝내자.
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
		//연산우선순위 고려, (괄호)안에 다 넣어주자!!★
		//(i != 0) 부분이 없다면 입력에 따라 무한루프 존재할 수 있음!! ★
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