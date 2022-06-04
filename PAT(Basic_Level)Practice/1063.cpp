#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n, num0, num1;
    double max = -666666, dl0;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>num0>>num1;
        dl0 = sqrt(num0*num0+num1*num1);
        if(dl0>max) max=dl0;
    }
    printf("%.2f", max);
    return 0;
}
