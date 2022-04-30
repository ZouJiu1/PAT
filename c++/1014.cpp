#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    string s0, s1, s2, s3, tmp;
    cin>>s0;
    cin>>s1;
    cin>>s2;
    cin>>s3;
    map<string, string> mp{{"A", "MON"}, {"B", "TUE"}, {"C", "WED"}, 
                           {"D", "THU"}, {"E", "FRI"}, {"F", "SAT"}, 
                           {"G", "SUN"}};
    int l1, l2, count, hour, minute;
    l1 = min(s0.size(), s1.size());
    l2 = min(s2.size(), s3.size());
    count = 0;
    for(int i=0; i<l1; i++){
        if(s0[i] == s1[i]&&(s0[i]>='A')&&(s0[i]<='G')&&count==0){
            tmp = s0[i];
            tmp = mp[tmp];
            count = 1;
            continue;
        }
        if(s0[i] == s1[i]&&(s0[i]>='0')&&(s0[i]<='9')&&count==1){
            hour = s0[i] - '0';
            break;
        }
        if(s0[i] == s1[i]&&(s0[i]>='A')&&(s0[i]<='N')&&count==1){
            hour = s0[i] - '0' - 7;
            break;
        }
    }
    for(int i=0; i<l2; i++){
        if(s2[i] == s3[i]&&(((s2[i]>='A')&&(s2[i]<='Z'))||((s2[i]>='a')&&(s2[i]<='z')))&&count==1){
            minute = i;
            break;
        }
    }
    cout<<tmp<<" ";
    printf("%02d:", hour);
    printf("%02d", minute);
    return 0;
}
