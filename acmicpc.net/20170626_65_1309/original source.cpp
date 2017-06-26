//20170626
#include <iostream>
using namespace std;

int n, a, b;

int main() {
	a = 1; b = 0;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		int tempB;
		tempB = (2 * a + b);
		a += 1 + b; a %= 9901;
		b = tempB; b %= 9901;
	}
	cout << (2 * a + b + 1)%9901 << endl;
	/*system("pause");*/
	return 0;
}