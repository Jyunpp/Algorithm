// 20181012 23:35 ~ 23:44
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

typedef long long ll;
typedef pair<int, int> P;

int t;
int L, v, l, r;

int main() {
    cin>>t;
    for(int T=1; T<=t; T++){
        cin>>L>>v>>l>>r;
        int ans = 0;
        int templ = (l/v)*v;
        if(templ==l) templ--;
        ans += templ/v;
        int tempr = (1 + (r/v))*v;
        if(tempr==r) tempr++;
        int last = (L/v)*v;
        if(last>=tempr) {
            ans +=(1 + (last-tempr)/v);
        }
        cout<<ans<<endl;
    }
}