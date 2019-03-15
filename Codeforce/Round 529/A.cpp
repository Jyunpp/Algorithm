// 20190315 07:20 ~ 07:23
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

int main() {
    int a;
    string s;
    cin>>a;
    cin>>s;
    int t = 1;
    int curr = 0;
    while(curr<=a) {
        cout<<s.substr(curr, 1);
        curr+=t;
        t++;
    }
    return 0;
    
}