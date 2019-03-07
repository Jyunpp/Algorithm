// 20190308 0:05 ~ 00:13
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

int a, b, c, d;

int main() {
    char ch;
    cin>>a>>ch>>b>>c>>ch>>d;
    int ret = a*60+b + (c*60+d - (a*60+b))/2;
    if(ret/60<=9) {
        cout<<"0";
    }
    cout<<ret/60<<":";
    if(ret%60<=9){
        cout<<"0";
    }
    cout<<ret%60<<endl;
    return 0;
}