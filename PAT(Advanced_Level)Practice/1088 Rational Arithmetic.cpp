#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<cmath>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long c) {
    long long i = c;
    while(a%c!=0) {
        i = a%c;
        a = c;
        c = i;
    }
    return abs(c);
}

string simplest(long long num0, long long den0) {
    if((den0<0&&num0>0)||(den0<0&&num0<0)) {
        num0 = -num0;
        den0 = -den0;
    }
    long long k0, rem0;
    if(num0==0) return "0";
    k0 = num0/den0;
    num0 = num0%den0;
    rem0 = gcd(num0, den0);
    num0 = num0/rem0;
    den0 = den0/rem0;
    string s0;
    if(num0 < 0||k0<0) s0 += "(";
    if(k0!=0) 
        s0 += to_string(k0);
    if(k0<0&&num0<0) num0 = -num0;
    if(num0==0){
        if(num0 < 0||k0<0) s0 += ")";
        return s0;
    }
    if(den0==1) s0 += to_string(num0);
    else {
        if(k0!=0) s0 += " ";
        s0 += to_string(num0)+"/"+to_string(den0);
    }
    if(num0 < 0||k0<0) s0 += ")";
    return s0;
}

int main(void) {
    int i, j, k, mm, n, w, x, y, des;
    string s1, s0, ss, sss;
    long long num0, num1, den0, den1, k0, k1, rem0, rem1;
    scanf("%lld/%lld", &num0, &den0);
    scanf("%lld/%lld", &num1, &den1);
    s0 = simplest(num0, den0);
    s1 = simplest(num1, den1);
    k0 = gcd(num0, den0);
    k1 = gcd(num1, den1);
    num0 = num0/k0;
    den0 = den0/k0;
    num1 = num1/k1;
    den1 = den1/k1;

    rem0 = num0 * den1 + num1 * den0;
    rem1 = den1 * den0;
    ss = simplest(rem0, rem1);
    cout<<s0<<" + "<<s1<<" = "<<ss<<endl;

    rem0 = num0 * den1 - num1 * den0;
    rem1 = den1 * den0;
    ss = simplest(rem0, rem1);
    cout<<s0<<" - "<<s1<<" = "<<ss<<endl;

    rem0 = num0 * num1;
    rem1 = den1 * den0;
    ss = simplest(rem0, rem1);
    cout<<s0<<" * "<<s1<<" = "<<ss<<endl;

    if(num0==0||num1==0){
        cout<<s0<<" / "<<s1<<" = Inf"<<endl;
    }
    else{
        rem0 = num0 * den1;
        rem1 = num1 * den0;
        ss = simplest(rem0, rem1);
        cout<<s0<<" / "<<s1<<" = "<<ss<<endl;
    }
    return 0;
}
