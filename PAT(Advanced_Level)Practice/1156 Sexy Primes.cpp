#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

bool judges(long long x){
    long long i = sqrt(x) + 2;
    if(x==2||x==3||x==5||x==7) return true;
    if(x==1||x==4||x==6) return false;
    for(long long j = 2; j <i; j++){
        if(x%j==0) return false;
    }
    return true;
}

int main(void){
    long long n, m, res;
    cin>>n;
    if(n<5) {
        cout<<"No"<<endl;
        cout<<5;
        return 0;
    }
    if(n==5){
        cout<<"Yes"<<endl;
        cout<<11;
        return 0;
    }
    bool bl9 = judges(n);
    bool bl, bl0;
    if(bl9){
        bl = judges(n+6);
        bl0 = judges(n-6);
        
        if(bl0){
            cout<<"Yes"<<endl; 
            cout<<(n-6);
            return 0;
        }
        if(!bl0&&bl){
            cout<<"Yes"<<endl;
            cout<<(n+6);
            return 0;
        }
    }
    cout<<"No"<<endl;
    bl = false;
    bl0 = false;
    bl9 = false;
    while(!((bl&&bl0)||(bl&&bl9))){
        bl = judges(++n);
        bl0 = judges(n + 6);
        bl9 = judges(n - 6);
    }
    cout<<n;
    return 0;
}
