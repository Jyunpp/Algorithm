#include <iostream>
using namespace std;

int curr, ret;
int distance(int curr){
    int ret = 100-curr;
    if(ret<0) ret *=-1;
    return ret;
}

int main(){
    cin>>curr;
    ret = curr;
    for(int i=2; i<=10; i++){
        cin>>curr;
        if(distance(ret+curr)<=distance(ret)) ret += curr;
        else break;
    }
    cout<<ret<<endl;
    return 0;
}