#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    string s, s0, sub, sk;
    int i, j, k, m, n;
    getline(cin, s);
    s0 = s;
    int max = -999;
    for(i = 0; i < s.length(); i++){
        for(j = s.length() - i; j >=0; j--){
            sub = s.substr(i, j);
            sk = sub;
            reverse(sub.begin(), sub.end());
            k = sk.size();
            if(sub==sk)
                if (k > max)
                    max = k;
        }
    }
    cout<<max;
    return 0;
}
