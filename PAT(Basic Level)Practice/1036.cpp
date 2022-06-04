#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    char cr;
    int n, halfnum;
    cin>>n>>cr;
    halfnum = round((float)(n/2.0));
    for(int j=0; j<n; j++)
        cout<<cr;
    cout<<endl;
    for(int j=0; j<halfnum-2; j++){
        cout<<cr;
        for(int i=0; i<n-2; i++)
            cout<<" ";
        cout<<cr;
        cout<<endl;
    }
    for(int j=0; j<n; j++)
        cout<<cr;
    return 0;
}
