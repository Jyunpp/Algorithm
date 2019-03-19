// 20190318 21:17 ~ 
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
int arr[101];

int main() {
    cin>>n;
    rep(i, 1, n+1) cin>>arr[i];
    int ret = 0;
    rep(i, 2, n) {
        if(!arr[i] && arr[i-1] && arr[i+1]) {
            arr[i+1] = 0;
            ret++;
        }
    }
    cout<<ret<<endl;
    return 0;
}