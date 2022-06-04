#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    double R0, P0, R9, P9;
    cin>>R0>>P0>>R9>>P9;
    double A0, B0, res0, res1;
    A0 = R0*R9;
    B0 = P0+P9;
    res0 = A0*cos(B0);
    res1 = A0*sin(B0);
    if(res0+0.005>0&&res0<0)
        printf("0.00");
    else
        printf("%.2f", res0);
    if(res1+0.005>0&&res1<0){
        printf("+0.00i");
    }else{ 
        if(res1<0)
            cout<<"-";
        else
            cout<<"+";
        printf("%.2fi", abs(res1));
    }
    return 0;
}
