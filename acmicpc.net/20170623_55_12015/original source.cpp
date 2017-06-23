//20170623 
#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000001], len, N, temp;
int main() {
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> temp;
		int *pos = lower_bound(dp + 1, dp + len + 1, temp);
		*pos = temp;
		if (pos == dp + len + 1)
			len++;
	}
	cout << len << endl;
	/*cin >> n;*/
	return 0;
}