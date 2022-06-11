#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    string s0, s2;
    long long a=0, c=0;
    cin>>s0;
    for(int i=0; i<s0.length(); i++) a += s0[i] - '0';
    s2 = to_string(a);
    map<char, string> mp{{'0', "zero"},{'1', "one"},{'2', "two"},
    {'3', "three"},{'4', "four"},{'5', "five"},{'6', "six"},
    {'7', "seven"},{'8', "eight"},{'9', "nine"}};
    for(int i = 0; i < s2.length(); i++){
        cout<<mp[s2[i]];
        if(i!=(s2.length()-1)) cout<<" ";
    }
    return 0;
}

