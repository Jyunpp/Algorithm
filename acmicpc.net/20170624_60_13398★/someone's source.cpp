////20170624 15:34 ~ 16:27 �ٸ� ����� �ڵ�.
#include<cstdio>
#include<algorithm>
using namespace std;
int p = -1e9, q, n, x, r = -1e9;
int main() {
	for (scanf("%d", &n); n--;) {
		scanf("%d", &x);
		q = max(p, q + x);//p�� �ִ�� ���ѰŴϱ�..
		p = max(p + x, x);
		r = max({ r,p,q });
	}
	printf("%d", r);
	/*system("pause");*/
	return 0;
}