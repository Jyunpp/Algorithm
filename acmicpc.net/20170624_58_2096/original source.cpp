//20170624
//�Ϻη� ���� �ݺ������� ����.
#include <iostream>
#include <algorithm>
using namespace std;

int n, prevIndex, index;
int dp[3][2][2];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		prevIndex = (i - 1) % 2;
		index = i % 2;
		cin >> dp[0][index][1] >> dp[1][index][1] >> dp[2][index][1];
		//ù° ĭ�� �ִ� �ּ�
		dp[0][index][0] = max(dp[0][prevIndex][0], dp[1][prevIndex][0]) + dp[0][index][1];
		dp[0][index][1] += min(dp[0][prevIndex][1], dp[1][prevIndex][1]);
		//��° ĭ�� �ִ� �ּ�
		dp[1][index][0] = max(max(dp[0][prevIndex][0], dp[1][prevIndex][0]), dp[2][prevIndex][0]) + dp[1][index][1];
		dp[1][index][1] += min(min(dp[0][prevIndex][1], dp[1][prevIndex][1]), dp[2][prevIndex][1]);
		//��° ĭ�� �ִ� �ּ�
		dp[2][index][0] = max(dp[1][prevIndex][0], dp[2][prevIndex][0]) + dp[2][index][1];
		dp[2][index][1] += min(dp[1][prevIndex][1], dp[2][prevIndex][1]);
	}
	int maxAns = max(max(dp[0][index][0], dp[1][index][0]), dp[2][index][0]);
	int minAns = min(min(dp[0][index][1], dp[1][index][1]), dp[2][index][1]);
	cout << maxAns << " " << minAns << endl;
	/*cin >> n;*/
	return 0;
}