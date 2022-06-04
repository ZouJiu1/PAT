#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

void printres(int my, int a){
    if(a>my) cout<<"Cong";
    else if(a==my) cout<<"Ping";
    else cout<<"Gai";
}

int main(void){
    int my, x, y, z, n, m, i, j, w, h, res;
    cin>>my>>m>>w;
    string s0, s9;
    h = -666;
    for(i=99; i>9; i--){
        x = i;
        s9 = to_string(x);
        reverse(s9.begin(), s9.end());
        y = stoi(s9);
        z = abs(x - y)/m;
        if(z*w==y){
            h = 666;
            break;
        }
    }
    if(h<0) {
        cout<<"No Solution";
        return 0;
    }
    cout<<x<<" ";
    printres(my, x);
    cout<<" ";
    printres(my, y);
    cout<<" ";
    printres(my, z);
    return 0;
}
