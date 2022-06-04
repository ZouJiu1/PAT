#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n, m, res;
    cin>>n>>m;
    res = n*m;
    string ss = to_string(res);
    reverse(ss.begin(), ss.end());
    cout<<stoi(ss);
    return 0;
}
