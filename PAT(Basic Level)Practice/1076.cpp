#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n, i, j;
    string s0, s2;
    vector<string> vec[101];
    cin>>n;
    cin.get();
    for(i=0; i<n; i++){
        getline(cin, s0);
        for(j=0; j<s0.size(); j++){
            if(s0[j]=='T'){
                cout<<s0[j-2] - 'A' +1;
            }
        }
    }
    return 0;
}
