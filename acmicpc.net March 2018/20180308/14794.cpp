//20180308 20:49 ~ 22:35
//need to use long long !!!!!!!!!!!!!
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int T;

void solve(long long a, long long b){
    long long remain, occupied, power, n, base;
    bool extra;
    remain = a;
    occupied = 0;
    power = 0;
    n = b;
    // loop (int)log2(b) times
    while(n/=2){
        occupied += pow(2, power);
        remain = a - occupied;
        power++;
    }
    base = remain / (long long)pow(2, power);
    extra = (remain - base * (long long)pow(2, power) >= b - occupied );
    if(extra){
        if((base+extra)%2) cout<<base/2<<" "<<base/2;
        else cout<<base/2+1<<" "<<base/2;
    }
    else {
        if(base%2) cout<<base/2<<" "<<base/2;
        else cout<<base/2<<" "<<base/2 - 1;
    }
}
int main(){
    cin>>T;
    for(int i=1; i<=T; i++){
        long long a, b;
        cin>>a>>b;
        cout<<"Case #"<<i<<": ";
        solve(a, b);
        if(i!=T)cout<<endl;
    }
    return 0;
}