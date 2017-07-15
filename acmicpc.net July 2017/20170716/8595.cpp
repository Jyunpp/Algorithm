//20170716 03:10 ~ 03:28
#include <iostream>
using namespace std;

int n, temp = -1, templen = -1;
char curr;
long long ans;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> curr;
		//이번 문자가 숫자라면
		if (curr >= '0' && curr <= '9') {
			//이전에 문자가 숫자가 아니었다.
			if (temp == -1) {
				temp = curr - '0';
				templen = 1;
			}
			//이전 문자에 이미 숫자가 있었다.
			else {
				temp *= 10;
				temp += (curr - '0');
				templen++;
				//이번 문자까지 더했더니 6자리를 넘는다?
				//=> 문자처리 해준다.
				if (templen > 6) {
					temp = -1;
					templen = -1;
				}
			}
		}
		//이번 문자가 숫자가 아니라면
		else {
			//그런데 이전까진 숫자가 있었다면.
			if (temp != -1) {
				ans += temp;
				temp = -1;
				templen = -1;
			}
		}
	}
	//마지막까지 받은 게 숫자 였다면..즉, temp에 숫자가 남아있는 경우.
	if (temp != -1) {
		ans += temp;
	}
	cout << ans << endl;
//	system("pause");
	return 0;
}