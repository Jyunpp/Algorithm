//20180307 23:37 ~ 23:47

#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int T, n, ret;
string s;

int main(){
    cin>>T;
    for(int i=1; i<=T; i++){
        ret = 0;
        cin>>s>>n;
        int len = s.length();
        for(int j=0; j+n<=len; j++){
            if(s[j]=='-'){
                ret++;
                for(int k=0; k<n; k++) { s[j+k]=='-'?s[j+k]='+':s[j+k]='-'; }
            }
        }
        bool pos = true;
        for(int j=len-n; j<=len-1; j++){
            if(s[j]=='-') pos = false;
        }
        cout<<"Case #"<<i<<": ";
        if(pos) cout<<ret;
        else cout<<"IMPOSSIBLE";
        if(i!=T)cout<<endl;
    }
    return 0;
}
