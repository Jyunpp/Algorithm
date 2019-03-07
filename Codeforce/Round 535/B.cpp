// 20190306 20:20 ~ 20:44
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
int arr[10001];

int main() {
    cin>>n;
    vector<int> v;
    rep(i, 1, n+1){
        int a; cin>>a;
        arr[a]++;
    }
    rep(i, 1, 10001) {
        if(arr[i]) v.push_back(i);
    }
    int ret1 = v[v.size()-1];
    int ret2;
    for(int i=v.size()-1; i>=0; i--) {
        int currRet = v[i];
        if(ret1%currRet!=0) {
            ret2 = currRet;
            break;
        }
        if(arr[currRet]==2){
            ret2 = currRet;
            break;
        }
    }
    
    cout<<ret1<<" "<<ret2<<endl;
    return 0;
}