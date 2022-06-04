#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n, m, num;
    string s0, s1;
    cin>>s0>>n;
    m = 0;
    vector<string> vec;
    cin.get();
    while(1){
        getline(cin, s1);
        if(s1.size()==1&&s1[0]=='#')
            break;
        vec.push_back(s1);
    }
    for(int i=0; i<vec.size(); i++){
        s1 = vec[i];
        if(s0==s1&&m<n){
            cout<<"Welcome in";
            return 0;
        }
        if(s0!=s1){
            cout<<"Wrong password: "<<s1<<endl;
            m++;
        }
        if(m==n){
            cout<<"Account locked";
            return 0;
        }
        num++;
    }
    return 0;
}
