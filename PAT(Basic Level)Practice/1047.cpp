#include<iostream>
#include<algorithm>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n, tmp, num, score[1001], markes[1001];
    memset((void *)markes, 0, sizeof(int)*1001);
    string s0, s1;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>s0>>num;
        tmp = s0.find('-');
        s1 = s0.substr(0, tmp);
        tmp = stoi(s1);
        markes[tmp] += num;
    }
    int maxmax = -666666666, ind;
    for(int i=1; i<1001; i++){
        if(markes[i] > maxmax){
            maxmax = markes[i];
            ind = i;
        }
    }
    cout<<ind<<" "<<maxmax<<endl;
    return 0;
}
