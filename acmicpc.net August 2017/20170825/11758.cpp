//20170825 01:15 ~ 01:23
//기하 문제 복습 겸 
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
using namespace std;

int x[3], y[3];

int ccw(int x1, int y1, int x2, int y2) {
	return x1*y2 - x2*y1;
}

int main() {
	for (int i = 0; i < 3; i++)
		scanf(" %d %d", &x[i], &y[i]);
	int c = ccw(x[1] - x[0], y[1] - y[0], x[2] - x[1], y[2] - y[1]);
	int ans;
	if (c > 0) ans = 1;
	else if (c == 0) ans = 0;
	else ans = -1;
	printf("%d\n", ans);
	system("pause");
	return 0;
}