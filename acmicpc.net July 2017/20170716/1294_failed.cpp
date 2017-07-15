//20170716 04:13 ~ 05:13
//출력 초과인데 이유를 모르겠다~
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
using namespace std;
int n;
deque<int> dp['Z' - 'A' + 1][21]; //dp[i][j] means.. j번째 string에서 'A' + i 문자의 index 들을 오름차순으로 저장.
char str[21][1000];
int printStartIndex[21]; // p[n] : n번째 문자열의 이번 프린트의 시작지점.
//n만 1~20 사용. 나머지 index는 0~ 사용.
int main() {
	cin >> n;
	////dp -1로 초기화. -> 할 필요 없어짐. 
	//for (int i = 1; i <= n; i++) {
	//	for (int j = 0; j < 'Z' - 'A' + 1; j++)
	//		dp[j][i] = -1;
	//}
	for (int i = 1; i <= n; i++) {
		string currStr;
		cin >> currStr;
		//처음 나오는 문자라면 저장. -> 처음이 아니라 모든 문자의 index 저장.
		for (int j = 0; j < currStr.length(); j++) {
			str[i][j] = currStr[j];
			int curr = str[i][j] - 'A'; //curr : index
			dp[curr][i].push_back(j);
		}
	}
	// i : 0 ~ 'Z'-'A' 순으로 빨리 만나는 string에서 뽑아낸다. dp[i][j] == -1 인 j들은 제외.('A'+ i 문자가 없음을 의미.)
	//뽑아낼 떄, string 내에서 그 다음 문자도 같은 문자일때 까지 다 뽑아냄.
	for (int i = 0; i <= 'Z' - 'A'; i++) {
		//이번 문자 : 'A' + i
		//이번 문자가 나오는 문자열은, 그 정보 { 문자열 내 그 문자의 첫 인덱스, 문자열 인덱스(얘는 1~n) } 를 저장.
		vector<pair<int, int>> v;
		for (int j = 1; j <= n; j++) {
			if (!dp[i][j].empty())
				v.push_back({ *dp[i][j].begin(), j }); // 그 정보. *가 맞나? 맞겟지?★ 맞다 GOOD!!
		}
		//이번 문자가 나오는 문자열이 없다면 건너뛰기.
		if (v.empty())
			continue;
		sort(v.begin(), v.end()); //이번 문자가 나오는 문자열들 중 빠른 순으로,
		int len = v.size();
		for (int j = 0; j < len; j++) {
			for (int k = printStartIndex[v[j].second]; k <= v[j].first; k++) { // 그 문자와 앞부분을 다 뽑아낸다.
				cout << str[v[j].second][k];
				dp[str[v[j].second][k] - 'A'][v[j].second].pop_front();//이번에 나온 문자의 index를 dp에서도 없애준다.
			}
			//그 다음 문자도 이번 문자와 같은 문자라면 쭉 다 뽑아냄. 달라지면 그때의 인덱스가 다음번의 프린트 시작점.
			while (str[v[j].second][++v[j].first] == 'A' + i) {
				cout << str[v[j].second][v[j].first];
			}
			printStartIndex[v[j].second] = v[j].first;
		}
	}
	system("pause");
	return 0;
}