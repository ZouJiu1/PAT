#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

int main(){
    long long a, w, c;
    int x, y, m;
    cin>>a>>c;
    string s, s0;
    vector<int> v, v0;
    w = a;
    if(w==0) s+='0';
    while(w!=0){
        w = a/c;
        y = a%c;
        s += to_string(y);
        v.push_back(y);
        a= w;
    }
    v0 = v;
    reverse(v.begin(), v.end());
    if(v0==v) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    for(int i=0; i<v.size(); i++){
        cout<<v[i];
        if(i!=(v.size()-1)) cout<<" ";
    }
    return 0;
}
