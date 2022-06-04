#include<vector>
#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

bool judge(int num){
    int tmp = num;
    if(num>6)
        tmp = sqrt(num) + 1;
    for(int i=2; i<tmp; i++){
        if(num%i==0) return false;
    }
    return true;
}


int main(void){
    int n;
    unsigned int i;
    vector<int> vc{2};
    cin>>n;
    if(n<=4){
        cout<<0;
        return 0;
    }
    for(i = 3; i < n + 1; i++){
        if(judge(i))
            vc.push_back(i);
    }
    n = 0;
    for(i = 0; i<vc.size()-1; i++){
        if(vc[i+1]-vc[i]==2){
            n++;
        }
    }
    cout<<n;
    return 0;
}
