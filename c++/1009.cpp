#include<vector>
#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    vector<string> vec;
    string s;
    while(cin>>s){
        vec.push_back(s);
        if(cin.get()=='\n')
            break;
    }
    reverse(vec.begin(), vec.end());
    for(unsigned int i=0; i<vec.size(); i++){
        cout<<vec[i];
        if(i!=vec.size()-1){cout<<" ";}
    }
    return 0;
}
