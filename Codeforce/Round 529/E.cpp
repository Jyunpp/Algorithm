// 20190316 23:00 ~ 
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
#define rep(i, l, r) for(int i=l; i<r; i++)
#define sortV(v, lambda) sort(v.begin(), v.end(), lambda)
#define powll(a, b) (ll) pow(a, b)

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;

int n;
char ch[1000001];
int arr[1000001];
bool can[1000001];

int main() {
    cin>>n;
    can[0] = true;
    rep(i, 1, n+1) {
        cin>>ch[i];
        arr[i] = arr[i-1] + (ch[i] =='(' ? 1 : -1);
        can[i] = can[i-1] & (arr[i] >= 0);
    }
    int ret = 0;
    int temp = 1000001;
    for(int i=n; i>=1; i--) {
        temp = min(temp, arr[i]);
        if(!can[i-1]) continue;
        int diff = (ch[i] == '(' ? -2 : 2);
        ret += (arr[n] + diff == 0 && temp + diff >= 0);
    }
    cout<<ret<<endl;
    return 0;
}