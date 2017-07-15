//20170716 04:13 ~ 05:13
//��� �ʰ��ε� ������ �𸣰ڴ�~
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
using namespace std;
int n;
deque<int> dp['Z' - 'A' + 1][21]; //dp[i][j] means.. j��° string���� 'A' + i ������ index ���� ������������ ����.
char str[21][1000];
int printStartIndex[21]; // p[n] : n��° ���ڿ��� �̹� ����Ʈ�� ��������.
//n�� 1~20 ���. ������ index�� 0~ ���.
int main() {
	cin >> n;
	////dp -1�� �ʱ�ȭ. -> �� �ʿ� ������. 
	//for (int i = 1; i <= n; i++) {
	//	for (int j = 0; j < 'Z' - 'A' + 1; j++)
	//		dp[j][i] = -1;
	//}
	for (int i = 1; i <= n; i++) {
		string currStr;
		cin >> currStr;
		//ó�� ������ ���ڶ�� ����. -> ó���� �ƴ϶� ��� ������ index ����.
		for (int j = 0; j < currStr.length(); j++) {
			str[i][j] = currStr[j];
			int curr = str[i][j] - 'A'; //curr : index
			dp[curr][i].push_back(j);
		}
	}
	// i : 0 ~ 'Z'-'A' ������ ���� ������ string���� �̾Ƴ���. dp[i][j] == -1 �� j���� ����.('A'+ i ���ڰ� ������ �ǹ�.)
	//�̾Ƴ� ��, string ������ �� ���� ���ڵ� ���� �����϶� ���� �� �̾Ƴ�.
	for (int i = 0; i <= 'Z' - 'A'; i++) {
		//�̹� ���� : 'A' + i
		//�̹� ���ڰ� ������ ���ڿ���, �� ���� { ���ڿ� �� �� ������ ù �ε���, ���ڿ� �ε���(��� 1~n) } �� ����.
		vector<pair<int, int>> v;
		for (int j = 1; j <= n; j++) {
			if (!dp[i][j].empty())
				v.push_back({ *dp[i][j].begin(), j }); // �� ����. *�� �³�? �°���?�� �´� GOOD!!
		}
		//�̹� ���ڰ� ������ ���ڿ��� ���ٸ� �ǳʶٱ�.
		if (v.empty())
			continue;
		sort(v.begin(), v.end()); //�̹� ���ڰ� ������ ���ڿ��� �� ���� ������,
		int len = v.size();
		for (int j = 0; j < len; j++) {
			for (int k = printStartIndex[v[j].second]; k <= v[j].first; k++) { // �� ���ڿ� �պκ��� �� �̾Ƴ���.
				cout << str[v[j].second][k];
				dp[str[v[j].second][k] - 'A'][v[j].second].pop_front();//�̹��� ���� ������ index�� dp������ �����ش�.
			}
			//�� ���� ���ڵ� �̹� ���ڿ� ���� ���ڶ�� �� �� �̾Ƴ�. �޶����� �׶��� �ε����� �������� ����Ʈ ������.
			while (str[v[j].second][++v[j].first] == 'A' + i) {
				cout << str[v[j].second][v[j].first];
			}
			printStartIndex[v[j].second] = v[j].first;
		}
	}
	system("pause");
	return 0;
}