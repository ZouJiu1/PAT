#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    string s0, s2, s3;
    int a, c, m;
    cin>>s0;
    for(int i=0; i<10; i++){
        s2 = s0;
        reverse(s0.begin(), s0.end());
        if(s2==s0){
            cout<<s0<<" is a palindromic number.";
            return 0;}
        m = 0;
        for(int j=(s0.size()-1); j>=0; j--){
            a = (s0[j] - '0') + (s2[j] -'0') + m;
            c = a%10;
            m = a/10;
            s3 += to_string(c);
        }
        if(m>0) s3 += to_string(m);
        cout<<s2;
        s2 = s3;
        reverse(s3.begin(), s3.end());
        cout<<" + "<<s0<<" = "<<s3<<endl;
        if(s2==s3){
            cout<<s3<<" is a palindromic number.";
            return 0;}
        s0 = s3;
        s3.erase(s3.begin(), s3.end());}
    cout<<"Not found in 10 iterations.";
    return 0;
}
