//20170924 02:26 ~ 02:50
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#define xx first
#define yy second

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>
using namespace std;

int c, p;
int o, oo, Oo, ooO, Ooo, oO, ooo, OoO, oOO, lo, ol, OOo, oooo;
int arr[101];

int main() {
	cin >> c >> p;
	for (int i = 1; i <= c; i++)
		cin >> arr[i];
	//ÀüÃ³¸®
	o = c;	//ÇÑ Ä­Â¥¸®
	for (int i = 2; i <= c; i++) {
		int ppprev = arr[i - 3];
		int pprev = arr[i - 2];
		int prev = arr[i - 1];
		int curr = arr[i];
		//³× Ä­Â¥¸®
		if (i >= 4)
			if (ppprev == pprev && pprev == prev && prev == curr) oooo++;
		//¼¼ Ä­Â¥¸®
		if (i >= 3) {
			if (pprev == prev && prev + 1 == curr) ooO++;
			if (pprev - 1 == prev &&prev == curr) Ooo++;
			if (pprev == prev && prev == curr) ooo++;
			if (pprev == curr && prev + 1 == curr) OoO++;
			if (pprev + 1 == prev && prev == curr) oOO++;
			if (pprev == prev && prev - 1 == curr) OOo++;
		}
		//µÎ Ä­Â¥¸®
		if (prev == curr) oo++;
		if (prev - 1 == curr) Oo++;
		if (prev + 1 == curr) oO++;
		if (prev - 2 == curr) lo++;
		if (prev + 2 == curr) ol++;
	}

	int ans;
	if (p == 1) ans = o + oooo;
	if (p == 2) ans = oo;
	if (p == 3) ans = Oo + ooO;
	if (p == 4) ans = Ooo + oO;
	if (p == 5) ans = ooo + oO + OoO + Oo;
	if (p == 6) ans = ooo + oo + oOO + lo;
	if (p == 7) ans = ooo + oo + OOo + ol;
	cout << ans << endl;
	//system("pause");
	return 0;
}