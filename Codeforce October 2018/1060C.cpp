// 20181012 20:05 ~ 
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

int n, m, x;
int a[2001], b[2001];
int psA[2001], psB[2001];
ll minA[2001], minB[2001];
int ans = 0;

int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++) cin>>a[i], psA[i] = psA[i-1] + a[i], minA[i] = 9876543210;
    for(int i=1; i<=m; i++) cin>>b[i], psB[i] = psB[i-1] + b[i], minB[i] = 9876543210;
    cin>>x;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n+1-i; j++){
            if(minA[i] > psA[j+i-1] - psA[j-1]) minA[i] = psA[j+i-1] - psA[j-1];
        }
    }
    for(int i=1; i<=m; i++){
        for(int j=1; j<=m+1-i; j++){
            if(minB[i] > psB[j+i-1] - psB[j-1]) minB[i] = psB[j+i-1] - psB[j-1];
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(minA[i]*minB[j] <= x){
                ans = max(ans, i*j);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}