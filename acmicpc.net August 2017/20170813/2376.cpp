//20170813 15:39 ~ 18:02 
//�ð� �ʰ��� �����µ�, root, depth �迭 ũ�⸦ 
//�������� 1001�� ��Ƽ�(�ܸ� ����� root�� depth�� �����ϴ��� �˰�..) �׷���!!
//���� ����ߴ�~~~~~~~~

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
void merge(int nodeA, int nodeB, int newNodeNum) {//newNodeNumȣ�� �� ����������.
												  //classified
	return;
}

int findDistance(int a, int b) {
	int distance = 0;
	//classified
	return distance;
}

int main() {
	//�Է� �� �ʱ�ȭ
	scanf("%d", &n);
	for (int i = 1; i <= n - 1; i++) {
		scanf(" %d", &dis[i]);
		//classified
	}
	root[n] = n;
	
	//�� n-1���� ������ �Ѵ�.
	int newNodeNum = n + 1;		//���� ����� ����� ��ȣ�� n+1����.
	int mergeCnt = 0;			//n-1������ ä��� ��.
	int currDis = 2;			//classified
	while (mergeCnt < n - 1) {
		for (int i = 1; i <= n - 1; i++) {
			if (mergedCheck[i]) continue;			//�̹� ���� �� �� pass
			if (dis[i] == currDis) {
				merge(i, i + 1, newNodeNum++);		//����
				mergeCnt++;							//����Ƚ�� ����.
				mergedCheck[i] = 1;					//���տ��� ����.
			}
		}
	}

	//�Ÿ����ϱ�.
	scanf(" %d %d", &no1, &no2);
	printf("%d\n", findDistance(no1, no2));
	//system("pause");
	return 0;
}