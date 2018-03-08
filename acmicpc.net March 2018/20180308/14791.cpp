//20180308 12:19 ~ 12:30
//20180308 13:19 ~ 13:23
#include <iostream>
#include <string>
using namespace std;

int T;
string s;

int main(){
    cin>>T;
    for(int i=1; i<=T; i++){
        cin>>s;
        int len = s.length();
        char last = s[0];
        for(int j=1; j<len; j++){
            char curr = s[j];
            if(last>curr){
                s[j-1] = last-1;
                for(int k=j; k<len; k++) s[k] = '9';
                for(int k=j-1;k>0; k--){
                    if(s[k-1]>s[k]){s[k-1]--; s[k]='9';}
                }
                break;
            }
            last = curr;
        }
        if(s[0]=='0') s = s.substr(1, len);
        cout<<"Case #"<<i<<": "<<s;
        if(i!=T)cout<<endl;
    }
    return 0;
}