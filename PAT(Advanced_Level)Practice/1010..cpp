#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    map<char, int> mp;
    int a, b, i, j, k, sum, sum0, sum2;
    for(char i = '0'; i<='9'; i++) mp[i] = i - '0';
    for(char i = 'a'; i <= 'z'; i++) mp[i] = i - 'a' + 10;
    string s, s0, s2, s6, s9, s3;
    cin>>s>>s2>>a>>s0;
    sum0 = sum = 0;
    reverse(s0.begin(), s0.end());
    for(i = 0; i < s0.size(); i++) sum0 += mp[s0[i]] * pow(10, i);
    if(a==1){
        reverse(s.begin(), s.end());
        for(i = 0; i < s.size(); i++) sum += mp[s[i]] * pow(sum0, i);
        reverse(s2.begin(), s2.end());
        for(i = 1; i < 1000000; i++){
            sum2 = 0;
            k = 666;
            for(j = 0; j < s2.size(); j++) {
                if(mp[tolower(s2[j])]>=i) {k=-666; break;}
                sum2 += mp[tolower(s2[j])] * pow(i, j);
            }
            if(k<0) continue;
            if(sum2==sum){
                cout<<i;
                return 0;
            }
        }
        cout<<"Impossible";
        return 0;
    }else{
        reverse(s2.begin(), s2.end());
        for(i = 0; i < s2.size(); i++) sum += mp[s2[i]] * pow(sum0, i);
        reverse(s.begin(), s.end());
        for(i = 1; i < 1000000; i++){
            sum2 = 0;
            k = 666;
            for(j = 0; j < s.size(); j++){ 
                if(mp[tolower(s[j])]>=i) {k=-666; break;}
                sum2 += mp[tolower(s[j])] * pow(i, j);
            }
            if(k<0) continue;
            if(sum2==sum){
                cout<<i;
                return 0;
            }
        }
        cout<<"Impossible";
        return 0;
    }
    return 0;
}
