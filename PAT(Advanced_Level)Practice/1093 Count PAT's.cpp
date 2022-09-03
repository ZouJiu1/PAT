#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;



int main(void){
    string s0, s1, s2, s6;
    long long sum=0;
    int count=0;
    vector<long long> vec0, vec1, vec2, vec6;
    cin>>s0;
    if(s0[0]=='P')
        vec1.push_back(1);
    else
        vec1.push_back(0);
    for(int i=1; i<s0.size(); i++){
        if(s0[i]=='P')
            vec1.push_back(vec1[i-1]+1);
        else
            vec1.push_back(vec1[i-1]);
    }
    if(s0[s0.size()-1]=='T')
        vec2.push_back(1);
    else
        vec2.push_back(0);
    
    for(int i=(s0.size()-2); i>=0; i--){
        if(s0[i]=='T')
            vec2.push_back(vec2[count++]+1);
        else
            vec2.push_back(vec2[count++]);
    }
    reverse(vec2.begin(), vec2.end());

    for(int i=0; i<s0.size(); i++){
        if(s0[i]=='A'){
            sum += (long long)vec1[i]*vec2[i];
        }
    }
    sum = sum%1000000007;
    cout<<sum;
    return 0;
}
