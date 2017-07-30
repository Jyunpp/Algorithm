//20170728 stl을 잘 배우자..
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int n, total, printed;

int main(){
	cin >> n;
	vector<string> a(n);
	for (int i = 0; i < n; i++){
		cin >> a[i];
		total += a[i].length();
		a[i] += 'Z' + 1;
	}
	while (printed != total) {
		sort(a.begin(), a.end());
		cout << a[0][0]; 
		printed++;
		a[0].erase(a[0].begin());
	}
	//system("pause");
	return 0;
}