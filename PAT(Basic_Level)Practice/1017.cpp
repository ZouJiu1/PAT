#include<iostream>
#include<algorithm>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    string A;
    int B, R, mod, division, K=-9;
    cin>>A>>B;
    R = A[0] - '0';
    division = R/B;
    mod = R%B;
    
    if(A.size()==1&&R<=B){
        cout<<"0 "<<R;
        return 0;
    }
    
    if(division!=0)
        cout<<division;
    for(int i=1; i< A.size(); i++){
        R = A[i] - '0';
        division = (int)(R + mod * 10)/B;
        mod = (R + mod * 10) % B;
        if(division==0&&K>0)
            cout<<division;
        else if(division!=0){
            cout<<division;
            K = 9;
        }
    }
    cout<<" "<<mod;
    return 0;
}
