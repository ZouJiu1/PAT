#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int a, b, c;
    string s0, s9;
    cin>>a>>b;
    c = a + b;
    s0 = to_string(c);
    reverse(s0.begin(), s0.end());
    for(int i=0; i<s0.size(); i++){
        s9 += s0[i];
        if(c<0&&i==(s0.size()-2)) continue;
        if(i!=(s0.size()-1)&&s0[i]!='-'&&(i+1)%3==0){
            s9 += ',';
        }
    }
    reverse(s9.begin(), s9.end());
    cout<<s9;
    return 0;
}
