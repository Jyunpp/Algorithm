//20170701_9507
#include <stdio.h>
#include <iostream>
int t, n;
long long fibo[68];
int main() {
	fibo[0] = fibo[1] = 1;
	fibo[2] = 2; fibo[3] = 4;
	for (int i = 4; i <= 67; i++)
		fibo[i] = fibo[i - 1] + fibo[i - 2] + fibo[i - 3] + fibo[i - 4];
	for (scanf("%d", &t); t > 0; t--) {
		scanf("%d", &n);
		printf("%lld\n", fibo[n]);
	}
	//system("pause");
	return 0;
}