//20170707 14:49 ~ 15:13
#include <iostream>
#include <algorithm>
using namespace std;

int T[45];//1 ~44 »ç¿ë
int tc, n, lb;

int main() {
	for (int i = 1; i <= 44; i++)
		T[i] = T[i - 1] + i;
	cin >> tc;
	while (tc--) {
		cin >> n;
		lb = 0;
		while (T[++lb] < n) {}
		lb--;
		int canExpress = 0;
		for (int i = 1; i <= lb; i++) {
			for (int j = 1; j <= lb; j++) {
				for (int k = 1; k <= lb; k++) {
					if (T[i] + T[j] + T[k] == n) {
						canExpress = 1;
					}
				}
			}
		}
		if (canExpress) {
			cout << 1 << endl;
		}
		else {
			cout << 0 << endl;
		}
	}
	return 0;
}
