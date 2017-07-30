//20170729 02:58 ~ 03:45
//강산이가 못 푼 문제 풀어보자.
// 번호 -> 위치 -> 이동 -> 위치 -> 번호 순으로 풀자.
#include <iostream>
using namespace std;

#define point pair<long long, long long>

int d;
char str[51];
char ans[51];
point moving;

//제일 왼쪽 위 점을 (1, 1)로 보고, 위치를 반환.
point getLocation(char *str) {
	long long x = 1, y = 1;
	long long adj = 1;
	for (int i = 2; i <= d; i++)
		adj *= 2;
	for (int curr = 1; curr <= d; curr++) {
		if (str[curr] == '1')
			x += adj;
		else if (str[curr] == '3')
			y += adj;
		else if (str[curr] == '4') {
			x += adj;
			y += adj;
		}
		adj /= 2;
	}
	return point{ x,y };
}

void solve(point curr) {
	long long len = 1;
	for (int i = 1; i <= d; i++)
		len *= 2;
	if (curr.first<1 || curr.first>len || curr.second<1 || curr.second>len) {
		cout << -1 << endl;
		return;
	}
	for (int i = 1; i <= d; i++) {
		len /= 2;
		if (curr.first > len && curr.second > len) {
			ans[i] = '4';
			curr.first -= len;
			curr.second -= len;
		}
		else if (curr.first>len && curr.second<=len) {
			ans[i] = '1';
			curr.first -= len;
		}
		else if (curr.first<=len && curr.second<=len) {
			ans[i] = '2';
		}
		else {
			ans[i] = '3';
			curr.second -= len;
		}
	}
	for (int i = 1; i <= d; i++)
		cout << ans[i];
	cout << endl;
	return;
}

int main() {
	cin >> d;
	for (int i = 1; i <= d; i++)
		cin >> str[i];
	cin >> moving.first >> moving.second;
	point startLocation = getLocation(str);
	point endLocation = { startLocation.first + moving.first, startLocation.second - moving.second };
	solve(endLocation);
	system("pause");
	return 0;
}