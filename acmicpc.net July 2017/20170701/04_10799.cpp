#include <iostream>
#include <string>
using namespace std;
string s;
char last, here;
int ans, temp, len;
int main() {
	cin >> s;
	len = s.length();
	last = s[0];
	temp++;
	for (int i = 1; i < len; i++) {
		here = s[i];
		if (here == '(') {
			temp++;
		}
		else {
			if (last == '(') {
				temp--;
				ans += temp;
			}
			else {
				ans += 1;
				temp--;
			}
		}
		last = here;
	}
	cout << ans;
	/*system("pause");*/
	return 0;
}