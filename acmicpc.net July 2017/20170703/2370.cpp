//20170703.. 계절학기 중간고사 끝나고 자료구조 책 복습해서 구조체로 구현하자..
#include <iostream>
using namespace std;

int arr[100][2];
int n;
char p, l, r;

void preorder(int n);
void inorder(int n);
void postorder(int n);

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p >> l >> r;
		arr[p][0] = l;
		arr[p][1] = r;
	}
	preorder('A'); cout << endl;
	inorder('A'); cout << endl;
	postorder('A'); cout << endl;
	/*system("pause");*/
	return 0;
}

void preorder(int n) {
	if (n == '.') return;
	cout << (char)n;
	preorder(arr[n][0]);
	preorder(arr[n][1]);
}

void inorder(int n) {
	if (n == '.') return;
	inorder(arr[n][0]);
	cout << (char)n;
	inorder(arr[n][1]);
}
void postorder(int n) {
	if (n == '.') return;
	postorder(arr[n][0]);
	postorder(arr[n][1]);
	cout << (char)n;
}