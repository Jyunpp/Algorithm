//20170724 20:40 ~ 21:28
#include <iostream>
using namespace std;

char arr[3100][6200];
int n, temp, k = 0;

int main() {
	cin >> n;
	temp = n / 3;
	while (temp / 2 != 0) {
		temp /= 2;
		k++;
	}
	//�� ���� ���� �ֱ�.
	arr[1][1] = '*';
	arr[2][1] = arr[2][3] = '*'; arr[2][2] = ' ';
	arr[3][1] = arr[3][2] = arr[3][3] = arr[3][4] = arr[3][5] = '*';
	//������ �ٵ��� �����ذ��� �ֱ�.
	for (int i = 1; i <= k; i++) {
		int copyEndRow = 3;
		int copyStartRow;
		int copyRowDistance;
		int space;
		int copyColumnNumber;
		for (int j = 1; j <= i; j++)
			copyEndRow *= 2;
		copyStartRow = copyEndRow / 2 + 1;
		copyRowDistance = copyEndRow / 2;
		space = copyRowDistance * 2 - 1; //���ķ� ���� �� �� �ٲ� ������ -2��.
		copyColumnNumber = 1;//���ķ� ���� �� �� �ٲ𶧸��� +2��.
		
		for (int row = copyStartRow; row <= copyEndRow; row++) {
			int currColumn = 1;
			//�ﰢ��
			for (int column = 1; column <= copyColumnNumber; column++)
				arr[row][currColumn++] = arr[row - copyRowDistance][column];
			//����
			for (int sp = 1; sp <= space; sp++)
				arr[row][currColumn++] = ' ';
			//�ﰢ��
			for (int column = 1; column <= copyColumnNumber; column++)
				arr[row][currColumn++] = arr[row - copyRowDistance][column];
			space -= 2;
			copyColumnNumber += 2;
		}
	}
	//���
	for (int i = 1; i <= n; i++) {//�� n��
		for (int j = 1; j <= n - i; j++)
			cout << " ";
		for (int j = 1; j <= 2 * i - 1; j++) {
			cout << arr[i][j];
		}
		for (int j = 1; j <= n - i; j++)
			cout << " ";
		cout << endl;
	}
	//system("pause");
	return 0;
}