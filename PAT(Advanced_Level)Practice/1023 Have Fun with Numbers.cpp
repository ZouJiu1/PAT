/*
数值的位数大于等于20位，大于long long的取值范围要使用string保存
*/
#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
#include<vector>

using namespace std;

int main(void){
    string s, s0, sk;
    int i, j, f, h;
    cin>>s;
    j = 0;
    reverse(s.begin(), s.end());
    for(int i=0; i<s.size(); i++){
        h = (s[i] - '0') * 2 + j;
        j = h/10;
        f = h%10;
        s0 += to_string(f);
        if(i==(s.size() - 1) && (j > 0)) 
            s0 += to_string(j);
    }
    reverse(s0.begin(), s0.end());
    sk = s0;
    sort(s.begin(), s.end());
    sort(s0.begin(), s0.end());
    if(s==s0) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    cout<<sk;
    return 0;
}
