// 20190303 16:46 ~ 17:07
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
int arr[200001];
ll o[200001];
ll e[200001];
int ret;

ll calcO(int i) {
    return o[i-1] + e[n] - e[i];
}
ll calcE(int i) {
    return e[i-1] + o[n] - o[i];
}

int main() {
    cin>>n;
    rep(i, 1, n+1) {
        cin>>arr[i];
        o[i] = o[i-1];
        e[i] = e[i-1];
        if(i%2) {
            o[i] += arr[i];
        } else {
            e[i] += arr[i];
        }
    }
    rep(i, 1, n+1) {
        if (calcO(i) == calcE(i)) ret++;
    }
    cout<<ret<<endl;
    return 0;
}