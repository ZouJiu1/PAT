#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

#define min(a, b) (a<b? a:b)

long long gcd(long long a, long long b){
    long long i = b;
    while(a%b){
        i = a%b;
        a = b;
        b = i;
    }
    return i;
}

void getstring(long long i2, long long i3, char *x0){
    if(i3==0){
        sprintf(x0, "Inf");
        return;
    }
    long long bei = gcd(abs(i2), abs(i3));
    if(bei!=0){
        i2 = i2/bei;
        i3 = i3/bei;
    }
    long long i = i2/i3;
    long long rem0;
    if(abs(i)>0){
        rem0 = abs(i2%i3);
        if(i>0&&rem0!=0)
            sprintf(x0, "%lld %lld/%lld", i, rem0, i3);
        else if(i<0&&rem0!=0)
            sprintf(x0, "(%lld %lld/%lld)", i, rem0, i3);
        else if(i>0&&rem0==0)
            sprintf(x0, "%lld", i);
        else if(i<0&&rem0==0)
            sprintf(x0, "(%lld)", i);
    }else{
        rem0 = i2%i3;
        if(rem0>0)
            sprintf(x0, "%lld/%lld", i2, i3);
        else if(rem0<0)
            sprintf(x0, "(%lld/%lld)", i2, i3);
        else
            sprintf(x0, "0");
    }
}

int main(void){
    string s0, s1;
    long long i2, i3, i6, i9;
    long long i, j, add, div, sub, mpy, rem0, rem1;
    cin>>s0>>s1;
    i = s0.find('/');
    i2 = atoi(s0.substr(0, i).c_str());
    i3 = atoi(s0.substr(i+1, s0.length() - 1 - i).c_str());
    i = s1.find('/');
    i6 = atoi(s1.substr(0, i).c_str());
    i9 = atoi(s1.substr(i+1, s1.length() - 1 - i).c_str());
    
    char x0[300], x1[300], x2[300], x3[300], xz[300], xw[300];
    getstring(i2, i3, x0);
    getstring(i6, i9, x1);
    i = i2*i9+i3*i6;
    j = i3*i9;
    getstring(i, j, x2);
    i = i2*i9 - i3*i6;
    getstring(i, j, x3);
    i = i2*i6;
    j = i3*i9;
    getstring(i, j, xz);
    if(i6<0){
        i9 = -i9;
        i6 = -i6;
    }
    i = i2*i9;
    j = i3*i6;
    getstring(i, j, xw);

    printf("%s + %s = %s\n", x0, x1, x2);
    printf("%s - %s = %s\n", x0, x1, x3);
    printf("%s * %s = %s\n", x0, x1, xz);
    printf("%s / %s = %s\n", x0, x1, xw);
    return 0;
}
