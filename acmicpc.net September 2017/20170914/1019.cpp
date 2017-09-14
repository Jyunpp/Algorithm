//20170914 10:46 ~ 20:07
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;

int n;
long long ans[10];

int main() {
	scanf("%d", &n);
	int curr = 1;		//���� �ڸ���
	int prev = 0;		//���� �ڸ����� ���ڰ� ���� Ƚ���� ���ϱ� ���� ����.
	while (n) {
		int currNum = n % 10;	//���� �ڸ����� ���� 
		int nOverTen = n / 10;	//���� �ڸ��� �̻� �κ��� ����. A

		//������ ���ڿ� ���ؼ� ���� �ڸ��� ��ġ���� �� �� ������ ���.

		//currNum���� ū ���ڴ� (A * ���� �ڸ���) ��ŭ ����.
		for (int i = currNum + 1; i <= 9; i++) {
			ans[i] += nOverTen*curr;
		}
		//currNum�� (A * ���� �ڸ��� ��ŭ) ������
		//prev �κ� ������ currNum�̹Ƿ� prev + 1��ŭ �߰��� ���´�.
		ans[currNum] += nOverTen*curr + prev + 1;
		//currNum���� ���� ���ڴ� ((A+1) * ���� �ڸ���) ��ŭ ����.
		for (int i = 0; i < currNum; i++) {
			ans[i] += (nOverTen + 1) *curr;
		}
		//�� ��, 0�� ���� ���ڸ� ������ �� �����Ƿ�, curr��ŭ ���ش�.
		ans[0] -= curr;
		prev += currNum*curr;
		curr *= 10;
		n /= 10;
	}
	for (int i = 0; i <= 9; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	//system("pause");
	return 0;
}