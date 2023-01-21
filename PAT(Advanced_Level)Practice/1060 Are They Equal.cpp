update
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
using namespace std;
int main(void) {
    //小数点的地方（初始化数组长度）；不是0不是.的地方
    int i, j, k, m=0, n=0, N, leA, leK, pointA, pointK, notzeroA=0, notzeroK=0, pxA, pxK; 
    //123.456, 0.0000123456 123456
    cin>>N;
    char A[10006], K[10006];
    scanf("%s %s", &A, &K);
    leA = pointA = strlen(A)/sizeof(*A);
    leK = pointK = strlen(K)/sizeof(*K);
    for(i = 0; i < pointA; i++) {
        if(A[i]=='.') {
            pointA = i;
            break;
        }
    }
    for(i = 0; i < pointK; i++) {
        if(K[i]=='.') {
            pointK = i;
            break;
        }
    }
    while(A[notzeroA]=='0'||A[notzeroA]=='.') notzeroA++;
    while(K[notzeroK]=='0'||K[notzeroK]=='.') notzeroK++;
    if(pointA >= notzeroA) pxA = pointA - notzeroA;
    else pxA = pointA - notzeroA + 1;
    if(pointK >= notzeroK) pxK = pointK - notzeroK;
    else pxK = pointK - notzeroK + 1;
    if(notzeroA==leA) pxA = 0;
    if(notzeroK==leK) pxK = 0;
    string reA, reK;
    m = notzeroA;
    while(reA.length() < N) {
        if(A[m]!='.'&&m < leA) 
            reA += A[m];
        else if(m >= leA)
            reA += '0';
        m++;
    }
    m = notzeroK;
    while(reK.length() < N) {
        if(K[m]!='.'&&m < leK) 
            reK += K[m];
        else if(m >= leK)
            reK += '0';
        m++;
    }
    if(reA==reK && pxA==pxK) {
        printf("YES 0.");
        cout<<reA<<"*"<<"10^"<<pxA<<endl;
    }else{
        printf("NO 0.");
        cout<<reA<<"*"<<"10^"<<pxA<<" 0.";
        cout<<reK<<"*"<<"10^"<<pxK<<endl;
    }
    return EXIT_SUCCESS;
}

old before
#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>

using namespace std;

string prepro(string &s, int m){
    int i, j, integer;
    string n;
    j = 0;
    while(s[j]=='0'||s[j]=='.') j++;
    if(s[0]=='0'&&s[1]=='.'){
        n = "0."+s.substr(j, m);
        if(n.length() - 2 < m) n.append(m - n.length() + 2, '0');
        if(j==s.length())
            return n + "*10^0";
        if(j==2)
            return n + "*10^0";
        else
            return n + "*10^-" + to_string(j-2);
    }
    else if(s=="0") {
        n = "0.";
        if(n.length() - 2 < m) n.append(m - n.length() + 2, '0');
        return n + "*10^0";
    }
    i = s.find('.');
    if(i < 0) {
        integer = s.length();
    }else{
        integer = i;
        s.erase(s.begin() + i);
    }
    if(s.length() < m) s.append(m - s.length(), '0');
    n = "0." + s.substr(j, m)+"*10^"+to_string(integer);
    return n;
}

int main(void){
    int i, j, m, n;
    string x0, x1, y1, y0;
    int int0, int1, int2;
    string l0, l1, r0, r1;
    cin>>m>>x0>>x1;
    x0 = prepro(x0, m);
    x1 = prepro(x1, m);
    if(x0==x1) cout<<"YES "<<x0;
    else cout<<"NO "<<x0<<" "<<x1;
    return 0;
}
