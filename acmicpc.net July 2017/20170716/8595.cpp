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
		//�̹� ���ڰ� ���ڶ��
		if (curr >= '0' && curr <= '9') {
			//������ ���ڰ� ���ڰ� �ƴϾ���.
			if (temp == -1) {
				temp = curr - '0';
				templen = 1;
			}
			//���� ���ڿ� �̹� ���ڰ� �־���.
			else {
				temp *= 10;
				temp += (curr - '0');
				templen++;
				//�̹� ���ڱ��� ���ߴ��� 6�ڸ��� �Ѵ´�?
				//=> ����ó�� ���ش�.
				if (templen > 6) {
					temp = -1;
					templen = -1;
				}
			}
		}
		//�̹� ���ڰ� ���ڰ� �ƴ϶��
		else {
			//�׷��� �������� ���ڰ� �־��ٸ�.
			if (temp != -1) {
				ans += temp;
				temp = -1;
				templen = -1;
			}
		}
	}
	//���������� ���� �� ���� ���ٸ�..��, temp�� ���ڰ� �����ִ� ���.
	if (temp != -1) {
		ans += temp;
	}
	cout << ans << endl;
//	system("pause");
	return 0;
}