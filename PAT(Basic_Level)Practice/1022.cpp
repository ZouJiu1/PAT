#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int A, B, D, sum, mod, division = 9;
    string s0, tmp;

    cin>>A>>B>>D;
    sum = A + B;
    while(division!=0){
        division = sum/D;
        mod = sum%D;
        tmp = to_string(mod);
        s0.append(tmp);
        sum = division;
    }
    reverse(s0.begin(), s0.end());
    for(int i=0; i<s0.size(); i++)
        cout<<s0[i];
    return 0;
}
