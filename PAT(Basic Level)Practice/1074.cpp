#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    string s0, s2, s3, res;
    cin>>s0>>s2>>s3;
    int x, y, z, w, h, m=0, n;
    int max0 = s2.size()>s3.size()? (int)s2.size():(int)s3.size();
    int max1 = s0.size()>s3.size()? (int)s0.size():(int)s3.size();
    int max2 = max0<max2? (int)max2:(int)max0;
    reverse(s0.begin(), s0.end());
    reverse(s3.begin(), s3.end());
    reverse(s2.begin(), s2.end());
    s3.append(max2-s3.size(), '0');
    s2.append(max2-s2.size(), '0');
    s0.append(max2-s0.size(), '0');
    for(int i=0; i<s2.size(); i++){
        x = s2[i]-'0';
        y = s3[i]-'0';
        w = s0[i]-'0';
        if(w==0) w=10;
        z = x+y+m;
        h = z%w;
        m = z/w;
        res += to_string(h);
    }
    if(m>0){
        while(m!=0){
            h = m%w;
            m = m/w;
            res += to_string(h);
        }
    }
    for(int i=res.size()-1; i>=0; i--){
        if(res[i]=='0'){
            res.pop_back();
        }else break;
    }
    reverse(res.begin(), res.end());
    if(res.size()==0) res +='0';
    cout<<res;
    return 0;
}
