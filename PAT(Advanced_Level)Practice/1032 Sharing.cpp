#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

int main(int argc, char **argv){
    char add[100003];
    int m, n, c, k, h, i, j, f;
    int w, t, x, y, z;
    int ind[100003];
    char ch;
    scanf("%d %d %d", &m, &n, &c);
    for(i = 0; i < c; i++){
        cin>>k>>ch>>f;
        add[k] = ch;
        ind[k] = f;
    }
    w = m;
    string s, s0;
    while(w!=-1){
        s += add[w];
        w = ind[w];
    }
    w = n;
    while(w!=-1){
        s0 += add[w];
        w = ind[w];
    }
    reverse(s.begin(), s.end());
    reverse(s0.begin(), s0.end());
    char tmp;
    int minmin = s.length() < s0.length()? s.length():s0.length();
    w = -1;
    for(i = 0; i < minmin; i++){
        if(s[i]==s0[i]){
            w = i;
            tmp = s[w];
        }
        if(s[i]!=s0[i]) break;
    }
    t = s.length() - w - 1;
    if(w < 0) cout<<"-1";
    else{
        x = m;
        for(i = 0; i < s.length(); i++){
            if(i == t) {
                printf("%05d", x);
                return 0;
            }
            x = ind[x];
        }
    }
    return EXIT_SUCCESS;
}
