//20170530
//��ǥ���� �÷��̵� �ͼ� �˰��� �������� �� ����� �̿�.

//�ںκп� ���� ���� �� ����.

//ó������ for�� i->j->k ���� ��,
//i,j ���� && j,k �����̸� i,k �����ϴ� ������� �ߴ�.
//�׷��� �ϸ� ���� ���� ������ �̿��ؼ� �߰� ������ ������ �� ����.

//for�� i->j->k ���� ��,
//j,i ���� && i,k �����̸� j, k�����ϴ� ������� �ؾ���.
//connection vertex �� i�� �ϰ�, i�� ���� ū for��, �� i�� �߽����� ���ƾ�
//���� ���� ������ ���� ���ῡ �ݿ��� �� ����.
#include <iostream>
#include <queue>
using namespace std;

int n;
int arr[101][101];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (arr[j][i] && arr[i][k]) {//��
					arr[j][k] = 1;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	/*cin >> n;*/
	return 0;
}