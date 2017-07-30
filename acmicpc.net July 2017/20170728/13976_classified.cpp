//20170729 12:47 ~ 02:30
#include <iostream>
#include <vector>
using namespace std;
#define mod 1000000007
long long n, N;
long long arr[61][3][3]; //classified
long long needArr[3][3]; //classified
long long ans;
long long a2 = 3, b2 = 2;//classified
						 //classified
						 //classified

void getBinary( vector<int> &v, long long n) {
	while (n / 2) {
		v.push_back(n % 2);
		n /= 2;
	}
	v.push_back(1);
}

int main() {
	cin >> n;
	if (n % 2) { cout << 0 << endl; return 0; }     //classified
	if (n == 2) { cout << 3 << endl; return 0; }    //classified
	
	N = (n - 2) / 2;								//classified
	vector<int> binaryN;
	getBinary(binaryN, N);
	int len = binaryN.size();
	////test
	//for (int i = 0; i < len; i++)
	//	cout << binaryN[i] << " ";
	//cout << endl;
	////testend
	
	//classified

	if (binaryN[0] == 1) {							//classified
		//classified								//classified
	}
	for (int i = 1; i < len; i++) {					//classified
		//classified
		//classified
		//classified
		if (binaryN[i]) {
			//classified
		}
	}
	//classified
	cout << ans << endl;
	system("pause");
	return 0;
}