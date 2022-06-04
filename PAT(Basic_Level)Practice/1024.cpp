#include<iostream>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    string s0, tmp;
    int n, m=1, index0, index3, index1, index6, length, marks = -10;
    cin>>s0;
    if(s0[0]=='-')
        cout<<s0[0];
    index0 = s0.find("E-");
    index3 = s0.find("E+");
    index1 = s0.find("E");
    index6 = s0.find(".");
    length = index1 - index6 - 1;
    if(index0>0){
        tmp = s0.substr(index0+2, s0.size() - index0 - 2);
        n = atoi(tmp.c_str());
        if(n!=0)
            cout<<"0.";
        for(int j=0; j< n - 1; j++)
            cout<<"0";
        for(int i=1; i<index0; i++){
            if(s0[i]=='.'&&n!=0)
                continue;
            cout<<s0[i];
        }
    }
    else if(index3){
        tmp = s0.substr(index3+2, s0.size() - index3 - 2);
        n = atoi(tmp.c_str());
        for(int i=1; i<index3; i++){
            if(s0[i]=='.'){
                marks = 0;
                continue;
            }
            if(marks>=0){
                tmp = s0.substr(i, length--);
                m = atoi(tmp.c_str());
            }
            if(m==0&&marks<n)
                break;
            if(marks==n)
                cout<<".";
            if(marks>=0)
                marks++;
            cout<<s0[i];
        }
        for(int j=0; j< n - marks; j++)
            cout<<"0";
    }
    cout<<endl;
    return 0;
}
