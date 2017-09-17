//20170917 03:36 ~ 03:52
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
using namespace std;

int h, w;
int arr[501];

int main() {
	cin >> h >> w;
	int maxH = 0;
	for (int i = 1; i <= w; i++) {
		cin >> arr[i];
		maxH = max(maxH, arr[i]);
	}
	int ans = 0;
	for (int i = 1; i <= maxH; i++) {
		bool started = false;
		int waterWidth = 0;
		for (int j = 1; j <= w; j++) {
			if (arr[j] >= i && started == false) {
				started = true;
				continue;
			}
			if (started){
				if (arr[j] < i) {
					waterWidth++;
				}
				else if (waterWidth > 0) {
					ans += waterWidth;
					waterWidth = 0;
				}
			}
		}
	}
	cout << ans << endl;
	//system("pause");
	return 0;
}