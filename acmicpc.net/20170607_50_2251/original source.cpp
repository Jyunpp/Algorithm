//20170607
#include <iostream>
#include <queue>
using namespace std;

struct Pos {
	int water[3];
};

int Capacity[3];
int visited[201][201][201];
int ansCheck[202];

int main() {
	cin >> Capacity[0] >> Capacity[1] >> Capacity[2];
	queue<Pos> q;
	visited[Capacity[0]][Capacity[1]][Capacity[2]] = 1;
	q.push(Pos{ {0, 0, Capacity[2] } });
	ansCheck[Capacity[2]] = 1;
	while (!q.empty()) {
		int present[3] = { q.front().water[0], q.front().water[1], q.front().water[2] };
		q.pop();
		//i���� j�� �ױ�
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == j) { continue; }
				int spare = Capacity[j] - present[j]; //j�� ���� �� �ִ� ��
				int delta = (present[i] < spare ? present[i] : spare); //i���� j�� ���� �� �̵��ϴ� ���� ��
				int k = 3 - i - j;
				//iĭ�� present[i] - delta;
				//jĭ�� present[j] + delta;
				//������ĭ�� present[������]
				//ex) i==0, j==1�̸�, [present[i]-delta][present[j]+delta][present[3-i-j]
				//������ �͵鿡 �տ� ����� ������. ����� ù°���ǰ�� 0�̸� 1, 1�̳� 2�� 0��ȯ�ϴ� ���.. 
//				cout << "i : " << i << ", j : " << j << ", k : " << k << endl;
//				cout << "spare : " << spare << ", delta : " << delta << endl;
				int a = (i - 1)*(i - 2)*(present[i] - delta) / 2 + (j - 1)*(j - 2)*(present[j] + delta) / 2 + (k - 1)*(k - 2)*present[k] / 2;
				int b = -1 * i*(i - 2)*(present[i] - delta) + (-1)*j*(j - 2)*(present[j] + delta) + (-1) * k*(k - 2)*present[k];
				int c = i*(i - 1)*(present[i] - delta) / 2 + j*(j - 1)*(present[j] + delta) / 2 + k*(k - 1)*present[k] / 2;
//				cout << "(" << a << ", " << b << ", " << c << ")" << endl;
				if (visited[a][b][c] == 0) { 
					visited[a][b][c] = 1;
					q.push(Pos{ a,b,c });
//					cout << c << endl;
					if (!ansCheck[c] && a==0) { ansCheck[c] = 1; }
				}
			}
		}
	}
	for (int i = 0; i <= Capacity[2]; i++) {
		if (ansCheck[i]) {
			cout << i << " ";
		}
	}
	return 0;
}