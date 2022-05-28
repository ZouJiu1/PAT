#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    int i = b;
    while(a%b){
        i = a%b;
        a = b;
        b = i;
    }
    return i;
}

int main(void){
    int n, m, num0, num1, num2, num3;
    string s0, s1, s2;
    double dl0, dl1, dl2;
    vector<string> vec;
    cin>>s0>>s1>>n;
    m = s0.find('/');
    s2 = s0.substr(0, m);
    num0 = stoi(s2);
    s2 = s0.substr(m+1, s0.size());
    num1 = stoi(s2);
    m = s1.find('/');
    s2 = s1.substr(0, m);
    num2 = stoi(s2);
    s2 = s1.substr(m+1, s1.size());
    num3 = stoi(s2);
    dl0 = num0/(double)num1;
    dl1 = num2/(double)num3;
    if(dl0>dl1){
        dl0 = dl1 + dl0;
        dl1 = dl0 - dl1;
        dl0 = dl0 - dl1;
    }
    for(int i=1; i<n; i++){
        dl2 = i/(double)n;
        s0.erase(s0.begin(), s0.end());
        if(dl2>dl0&&dl2<dl1){
            m = gcd(i, n);
            if(m!=1){
                continue;
            }else{
                s0 += to_string(i);
                s0 += '/';
                s0 += to_string(n);
                vec.push_back(s0);
            }
        }
    }
    for(int i=0; i<vec.size(); i++){
        cout<<vec[i];
        if(i!=(vec.size()-1))
            cout<<" ";
    }
    return 0;
}
