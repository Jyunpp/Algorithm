//20170716
#include <iostream>
#include <algorithm>
using namespace std;

#define sz 300001

int h[sz], moveL[sz], moveR[sz];
char t[sz];
int n, k;

int main() {
	cin >> n >> k; k--;
	for (int i = 0; i < n; i++)
		cin >> h[i];
	cin >> t;
	//�������� �̵� �� �� �ִ� ���,
	//�������� �̵� ���� ���̸� �÷����� ����,
	//������ T���(T�� ���� : T�̰ų� ���� ���⿡ T�� ������ �� �� �ִ�.) �̹��� T�� ���·�.
	for (int i = 1; i < n; i++) {
		if (h[i] < h[i - 1]) continue;
		if (t[i - 1] == 'T') t[i] = 'T';
		moveL[i] = 1 + moveL[i - 1];
	}
	//�����ʵ� ����.
	for (int i = n - 2; i >= 0; i--) {
		if (h[i] < h[i + 1]) continue;
		if (t[i + 1] == 'T') t[i] = 'T';
		moveR[i] = 1 + moveR[i + 1];
	}
	//T�� ������, T�� ���� ���� �� �ִ� ���̸� ���Ѵ�.
	int T = 0, best = 0;
	for (int i = 0; i < n; i++) {
		if (t[i] == 'T') T++;
		else best = max(best, 1 + max(moveL[i], moveR[i]));
	}
	//���� ���� T��� ����, �������� ������ �̾��� ������ ��� �� �� ������
	//������ ���� ��� T�� �̾��� ������ ���ε��� �� �� �ִ�.
	//=> T�� ���� + T�� ���� ������ �ִ� ���� ���
	if (t[k] == 'T')
		cout << T + best << endl;
	//���� ���� T�� �ƴ϶��, �������� ���� ������ �� �� �� �ִ� �̵� ���� + �������� ���
	else {
		int l = k, r = k;
		//�¿������� ������ ���� ������ �� �� �����Ƿ� �������.
		while (l > 0 && h[l - 1] == h[k]) l--;
		while (r < n - 1 && h[r + 1] == h[k]) r++;
		cout << r - l + 1 + max(moveL[l], moveR[r]) << endl;
	}
	system("pause");
	return 0;
}