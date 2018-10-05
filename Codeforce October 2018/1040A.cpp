// 20181005 18:00 ~ 18:18
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

int n;
int cost[2];
int arr[21];

int main() {
	cin>>n>>cost[0]>>cost[1];
	for(int i=1; i<=n; i++){
		cin>>arr[i];
	}
	int ans = 0;
	for(int i=1; i<=n/2; i++){
		if(arr[i]!=arr[n-i+1]){
			if(arr[i]!=2&&arr[n-i+1]!=2){
				ans = -1;
				break;
			}
			int need = min(arr[i], arr[n-i+1]);
			ans += cost[need];
		}else{
			if(arr[i]==2){
				ans += 2*min(cost[0], cost[1]);
			}
		}
	}
	if(ans!=-1&&n%2==1 && arr[n/2 + 1]==2){
		ans += min(cost[0], cost[1]);
	}
	cout<<ans<<endl;
}