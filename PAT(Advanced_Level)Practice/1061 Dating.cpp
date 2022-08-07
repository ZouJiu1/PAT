#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int i, j, m, n, x, y;
    string s0, s00, s000, s0000;
    cin>>s0>>s00>>s000>>s0000;
    x = min(s0.length(), s00.length());
    string wee[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    map<char, int> mp;
    for(i=0; i<24; i++){
        if(i<10) mp[i + '0'] = i;
        else mp[i - 10 + 'A'] = i;
    }
    y = 0;
    for(i=0; i<x; i++){
        if(s0[i]==s00[i]&&(s0[i]>='A'&&s0[i]<='G')&&y==0){
            cout<<wee[tolower(s0[i]) - 'a']<<" ";
            y++;
            continue;
        }
        if(s0[i]==s00[i]&&((s0[i]>='0'&&s0[i]<='9')||(s0[i]>='A'&&s0[i]<='N'))&&y==1){
            printf("%02d:", mp[s0[i]]);
            break;
        }
    }
    x = min(s000.length(), s0000.length());
    for(i=0; i<x; i++){
        if(s000[i]==s0000[i]&&((s000[i]>='A'&&s000[i]<='Z')||(s000[i]>='a'&&s000[i]<='z'))){
            printf("%02d", i);
            break;
        }
    }
    return 0;
}
