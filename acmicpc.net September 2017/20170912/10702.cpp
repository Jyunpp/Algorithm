//20170912 14:30 ~ 15:02
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
using namespace std;

int nnn;
int O[11], V[11], N[11];
int m;
int arr['O' + 'V' + 'N' + 1];

int main() {
	scanf("%d", &nnn);
	for (int i = 1; i <= nnn; i++) {
		scanf("%d-%d-%d", &O[i], &V[i], &N[i]);
	}
	scanf(" %d", &m);
	for (int i = 1; i <= m; i++) {
		string s;
		cin >> s;
		int sz = s.size();
		int curr = 0;
		for (int j = 0; j < sz; j++) {
			curr += (int)s[j];
		}
		arr[curr]++;
	}
	int oo = arr['O'];
	int vv = arr['V'];
	int nn = arr['N'];
	int on = arr['O' + 'N'];
	int vn = arr['V' + 'N'];
	int ov = arr['O' + 'V'];
	int ovn = arr['O' + 'V' + 'N'];
	for (int i = 1; i <= nnn; i++) {
		bool ans = false;
		for (int j = 0; j <= arr['O' + 'N']; j++) {			//j°¡ n
			for (int k = 0; k <= arr['V' + 'N']; k++) {		//k°¡ n
				for (int o = 0; o <= arr['O' + 'V']; o++) {	//o°¡ o
					int needN = max(0, N[i] - nn - j - k);
					int needV = max(0, V[i] - vv - (vn - k) - (ov - o));
					int needO = max(0, O[i] - oo - o - (on - j));
					if (needN + needV + needO <= ovn)
						ans = true;
				}
			}
		}
		if (ans) cout << "DA" << endl;
		else cout << "NE" << endl;
	}
	//system("pause");
	return 0;
}