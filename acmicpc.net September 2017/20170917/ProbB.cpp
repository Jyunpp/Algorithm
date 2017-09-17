//20170917 02:18 ~ 03:19
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

int a, b;
vector<int> v;

int main() {
	scanf("%d %d", &a, &b);
	int bunmo = 0;
	int bunja = 0;

	for (int i = 1; i <= 10; i++) {
		int times = 2;
		if (i == a) times--;
		if (i == b) times--;
		for (int j = 0; j < times; j++) {
			v.push_back(i);
		}
	}

	int score;
	if (a == b)
		score = 11 - a;
	else
		score = 10 + (10 - (a + b) % 10);

	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) {
			int c = v[i];
			int d = v[j];
	
			int score2;
			if (c == d)
				score2 = 11 - c;
			else 
				score2 = 10 + (10 - (c + d) % 10);
			
			if (score < score2) bunja++;
			bunmo++;
		}
	}

	printf("%.3lf\n", float(bunja) / float(bunmo));
	system("pause");
	return 0;
}