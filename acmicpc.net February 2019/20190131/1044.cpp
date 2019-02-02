// 20190131 14:15 ~ 14:27 메모리 초과. 수정예정.
// 20190201 23:20 ~ 23:42 시간초과. C(36, 18) 90억
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
typedef pair<ll, ll> Pll;

int n;
ll arr[3][37];
ll ans;
string ansStr;

void recur(string s, int numOfTeam1, ll diff, int idx) {
    if(s.size() == n) {
        if(diff<0) diff*=-1;
        if(diff<ans) {
            ansStr = s;
            ans = diff;
        }
    }
    else {
        if(numOfTeam1 < n/2) {
            recur(s+"1", numOfTeam1+1, diff+arr[1][idx], idx+1);
        }
        recur(s+"2", numOfTeam1, diff-arr[2][idx], idx+1);
    }
    return ;
}

int main(){
    cin>>n;
    for(int i=1; i<=2; i++) {
        for(int j=1; j<=n; j++) {   
            cin>>arr[i][j];
        }
    }
    
    ans = 10e15 *36;
    recur("", 0, 0, 1);

    for(int i=0; i<n; i++) {
        cout<<ansStr[i]<<" ";
    }
    return 0;
}