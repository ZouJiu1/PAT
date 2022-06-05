#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    char cr;
    string s0, num;
    cin>>cr;
    int kk, cnt=1;
    cin.get();
    getline(cin, s0);
    if(cr=='D'){
        string tmp;
        kk = 1;
        for (int i = 0; i < s0.length(); i++) {
            if (s0[i] >= '0' && s0[i] <= '9') {
                num += s0[i];
            } else {
                if (num.length() > 0) cnt = stoi(num);
                while(cnt--) cout << s0[i];
                cnt = 1;
                num = "";
            }
        }
    }else if(s0.length()!=0){
        string x;
        int count=1;
        char pre = s0[0];
        for(int i=1; i<s0.size(); i++){
            if(pre==s0[i]){
                count++;
            }else{
                if(count>=2) cout<<count;
                cout<<pre;
                pre = s0[i];
                count = 1;
            }
        }
        if(count>=2) cout<<count;
        cout<<pre;
    }
    return 0;
}
