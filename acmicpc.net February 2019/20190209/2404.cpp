#include <iostream>
using namespace std;

int q, p, a, n;
int recur(int restNumerator, long long accumulatedDenominator, int recurNum, int prevDenomiator, int check) {
    if(recurNum > n ) return 0;
    if(restNumerator == 0) return 1;

    int ret = 0, denominator = prevDenomiator;
    // 6000 안넣으면 시간초과 나는데.. 이유를 모르겠네..
    while (restNumerator * denominator < accumulatedDenominator) denominator++;
    while ((n - recurNum) * restNumerator * denominator >= accumulatedDenominator && check*denominator <= a && denominator <= 6000) {
        ret += recur(restNumerator * denominator - accumulatedDenominator, accumulatedDenominator * denominator, recurNum + 1, denominator, check*denominator);
        denominator++;
    }
    return ret;
}

int main() {
    cin>>q>>p>>a>>n;
    cout<<recur(q, p, 0, 1, 1);
    return 0;
}