//20170707 뭐가 잘못된거지~
#include <iostream>
#include <algorithm>
using namespace std;

int tc, n, idx, num;
int upperbound;
int upperboundNum;
int ans1, ans2;
int arr[101];

int main() {
	cin >> tc;
	while (tc--) {
		upperbound = ans1 = ans2 = 0;
		upperboundNum = 987654321;
		cin >> n >> idx;
		idx++;
		for (int i = 1; i <= n; i++)
			cin >> arr[i];
		num = arr[idx];
		for (int i = 1; i <= n; i++) {
			if (i == idx) continue;
			if (arr[i] > num) {
				ans1++;
				if (arr[i] <= upperboundNum) {
					upperboundNum = arr[i];
					upperbound = i;
				}
			}
		}
		if (idx < upperbound) {
			for (int i = 1; i < idx; i++)
				if (arr[i] == num)
					ans2++;
			for (int i = upperbound + 1; i <= n; i++)
				if (arr[i] == num)
					ans2++;
		}
		else {
			for (int i = upperbound + 1; i < idx; i++)
				if (arr[i] == num)
					ans2++;
		}
		cout << ans1 << endl;
		cout << ans2 << endl;
		cout << ans1 + ans2 + 1 << endl;
	}
	return 0;
}