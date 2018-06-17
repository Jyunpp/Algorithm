#include <iostream>
using namespace std;

int n, x, y;
int arr[101][101];
int ret;

int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>x>>y;
        for(int j=x; j<x+10; j++){
            for(int k=y; k<y+10; k++){
                arr[j][k] = 1;
            }
        }
    }
    ret = 0;
    for(int i=1; i<=100; i++){
        for (int j=1; j<=100; j++){
            if(arr[i][j]) ret++;
        }
    }
    cout<<ret<<endl;
    return 0;
}