//20181023 23:45 ~ 
#include <iostream>
using namespace std;

long long n, m;
long long minAns, maxAns;

int main() {
	cin >> n >> m;
	if (m >= (n / 2 + 1)) minAns = 0;
	else minAns = n - (m * 2);
	if (m == 0) maxAns = n;
	else {
		long long curr = 2;
		maxAns = n - 2;
		m--;
		while (m>0) {
			maxAns--;
			m -= curr;
			curr++;
		}
	}
	cout << minAns << " " << maxAns << endl;

	return 0;
}