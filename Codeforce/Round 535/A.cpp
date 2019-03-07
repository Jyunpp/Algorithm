// 20190306 20:20 ~ 20:23
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

int t;
int x[2], y[2];
int main() {
    cin>>t;
    while(t--) {
        cin>>x[0]>>y[0]>>x[1]>>y[1];
        int ret1, ret2;
        ret1 = x[0];
        ret2 = x[1];
        while(ret1 == ret2) {
            if(ret1<y[0]) ret1++;
            else ret2++;
        }
        cout<<ret1<<" "<<ret2<<endl;
    }
}