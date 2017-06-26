#include <iostream>
#include <algorithm>
using namespace std;
int a, b, c;
int main() {
	cin >> a >> b >> c;
	int ans = max(b - a - 1, c - b - 1);
	cout << ans << endl;
	return 0;
}