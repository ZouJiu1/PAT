#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    string s;
    int x, j;
    cin>>s;
    if(s.size()==3){
        x = s[0] - '0';
        for(j=0; j<x; j++)
            cout<<"B";
        x = s[1] - '0';
        for(j=0; j<x; j++)
            cout<<"S";
        x = s[2] - '0';
        for(j=0; j<x; j++)
            cout<<j+1;
    }
    if(s.size()==2){
        x = s[0] - '0';
        for(j=0; j<x; j++)
            cout<<"S";
        x = s[1] - '0';
        for(j=0; j<x; j++)
            cout<<j+1;
    }
    if(s.size()==1){
        x = s[0] - '0';
        for(j=0; j<x; j++)
            cout<<j+1;
    }
    return 0;
}
