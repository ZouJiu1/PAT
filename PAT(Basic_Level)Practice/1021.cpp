#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<bits/stdc++.h>


using namespace std;


int main(void){
    string s0, tmp;
    map<string, int> mp{{"0", 0}, {"1", 0}, {"2", 0}, {"3", 0},
                        {"4", 0}, {"5", 0}, {"6", 0}, {"7", 0},
                        {"8", 0}, {"9", 0}};
    cin>>s0;
    for(int i=0; i<s0.size(); i++){
        tmp = s0[i];
        if(s0[i]<='9'&&s0[i]>='0')
            mp[tmp]++;
    }
    for(map<string, int>::iterator x = mp.begin(); x != mp.end(); x++)
        if(x->second!=0)
            cout<<x->first<<":"<<x->second<<endl;
    return 0;
}
