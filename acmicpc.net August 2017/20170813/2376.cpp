//20170813 15:39 ~ 18:02 
//시간 초과가 떴었는데, root, depth 배열 크기를 
//생각없이 1001로 잡아서(단말 노드의 root와 depth만 저장하는줄 알고..) 그랬다!!
//논리가 대단했다~~~~~~~~

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int n, no1, no2;
int root[100001];			//classified
int parent[100001];			//classified
int	depth[100001];			//classified
int dis[1000];				//classified
int mergedCheck[1000];		//classified
vector<int> child[100001];	

//classified
void updateSubtree(int prevRoot, int newRoot) {
	//classified
	return;
}

//classified
void merge(int nodeA, int nodeB, int newNodeNum) {//newNodeNum호출 시 후위증가로.
												  //classified
	return;
}

int findDistance(int a, int b) {
	int distance = 0;
	//classified
	return distance;
}

int main() {
	//입력 및 초기화
	scanf("%d", &n);
	for (int i = 1; i <= n - 1; i++) {
		scanf(" %d", &dis[i]);
		//classified
	}
	root[n] = n;
	
	//총 n-1번의 병합을 한다.
	int newNodeNum = n + 1;		//새로 생기는 노드의 번호는 n+1부터.
	int mergeCnt = 0;			//n-1번까지 채우면 끝.
	int currDis = 2;			//classified
	while (mergeCnt < n - 1) {
		for (int i = 1; i <= n - 1; i++) {
			if (mergedCheck[i]) continue;			//이미 병합 한 곳 pass
			if (dis[i] == currDis) {
				merge(i, i + 1, newNodeNum++);		//병합
				mergeCnt++;							//병합횟수 갱신.
				mergedCheck[i] = 1;					//병합여부 갱신.
			}
		}
	}

	//거리구하기.
	scanf(" %d %d", &no1, &no2);
	printf("%d\n", findDistance(no1, no2));
	//system("pause");
	return 0;
}