//20180213 10:24 ~ 
//20180215 23:29 ~ 01:02
#include <iostream>
using namespace std;

typedef long long ll;
const int MOD = 1000000007;
ll n, l, r;

ll dp[101][101][101]; //dp[n][l][r];

int main(){
    cin>>n>>l>>r;
    dp[1][1][1] = 1;
    dp[2][1][2] = dp[2][2][1] = 1;
    for(int i=3; i<=n; i++){
        for(int j=1; j<=i; j++){
            for(int k=1; k<=i; k++){
                //dp[i][j][k] += (dp[i-1][j-1][k] + dp[i-1][j][k-1] + dp[i-1][j][k]);
                dp[i][j][k] = (dp[i][j][k] + dp[i-1][j-1][k])%MOD;
                dp[i][j][k] = (dp[i][j][k] + dp[i-1][j][k-1])%MOD;
                dp[i][j][k] = (dp[i][j][k] + dp[i-1][j][k]*(i-2))%MOD;
            }
        }
    }
    cout<<dp[n][l][r]<<endl;
    return 0;
}