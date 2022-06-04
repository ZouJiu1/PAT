#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int i, num, score, n, max = -666, ind;
    cin>>n;
    int col[100000];
    memset(col, 0, sizeof(int)*100000);
    for(i=0; i<n; i++){
        cin>>num>>score;
        col[num] += score;
        if(max<col[num]){
            max = col[num];
            ind = num;
        }
    }
    cout<<ind<<" "<<max<<endl;
    return 0;
}
