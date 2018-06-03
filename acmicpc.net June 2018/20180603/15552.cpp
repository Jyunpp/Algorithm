#define sd(x) scanf(" %d", &x);
#include <stdio.h>
#include <iostream>
int n;
int main() {
    sd(n);
    for(int i=1, a, b; i<=n; i++){
        sd(a); sd(b);
        printf("%d\n", a+b);
    }
    return 0;
}