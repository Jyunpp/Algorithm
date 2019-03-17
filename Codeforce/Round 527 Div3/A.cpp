// 20190317 13:55 ~ 13:58
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

int t, n, k;

int main() {
    cin>>t;
    while(t--) {
        cin>>n>>k;
        int iter = 0;
        rep(i, 1, n+1 ){
            cout<<((char)('a'+iter));
            iter++;
            iter%=k;
        }
        cout<<endl;
    }
}