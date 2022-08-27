#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b){
    long long i = b;
    while(a%b){
        i = a%b;
        a = b;
        b = i;
    }
    return i;
}
struct nod{
    signed long long numerator;
    unsigned long long denominator;
};
int main(void){
    int i, j, m, n, k, w, q;
    long long xx, sum = 0;
    cin>>n;
    nod nd;
    unsigned long long xy, mul = 1;
    vector<nod> vec;
    bool status[1006];
    memset((void *)status, true, sizeof(bool)*1006);
    for(i = 0; i < n; i++){
        scanf("%lld/%lld", &nd.numerator, &nd.denominator);
        for(j = 2; j < 1006; j++){
            if (nd.denominator%j!=0)
                status[j] = false;
        }
        mul = mul * nd.denominator; 
        vec.push_back(nd);
    }
    for(j = 2; j < 1006; j++){
        if(status[j]==true){
            if(mul%j==0)
                mul = mul/j;
        }
    }

    for(i = 0; i < n; i++){
        if(vec[i].denominator==0)
            continue;
        sum += (mul/vec[i].denominator) * vec[i].numerator;
    }
    if(sum==0){
        cout<<0;
        return 0;
    }
    if(sum%mul==0){
        cout<<sum/mul;
    }
    else if(sum > mul){
        xx = sum%mul;
        xy = gcd(xx, mul);
        cout<<sum/mul<<" "<<(sum%mul)/xy<<"/"<<mul/xy;
    }else{
        xy = gcd(sum, mul);
        cout<<sum/xy<<"/"<<mul/xy;
    }
    return 0;
}
