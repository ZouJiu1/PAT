#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

template<typename T>
void printres(int my, T a){
    if(a>my) cout<<"Cong";
    else if(a==my) cout<<"Ping";
    else cout<<"Gai";
}

int main(void){
    int my, x, y, n, m, i, j, w, h, res;
    double z;
    cin>>my>>m>>w;
    string s0, s9;
    h = -666;
    for(i=99; i>9; i--){
        x = i;
        s9 = to_string(x);
        reverse(s9.begin(), s9.end());
        y = stoi(s9);
        z = (double)(abs(x - y)/(double)m);
        if(((double)z*w)==y){
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
