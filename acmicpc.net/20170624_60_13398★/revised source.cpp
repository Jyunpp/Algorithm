////20170624 15:34 ~ 16:27 �ٸ� ����� ���̵��..
#include <iostream>
#include<algorithm>
using namespace std;
int p = -987654321, q, n, x, r = -987654321;
int main() {
	for (cin >> n; n--;) {
		cin >> x;
		q = max(p, q + x);//p�� �ִ�� ���ѰŴϱ�..
		p = max(p + x, x);
		r = max({ r,p,q });
	}
	cout << r << endl;
	/*system("pause");*/
	return 0;
}