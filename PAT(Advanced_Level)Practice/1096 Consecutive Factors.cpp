#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

int main(void) {
    int i, j, k, m, n, w, y;
    cin>>m;
    vector<int> v, v0;
    int x = (int)sqrt(m) + 10;
    if(x > m) x = m;
    int mul = 1;
    int maxmax = -999999;
    for(j = 2; j < x; j++) {
        mul = 1;
        v.clear();
        for(i = j; i < x; i++) {
            y = m%i;
            if(y!=0) {
                if(v.size() > 0)
                    break;
            }
            else {
                mul *= i;
                if(m%mul!=0)
                    break;
                v.push_back(i);
                if((int)v.size() > maxmax) {
                    v0 = v;
                    maxmax = v.size();
                }
            }
        }
    }
    
    if(v0.size()==0) {
        cout<<1<<endl;
        cout<<m;
    }else
        cout<<v0.size()<<endl;
    for(i = 0; i < v0.size(); i++) {
        cout<<v0[i];
        if(i!=v0.size()-1) cout<<"*";
    }
    return 0;
}

update
#include<cmath>
#include<vector>
#include<string>
#include<iostream>
using namespace std;
int main(void) {
    int i, j, k, m, n, w=0, y, len=0;
    cin>>m;
    int mul = 1, sqr = (int)sqrt(m) + 1;
    for(j = 2; j <= sqr; j++) {
        mul = 1;
        for(i = j; i <= sqr; i++) {
            mul *= i;
            if(m % mul!=0) break;
        }
        if(i - j> len){
            len = i - j;
            w = j;
        }
    }
    
    if(w==0) {
        cout<<1<<endl<<m;
    }else
        cout<<len<<endl;
    for(i = 0; i < len; i++) {
        cout<<w + i;
        if(i!=len-1) cout<<"*";
    }
    return 0;
}
