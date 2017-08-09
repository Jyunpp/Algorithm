//20170808 16:02 ~ 16:10
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
#include <algorithm>
//#include <functional>
using namespace std;

int main() {
	int n, ans = 0, arr[100001];
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	//sort(arr, arr + n + 1, greater<int>());
	sort(arr, arr + n + 1, [](int a, int b) {return a > b; });
	for (int i = 1; i <= n; i++)
		ans = max(ans, i + arr[i - 1] + 1);
	cout << ans << endl;
	//system("pause");
	return 0;
}