//20170703
#include <iostream>
#include <algorithm>
using namespace std;

int n, len, lower;

int main() {
	cin >> n;
	int temp = n;
	while (temp) {
		len++;
		temp /= 10;
	}
	int lower = max(0, n - 9 * len);
	while (lower < n) {
		int temp = lower;
		int ans = 0;
		while (temp) {
			ans += temp % 10;
			temp /= 10;
		}
		if (ans + lower == n) {
			cout << lower << endl;
			system("pause");
			return 0;
		}
		lower++;
	}
	cout << 0 << endl;
	system("pause");
	return 0;
}