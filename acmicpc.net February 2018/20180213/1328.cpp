//20180213 10:24 ~ 
#include <iostream>
using namespace std;

const int MOD = 1000000007;
int n, l, r;

int ldp[101][101];
int rdp[101][101];

int main(){
    cin>>n>>l>>r;
    ldp[0][0] = rdp[0][0] = ldp[1][1] = rdp[1][1] = 1;
    for(int i=2; i<=n; i++){
        for(int j=0; j<i; j++){
            
        }
    }
}