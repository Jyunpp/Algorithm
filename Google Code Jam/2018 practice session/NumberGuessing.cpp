// 20190214
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

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;

int T;
int a, b, n;

int main() {
    cin>>T;
    while(T--) {
        cin>>a>>b>>n;
        a++;
        while(n--) {
            int m = ((a+b)>>1);
            cout<<m<<endl;
            string s;
            cin>>s;
            if(s=="TOO_BIG") b = m-1;
            else if (s=="TOO_SMALL") a = m+1;
            else if (s=="CORRECT") break;
        }
    }
}