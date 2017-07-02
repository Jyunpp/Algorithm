//20170702
#include <iostream>
using namespace std;

int n, ans;

int main() {
	cin >> n;
	if (n == 1000) n = 999;
	while (n) {
		if (n >= 100) {
			if ((n / 100) - ((n / 10) % 10) == ((n / 10) % 10) - (n % 10))
				ans++;
		}
		else {
			ans += n;
			break;
		}
		n--;
	}
	cout << ans;
	//system("pause");
	return 0;
}