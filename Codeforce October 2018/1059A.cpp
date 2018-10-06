// 20181006 21:10 ~ 21:18
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

int n,L,a;
int t[100001];
int l[100001];

int main() {
    cin>>n>>L>>a;
    for(int i=1; i<=n; i++){
        sd(t[i]);
        sd(l[i]);
    }
    int ans = 0;
    int prevT = 0;
    int prevI = 0;
    for(int i=1; i<=n; i++){
        ans += (t[i]-1 - (t[i-1] + (l[i-1]-1)))/a;
    }
    ans += (L-1 - (t[n] + (l[n]-1)))/a;
    cout<<ans;
    return 0;
}