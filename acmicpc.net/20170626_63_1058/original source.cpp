#include <iostream>
#include <algorithm>
using namespace std;

int arr[51][51], gop[51][51];
int n, ans = 0;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char inputChar;
			cin >> inputChar;
			arr[i][j] = (inputChar == 'Y' ? 1 : 0);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) { continue; }
			for (int k = 1; k <= n; k++) {
				gop[i][j] += arr[i][k] * arr[k][j];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		int tempAns = 0;
		for (int j = 1; j <= n; j++) {
			tempAns += (arr[i][j] || gop[i][j]);
		}
		ans = max(ans, tempAns);
	}
	cout << ans << endl;
	/*system("pause");*/
	return 0;
}