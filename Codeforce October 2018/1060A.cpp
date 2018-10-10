// 20181010 23:23 ~ 23:30
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

int n;
int arr[10];

int main() {
    cin>>n;
    for(int i=1; i<=n; i++){
        char c;
        cin>>c;
        arr[c-'0']++;
    }
    int ans = 0;
    while(arr[8]){
        arr[8]--;
        ans += (n>=11);
        n-=11;
    }
    cout<<ans<<endl;
}