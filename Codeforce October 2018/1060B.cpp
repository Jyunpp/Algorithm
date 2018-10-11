// 20181011 23:05 ~ 
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

ll n;
int ans;

int main() {
    cin>>n;
    ll num = 1;
    while(n/(num*10)) num*=10;
    while(num){
        int curr = (n/num)%10;
        ans += curr;
        if(num>=10){
            ans -=1;
            ans +=10;
        }
        num/=10;
    }
    for(ll i=1; i<=n; i*=10){
        if((n/i)%10==9 && (n/(i*10) !=0 )){
            ans -=9;
        }
        else{
            break;
        }
    }
    cout<<ans<<endl;
}