//20181002 retry 22:10 ~ 23:00
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>
using namespace std;

#define sd(x) scanf(" %d", &x);
#define slld(x) scanf(" %lld", &x);
#define pb push_back
#define xx first
#define yy second

typedef long long ll;
typedef pair<int, int> P;

int n, h;
pair<int, int> arr[200001]; //{x1, x2}
int Ans;

int main() {
	cin >> n >> h;
	for (int i = 1; i <= n; i++) {
		sd(arr[i].xx);
		sd(arr[i].yy);
	}
	int flyLen = arr[1].yy - arr[1].xx;
	int currH = h;
	int startIdx = 1;
	int currX = arr[1].yy;
	Ans = max(Ans, flyLen + currH);
	int i = 2; // 갈 곳
	while(i<=n){
		int needH = arr[i].xx - currX;
		while(flyLen>0){
			if(needH<currH) break;
			currX = arr[startIdx+1].yy;
			flyLen -= arr[startIdx+1].xx - arr[startIdx].xx;
			currH += arr[startIdx+1].xx - arr[startIdx].yy;
			startIdx++;
		}
		//갈 수 있다면
		if(flyLen>0){
			flyLen += arr[i].yy - arr[i-1].yy;
			currX = arr[i].yy;
			currH -= arr[i].xx - arr[i-1].yy;
			Ans = max(Ans, flyLen + currH);
		}
		//없다면 
		else {
			currH = h;
			flyLen = arr[i].yy - arr[i].xx;
			currX = arr[i].yy;
			Ans = max(Ans, flyLen + currH);
		}
		i++;
	}
	cout<<Ans<<endl;
}