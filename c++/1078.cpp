#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    char cr;
    string s0;
    cin>>cr;
    cin.get();
    getline(cin, s0);
    if(cr=='C'){
        string x;
        int count=1;
        s0+=' ';
        for(int i=0; i<s0.size()-1; i++){
            if(s0[i+1]==s0[i]){
                count++;
            }else if(s0[i+1]!=s0[i]){
                if(count!=1)
                    x += to_string(count);
                x += s0[i];
                count = 1;
            }
        }
        cout<<x<<endl;
    }else if(cr=='D'){
        s0 += ' ';
        string tmp;
        for(int i=0; i<s0.size(); i++){
            if(s0[i]>='0'&&s0[i]<='9'){
                tmp += s0[i];
            }else if(tmp.size()>0){
                for(int j = 0; j<stoi(tmp); j++) cout<<s0[i];
                tmp.erase(tmp.begin(), tmp.end());
            }
            else cout<<s0[i];
        }
    }
    return 0;
}
