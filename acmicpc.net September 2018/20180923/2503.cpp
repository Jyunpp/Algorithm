// 20180923 22:03 ~ 22:15
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

int n,ans;
int arr[101][4];

int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>arr[i][1]>>arr[i][2]>>arr[i][3];
    }
    for(int i=1; i<=9; i++){
        for(int j=1; j<=9; j++){
            if(j==i) continue;
            for(int k=1; k<=9; k++){
                if(k==i||k==j) continue;
                int canAns = 1;
                for(int l=1; l<=n; l++){
                    int s = 0;
                    int b = 0;
                    int curr = arr[l][1];
                    int q = curr/100, w = (curr%100)/10, e= curr%10;
                    s = (q==i) + (w==j) + (e==k);
                    b = (q==j||q==k) + (w==i||w==k) + (e==i||e==j);
                    if(arr[l][2] !=s || arr[l][3]!=b) {
                        canAns = 0;
                        break;
                    }
                }
                ans += canAns;
            }
        }
    }
    cout<<ans<<endl;
}