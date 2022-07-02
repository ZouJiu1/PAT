/*10进制转13进制的，要注意补齐两位0*/

#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

string convert13(int k){
    string s;
    int m, n, i;
    m = k;
    if(m==0) s = "00";
    while(m!=0){
        m = k/13;
        n = k%13;
        if(n==10) s += "A";
        else if(n==11) s += "B";
        else if(n==12) s += "C";
        else s += to_string(n);
        k = m;
    }
    reverse(s.begin(), s.end());
    if(s.length()==1) return "0" + s;
    return s;
}

int main(int argc, char **argv){
    int a, c, w, i, j;
    cin>>a>>c>>w;
    cout<<"#"<<convert13(a)<<convert13(c)<<convert13(w);
    return EXIT_SUCCESS;
}
