update202302，素数定义是在10进制，所以要转到10进制判断是否是素数
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
bool isprime(int a) {
    if(a<=1) return false;
    for(int i = 2; i * i <= a; i++) {
        if(a%i==0) return false;
    }
    return true;
}
vector<int> v;
void radix(int a, int r) {
    int tmp;
    while(a!=0){
        tmp = a%r;
        a = a/r;
        v.push_back(tmp);
    }
}
int to_ten_radix(int r) {
    int l = v.size(), sum=0;
    for(int i = 0; i < l; i++) {
        sum += (int)pow(r, l - i - 1) * v[i];
    }
    return sum;
}
int main(void) {
    int i, j, k, m, n;
    cin>>m;
    while(m >= 0) {
        cin>>n;
        if(!isprime(m)) printf("No\n");
        else {
            v.clear();
            radix(m, n);
            k = to_ten_radix(n);
            if(!isprime(k)) printf("No\n");
            else printf("Yes\n");
        }
        cin>>m;
    }
    return 0;
}

old before
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
