// 20190311 20:24 ~ 20:40
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
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

int n, x, y;
int temp;

int main() {
    cin>>n>>x>>y;
    rep(i, 1, n+1) {
        int curr; cin>>curr;
        temp += (curr<=x);
    }
    if(x>y){
        cout<<n<<endl;
        return 0;
    }
    cout<<temp/2 + temp%2<<endl;
    return 0;
}