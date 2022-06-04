#include<iostream>
#include<algorithm>
#include<string>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    string A, B, Da, Db, tmp;
    string na[1] = {}, nb[1] = {};
    int i, sum=0;
    cin>>A>>Da>>B>>Db;
    for(i = 0; i < A.size(); i++){
        tmp = A[i];
        if(tmp==Da)
            na[0].push_back(A[i]);
    }
    for(i = 0; i < B.size(); i++){
        tmp = B[i];
        if(tmp==Db)
            nb[0].push_back(B[i]);
    }
    sum = atoi(na[0].c_str()) + atoi(nb[0].c_str());
    cout<<sum<<endl;
    return EXIT_SUCCESS;
}
