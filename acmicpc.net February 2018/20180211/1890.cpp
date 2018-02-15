//20180211 21:32 ~ 22:15
#include <iostream>
#define xx first;
#define yy second;
using namespace std;

int n;
int arr[101][101];
long long dp[101][101];

long long solve(int y, int x){
    if(x==1&&y==1) return 1;
    long long &ret = dp[y][x];
    if(ret != -1) return ret;
    ret = 0;
    for(int i=1; i<=9 && y-i>0; i++){
        if(arr[y-i][x] == i) ret += solve(y-i, x);
    }
    for(int i=1; i<=9 && x-i>0; i++){
        if(arr[y][x-i] == i) ret += solve(y, x-i);
    }
    return ret;
}

int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>arr[j][i];
            dp[j][i] = -1;
        }
    }
    cout<<solve(n, n);
    return 0;
}
