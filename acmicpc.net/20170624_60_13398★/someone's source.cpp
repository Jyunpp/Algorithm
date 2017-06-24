////20170624 15:34 ~ 16:27 다른 사람의 코드.
#include<cstdio>
#include<algorithm>
using namespace std;
int p = -1e9, q, n, x, r = -1e9;
int main() {
	for (scanf("%d", &n); n--;) {
		scanf("%d", &x);
		q = max(p, q + x);//p가 최대로 더한거니까..
		p = max(p + x, x);
		r = max({ r,p,q });
	}
	printf("%d", r);
	/*system("pause");*/
	return 0;
}