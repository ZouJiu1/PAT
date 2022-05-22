#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<bits/stdc++.h>

using namespace std;

vector<int> tobinary(int a){
    vector<int> vec;
    int chu=1, mod=0;
    while(chu){
        chu = a/2;
        mod = a%2;
        a = chu;
        vec.push_back(mod);
    }
    reverse(vec.begin(), vec.end());
    return vec;
}

int main(void){
    string s0;
    getline(cin, s0);
    vector<int> vec, vec0;
    int zero=0, one=0, sum=0;
    for(int i=0; i<s0.size(); i++){
        if(tolower(s0[i])<='z'&&tolower(s0[i])>='a'){
            sum += tolower(s0[i]) - 'a' + 1;
        }
    }
    if(sum==0){
        cout<<"0 0";
        return 0;
    }
    vec0 = tobinary(sum);
    for(int i=0; i<vec0.size(); i++){
        if(vec0[i]==0) zero++;
        else one++;
    }
    cout<<zero<<" "<<one<<endl;
    return 0;
}
