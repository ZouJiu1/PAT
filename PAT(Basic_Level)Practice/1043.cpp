#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    string s0, s1;
    getline(cin, s0);
    map<char, int> mp{{'P', 0}, {'A', 0}, {'T', 0},
                      {'e', 0}, {'s', 0}, {'t', 0}};
    for(int i=0; i<s0.size(); i++){
        if(s0[i]=='P'||s0[i]=='A'||s0[i]=='T'||
           s0[i]=='e'||s0[i]=='s'||s0[i]=='t')
           mp[s0[i]] += 1;
    }
    s1 = {"PATest"};
    bool TE = true;
    while(mp['P']||mp['A']||mp['T']||
          mp['e']||mp['s']||mp['t']){
        for(int i=0; i<s1.size(); i++){
            if(mp[s1[i]]!=0){
                cout<<s1[i];
                mp[s1[i]]--;
            }
        }
    }
    return 0;
}
