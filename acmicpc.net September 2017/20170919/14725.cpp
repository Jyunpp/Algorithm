//20170918 10:04 ~ 20170919 16:25
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#define xx first
#define yy second

#include <iostream>
#include <stdio.h>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <queue>
using namespace std;

//1000개의 먹이 정보 각 최대 15개 => 최대 노드 갯수는 15000개
//루트노드는 0으로
int n;
string hyphen = "--";
vector<pair<string, int>> child[15002];	//child[i] : i번 노드의 자녀노드의 정보 { 이름, 노드번호 }
//vector<pair<string, int>> parent[15002];	//parent[i] : i번 노드의 부모노드의 s, 

void print_recur(int currNode, int layer);

int main() {
	std::ios::sync_with_stdio(false);		//cout 속도..

	cin >> n;
	bool havetoFind;
	int currNode;
	int nodeCnt = 0;
	bool haveThis;
	for (int i = 1, a; i <= n; i++) {
		cin >> a;
		string s;
		currNode = 0;
		havetoFind = true;
		for (int j = 1; j <= a; j++) {
			cin >> s;
			//찾아봐야 한다면,
			if (havetoFind) {
				haveThis = false;
				for (int k = 0; k < child[currNode].size(); k++) {
					if (child[currNode][k].xx == s) {
						haveThis = true;
						//찾았으면 그리 이동 후 종료
						currNode = child[currNode][k].yy;
						break;
					}
				}
				//못찾았으면 child추가 & 이동 후 안찾아도된다고 토글 후 종료
				if (!haveThis) {
					child[currNode].push_back({ s,++nodeCnt });
					currNode = nodeCnt;
					havetoFind = false;
				}
			}
			//안찾아봐야 한다면 그냥 추가 & 이동.
			else {
				child[currNode].push_back({ s, ++nodeCnt });
				currNode = nodeCnt;
			}
		}
	}
	print_recur(0, 0);
	//system("pause");
	return 0;
}

void print_recur(int currNode, int layer){
	sort(child[currNode].begin(), child[currNode].end(), [](pair<string, int> a, pair<string, int> b) {return a.xx < b.xx; });
	int sz = child[currNode].size();
	
	for (int i = 0; i < sz; i++) {
		
		for (int j = 1; j <= layer; j++) {
			cout << hyphen;
		}
		cout << child[currNode][i].xx << endl;

		print_recur(child[currNode][i].yy, layer + 1);
	}
}