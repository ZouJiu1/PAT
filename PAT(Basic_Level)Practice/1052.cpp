#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<bits/stdc++.h>

using namespace std;

vector<string> dealwith(string s0){
    vector<string> vec;
    string tmp, s2{"0"};
    int pre=-6, count=1;
    vec.push_back(s0);
    for(int i=1; i<s0.size(); i++){
        if(s0[i-1]=='['){
            tmp += s0[i];
            pre = 6;
        }else if(s0[i]==']'&&pre>0){
            pre = -6;
            vec.push_back(tmp);
            tmp.erase(tmp.begin(), tmp.end());
        }else if(pre>0)
            tmp += s0[i];
    }
    return vec;
}

int main(void){
    string s0, s1, s2;
    vector<string> s3, s6, s9;
    getline(cin, s0);
    getline(cin, s1);
    getline(cin, s2);
    s3 = dealwith(s0);
    s6 = dealwith(s1);
    s9 = dealwith(s2);
    const int l0= s3.size(), l1=s6.size(), l2=s9.size();
    int n, i0, i1, i2, i3, i4;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>i0>>i1>>i2>>i3>>i4;
        if(i0<=0||i1<=0||i2<=0||i3<=0||i4<=0||
           i0>=l0||i1>=l1||i2>=l2||
           i3>=l1||i4>=l0){
            cout<<"Are you kidding me? @\\/@"<<endl;
            continue;
        }
        cout<<s3[i0]<<"("<<s6[i1]<<s9[i2]<<s6[i3]<<")"<<s3[i4]<<endl;
    }
    return 0;
}
