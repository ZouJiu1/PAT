#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    string s0, s1, s2;
    getline(cin, s0);
    getline(cin, s1);
    for(int i=0; i< s1.size(); i++){
        if(s0.find(toupper(s1[i]))!=string::npos)
            continue;
        if(isupper(s1[i])&&s0.find('+')!=string::npos)
            continue;
        cout<<s1[i];
    }
    cout<<endl;
    return EXIT_SUCCESS;
}
