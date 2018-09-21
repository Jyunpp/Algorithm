//20180922 23:16 ~ 23:50
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

int n, ans = 9999999;
string s[7] = {"A", "B", "C", "AB", "AC", "BC", "ABC"};
string s2[7] = {"A", "B", "C", "BA", "CA", "CB", "ACB"};
string s3[7] = {"A", "B", "C", "BA", "CA", "CB", "BAC"};
string s4[7] = {"A", "B", "C", "BA", "CA", "CB", "BCA"};
string s5[7] = {"A", "B", "C", "BA", "CA", "CB", "CBA"};
string s6[7] = {"A", "B", "C", "BA", "CA", "CB", "CAB"};
vector<int> minCostsV(7, 9999999);

int main() {
	cin>>n;
	for(int i=1; i<=n; i++){
		int cost;
		string curr;
		cin>>cost>>curr;
		for(int j=0; j<7; j++){
			if(s[j]==curr||s2[j]==curr||s3[j]==curr||s4[j]==curr||s5[j]==curr||s6[j]==curr)
				minCostsV[j] = min(minCostsV[j], cost);
		}
	}
	ans = min(ans, minCostsV[0] + minCostsV[1] + minCostsV[2]);
	ans = min(ans, minCostsV[0] + minCostsV[5]);
	ans = min(ans, minCostsV[1] + minCostsV[4]);
	ans = min(ans, minCostsV[2] + minCostsV[3]);
	ans = min(ans, minCostsV[6]);
	ans = min(ans, minCostsV[3] + minCostsV[4]);
	ans = min(ans, minCostsV[3] + minCostsV[5]);
	ans = min(ans, minCostsV[4] + minCostsV[5]);
	if(ans == 9999999){
		cout<<-1<<endl;
	}
	else {
		cout<<ans<<endl;
	}
	system("pause");
}