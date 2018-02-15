//20180213 10:02 ~ 10:07
#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    char ret = 'F';
    if(n>=90) ret = 'A';
    else if(n>=80) ret = 'B';
    else if(n>=70) ret = 'C';
    else if(n>=60) ret = 'D';
    cout<< ret<<endl;
    return 0;
}