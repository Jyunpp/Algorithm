////20170624 15:34 ~ 16:27 다른 사람의 아이디어..
#include <iostream>
#include<algorithm>
using namespace std;
int p = -987654321, q, n, x, r = -987654321;
int main() {
	for (cin >> n; n--;) {
		cin >> x;
		q = max(p, q + x);//p가 최대로 더한거니까..
		p = max(p + x, x);
		r = max({ r,p,q });
	}
	cout << r << endl;
	/*system("pause");*/
	return 0;
}