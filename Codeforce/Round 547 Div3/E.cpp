// 20190319 
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

ll H;
ll sum, ret;
ll mini;
int n;
int arr[200001];

int main() {
    cin>>H>>n;
    mini = 987654321;
    rep(i, 1, n+1) cin>>arr[i];
    rep(i, 1, n+1) {
        H+=arr[i];
        sum+=arr[i];
        mini = min(mini, sum);
        ret++;
        if(H<=0) {
            cout<<ret;
            return 0;
        }
    }
    if(sum>=0) {
        cout<<-1;
        return 0;
    }
    // cout<<"ret : "<<ret<<endl;
    ll tempH = H + mini;
    // cout<<"tempH : "<<tempH<<endl;
    ret += (tempH/(-sum))*n;
    H += (tempH/(-sum))*sum;
    // cout<<ret<<endl;
    // cout<<H<<endl;
    rep(j, 1, 3) {
        rep(i, 1, n+1) {
            H+=arr[i];
            sum+=arr[i];
            mini = min(mini, sum);
            ret++;
            if(H<=0) {
                cout<<ret;
                return 0;
            }
        }
    }
    cout<<ret;
    return 0;
}