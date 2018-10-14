// 20181014 19:05 ~ 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>
#include <map>
using namespace std;

#define sd(x) scanf(" %d", &x);
#define pb push_back
#define xx first
#define yy second

typedef long long ll;
typedef pair<int, int> P;

int arr[3];

int main() {
    cin>>arr[0]>>arr[1]>>arr[2];
    sort(arr, arr+3);
    if(arr[0]+arr[1] > arr[2]) cout<<0<<endl;
    else cout<<arr[2] - (arr[0]+arr[1]) + 1<<endl;
    return 0;
}