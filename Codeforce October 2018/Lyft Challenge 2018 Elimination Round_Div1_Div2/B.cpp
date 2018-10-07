// 20181008 02:20 ~ 02:56
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
#define pb push_back
#define xx first
#define yy second

typedef long long ll;
typedef pair<int, int> P;

int t;
unsigned long long a, b;

bool solve(ll a){
    if(a%2==0) return false;
    for(int i=3; i<=sqrt(a); i+=2){
        if(a%i==0) {
            return false;
        }
    }
    return true;
}

int main() {
    cin>>t;
    for(int i=1; i<=t; i++){
        cin>>a>>b;
        if(a==b+1) {
            if(solve(a+b))cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else cout<<"NO"<<endl;
    }
}