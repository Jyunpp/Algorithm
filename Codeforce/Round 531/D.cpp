// 20190311 20:40 ~ 21:14
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
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

int n, arr[3];
string s;
int check[300001]; // use from 0

int main() {
    cin>>n;
    cin>>s;
    rep(i, 0, n) {
        char ch = s[i];
        arr[ch-'0']++;
    }
    int num = 0;
    rep(i, 0, 3) {
        num += abs(arr[i] - n/3);
    }
    num/=2;
    if(arr[0]>n/3) {
        int need = arr[0] - n/3;
        for(int i=n-1; i>=0; i--) {
            if(!need) break;
            if(s[i]=='0') {check[i] = 1; need--;}
        }
    }
    if(arr[2]>n/3) {
        int need = arr[2] - n/3;
        for(int i=0; i<=n-1; i++) {
            if(!need) break;
            if(s[i]=='2') {check[i] = 1; need--;}
        }
    }
    rep(i, 0, n) {
        if(arr[0]<n/3) {
            if(check[i]){
                arr[s[i]-'0']--;
                s[i] = '0';
                arr[0]++;
            } else if(s[i] == '1' && arr[1]>n/3) {
                s[i] = '0';
                arr[1]--;
                arr[0]++;
            }
        }else if (arr[1]<n/3) {
            if(check[i]){
                arr[s[i]-'0']--;
                s[i] = '1';
                arr[1]++;
            }
        }
    }
    for(int i=n-1; i>=0; i--) {
        if(arr[2]<n/3) {
            if(check[i]) {
                arr[s[i]-'0']--;
                s[i] = '2';
                arr[2]++;
            } else if(s[i]=='1' && arr[1]>n/3) {
                s[i] = '2';
                arr[1]--;
                arr[2]++;
            }
        }
    }
    cout<<s<<endl;
    return 0;
}