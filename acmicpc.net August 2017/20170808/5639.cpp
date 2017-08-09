//20170808 19:25 ~	19:56

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>
using namespace std;

struct Node {
	int num, leftIdx, rightIdx;
}nodeArr[10001];
int n;

void postOrder(int sIdx) {
	if (nodeArr[sIdx].leftIdx != -1)
		postOrder(nodeArr[sIdx].leftIdx);
	if (nodeArr[sIdx].rightIdx != -1)
		postOrder(nodeArr[sIdx].rightIdx);
	printf("%d ", nodeArr[sIdx].num);
}

int main() {
	for (int i = 1; i <= 10000; i++)
		nodeArr[i].leftIdx = nodeArr[i].rightIdx = -1;

	stack<int> s;						//idx 저장.
	scanf("%d", &nodeArr[1].num);
	s.push(1);
	int input, i = 1;
	while (scanf("%d", &input) !=EOF){	//입력 횟수 모를 때.
		i++;
		nodeArr[i].num = input;
		if (nodeArr[i].num < nodeArr[s.top()].num) {
			nodeArr[s.top()].leftIdx = i;
			s.push(i);
		}
		else {
			int temp;
			while (!s.empty()&&nodeArr[s.top()].num < nodeArr[i].num ) {
				temp = s.top();
				s.pop();
			}
			nodeArr[temp].rightIdx = i;
			s.push(i);
		}
	}

	postOrder(1);
	//system("pause");
	return 0;
}