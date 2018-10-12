// 20181013 00:05 ~ 00:21
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
#define pb push_back
#define xx first
#define yy second
// #define Mod 998244353

typedef long long ll;
typedef pair<int, int> P;

int n, m;
int arrN[200001];
int arrM[200001];
ll dpN[200001];
int psM[200001];

int main() {
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=n; i>=1; i--){
        char ch = s[n-i];
        arrN[i] = ch=='1';
    }
    dpN[1] = 1;
    for(int i=2; i<=n; i++){
        dpN[i] = (dpN[i-1]*2)%998244353;
    }
    cin>>s;
    for(int i=m; i>=1; i--){
        char ch = s[m-i];
        arrM[i] = ch=='1';
        psM[i] = psM[i+1] + arrM[i];
    }
    ll ans = 0;
    for(int i=1; i<=m; i++){
        if(arrN[i]){
            ans += (dpN[i]*psM[i]);
            ans%=998244353;
        }
    }
    cout<<ans<<endl;
}