// 20190325 09:30 ~ 09:36 retried.
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
int arr[200001];

int main() {
    cin>>n;
    rep(i, 1, n+1) cin>>arr[i];
    ll curr = arr[n];
    ll ret = arr[n];
    for(int i=n-1; i>=1; i--) {
        if(curr-1 < arr[i]) curr--;
        else curr = arr[i];
        if(curr<0) curr = 0;
        ret += curr;
    }
    cout<<ret<<endl;
    return 0;
}