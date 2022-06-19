#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

bool isprime(int a){
    if(a==2||a==3)
        return true;
    if(a==1) return false;
    int i, j, m;
    m = sqrt(a) + 2;
    for(i = 2; i < m; i++){
        if(a%i==0){
            return false;
        }
    }
    return true;
}

int number(string rs, int c){
    int i, j, a;
    a = 0;
    reverse(rs.begin(), rs.end());
    for(i = 0; i < rs.size(); i++){
        string cr = rs.substr(i, 1);
        a += stoi(cr) * pow(c, i);
    }
    return a;
}

string relsed(int a, int c){
    int m=2, n;
    string s;
    while(a){
        m = a/c;
        n = a%c;
        s += to_string(n);
        a = m;
    }
    return s;
}

int main(){
    int i, j, a=0, b, c, d, e, f, m, n;
    string s, s0;
    bool bl, bl0;
    while(a >= 0){
        cin>>a;
        if(a < 0) return 0;
        cin>>c;
        s = to_string(a);
        m = a;
        bl = isprime(m);
        s = relsed(a, c);
        n = number(s, c);
        bl0 = isprime(n);
        if(bl&&bl0) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
