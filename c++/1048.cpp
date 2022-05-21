#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    string s0, s1, s2, res;
    cin>>s0>>s1;
    int j, a, b, rem;
    reverse(s0.begin(), s0.end());
    reverse(s1.begin(), s1.end());
    if(s0.size()>s1.size())
        s1.append(s0.size()-s1.size(), '0');
    else
        s0.append(s1.size()-s0.size(), '0');
    
    char str[14] = {"0123456789JQK"};
    for(int i = 0; i<s0.size(); i++){
        j = i+1;
        a = s0[i] - '0';
        b = s1[i] - '0';
        // s0.erase(s0.begin());
        // s1.erase(s1.begin());
        if(j%2 == 1 ){
            rem = (a+b)%13;
            if(rem==10)
                res.push_back('J');
            else if(rem==11)
                res.push_back('Q');
            else if(rem==12)
                res.push_back('K');
            else{
                res += str[rem];
                // s2 = to_string(rem);
                // res.push_back(s2[0]);
            }
        }
        else{
            rem = b-a;
            rem = rem>=0?rem:(rem+10);
            // s2 = to_string(rem);
            // res.push_back(s2[0]);
            res += str[rem];
        }
    }
    reverse(res.begin(), res.end());
    int marked = -6;
    for(int i=0;i<res.size();i++){
        cout<<res[i];
    }
    return 0;
}
