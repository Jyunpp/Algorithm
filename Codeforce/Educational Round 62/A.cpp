// 20190322 00:05 ~ 00:13
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
#include <map>
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
int arr[10001];

int main() {
    cin>>n;
    int ans = 0;
    rep(i, 1, n+1) {
        cin>>arr[i];
    }
    int maxx = -1;
    rep(i, 1, n+1) {
        maxx = max(maxx, arr[i]);
        if(maxx>i) {
            continue;
        }
        else ans++;
    }
    cout<<ans<<endl;
}