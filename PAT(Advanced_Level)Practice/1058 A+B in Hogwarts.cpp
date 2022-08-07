#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    long long x0, y0, z0, x1, y1, z1;
    scanf("%lld.%lld.%lld %lld.%lld.%lld", &x0, &y0, &z0, &x1, &y1, &z1);
    long long z00, z11, sum;
    z00 = x0 * 17 * 29 + 29 * y0 + z0;
    z11 = x1 * 17 * 29 + 29 * y1 + z1;
    sum = z00 + z11;
    x0 = sum/29;
    x1 = sum%29;
    y0 = x0/17;
    y1 = x0%17;
    z1 = y0;
    printf("%lld.%lld.%lld", z1, y1, x1);
    return 0;
}
