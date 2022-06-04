#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    string s0;
    char x;
    map<char, int> mp;
    for(int i='a'; i<='z'; i++)
        mp[char(i)] = 0;
    getline(cin, s0);
    for(int i=0; i<s0.size(); i++){
        x = tolower(s0[i]);
        if(x<='z'&&x>='a')
            mp[x] += 1;
    }
    int max = -666;
    char tmp;
    for(int i='a'; i<='z'; i++){
        if(mp[char(i)]>max){
            tmp = char(i);
            max = mp[tmp];
        }
    }
    cout<<tmp<<" "<<max;
    return 0;
}
