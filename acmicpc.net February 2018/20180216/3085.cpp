//20180216 18:31 ~ 18:51
#include <iostream>
using namespace std;

int n;
int arr[52][52];
int ret = 1;

void check(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int curr = arr[i][j];
            int tempRet = 0;
            while(curr==arr[i+(++tempRet)][j]){}
            if(tempRet>ret) ret = tempRet;
            tempRet = 0;
            while(curr==arr[i][j+(++tempRet)]){}
            if(tempRet>ret) ret = tempRet;
        }
    }
}

int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            char ch;
            cin>>ch;
            arr[i][j] = ch-'A';
        }
    }
    for(int i=1 ;i<=n; i++){
        for(int j=1; j<=n; j++){
            //swap under candy 
            if(i!=n){
                int temp = arr[i][j];
                arr[i][j] = arr[i+1][j];
                arr[i+1][j] = temp;
                check();
                arr[i+1][j] = arr[i][j];
                arr[i][j] = temp;
            }
            //swap side candy
            if(j!=n){
                int temp = arr[i][j];
                arr[i][j] = arr[i][j+1];
                arr[i][j+1] = temp;
                check();
                arr[i][j+1] = arr[i][j];
                arr[i][j] = temp;
            }
        }
    }
    cout<<ret<<endl;
    return 0;
}