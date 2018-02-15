//20180213 10:08 ~ 10:15
#include <iostream>
using namespace std;

int dp[10];

int main(){
    int a, b, c;
    cin>>a>>b>>c;
    int ret = a*b*c;
    for(int i=0; i<=9; i++) dp[i] = 0;
    while(ret){
        int curr = ret%10;
        dp[curr]++;
        ret/=10;
    }
    for(int i=0; i<=9; i++){
        cout<<dp[i]<<endl;
    }
    return 0;
}