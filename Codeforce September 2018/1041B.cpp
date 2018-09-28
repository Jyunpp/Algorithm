// 20180928 21:55 ~ 22:08
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

typedef long long ll;
typedef pair<int, int> P;

ll a, b, x, y;

ll solve(){
    ll tempX = max(x,y);
    ll tempY = min(x,y);
    while(tempX!=0 && tempY!=0){
        ll r = tempX%tempY;
        tempX = tempY;
        tempY = r;
    }
    x /=tempX;
    y /=tempX;
    ll ans1 = a/x;
    ll ans2 = b/y;
    return min(ans1, ans2);
}

int main() {
    cin>>a>>b>>x>>y;
    cout<<solve();
}