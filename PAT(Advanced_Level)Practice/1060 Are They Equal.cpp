#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>

using namespace std;

string prepro(string &s, int m){
    int i, j, integer;
    string n;
    j = 0;
    while(s[j]=='0'||s[j]=='.') j++;
    if(s[0]=='0'&&s[1]=='.'){
        n = "0."+s.substr(j, m);
        if(n.length() - 2 < m) n.append(m - n.length() + 2, '0');
        if(j==s.length())
            return n + "*10^0";
        if(j==2)
            return n + "*10^0";
        else
            return n + "*10^-" + to_string(j-2);
    }
    else if(s=="0") {
        n = "0.";
        if(n.length() - 2 < m) n.append(m - n.length() + 2, '0');
        return n + "*10^0";
    }
    i = s.find('.');
    if(i < 0) {
        integer = s.length();
    }else{
        integer = i;
        s.erase(s.begin() + i);
    }
    if(s.length() < m) s.append(m - s.length(), '0');
    n = "0." + s.substr(j, m)+"*10^"+to_string(integer);
    return n;
}

int main(void){
    int i, j, m, n;
    string x0, x1, y1, y0;
    int int0, int1, int2;
    string l0, l1, r0, r1;
    cin>>m>>x0>>x1;
    x0 = prepro(x0, m);
    x1 = prepro(x1, m);
    if(x0==x1) cout<<"YES "<<x0;
    else cout<<"NO "<<x0<<" "<<x1;
    return 0;
}
