#include<iostream>
#include<algorithm>
#include<cstdlib>
// #include<bits/stdc++.h>

using namespace std;

int main(void){
    string s;
    cin>>s;
    int sum = 0;
    string ss[10]={"ling","yi", "er", "san", "si", "wu", "liu","qi","ba","jiu"};
    for(int i=0; i<s.length(); i++){
        sum += s[i] - '0';
    }
    string tmp = to_string(sum);
    for(unsigned int i=0; i<tmp.length()-1; i++){
        cout<<ss[tmp[i]-'0']<<" ";
    }
    cout<<ss[tmp[tmp.size()-1]-'0'];
    return 0;
}
