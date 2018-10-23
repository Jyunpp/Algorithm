//20181023 23:45 ~ 
#include <iostream>
using namespace std;

int n, m;
int minAns, maxAns;

int main() {
	cin >> n >> m;
	maxAns = n - (m + 1);
	if (m >= (n / 2 + 1)) minAns = 0;
	else minAns = n - (m * 2);
	cout << minAns << " " << maxAns << endl;
	cin >> n;
	return 0;
}