#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int i, k;
    double m0=-666, m2=-666, m3=-666;
    int id0, id2, id3;
    map<int, string> mp{{0, "W"}, {1, "T"}, {2, "L"}};
    double sum = 0, j;
    for(i = 0; i < 3; i++){
        cin>>j;
        if(j>m0){
            id0 = i;
            m0 = j;
        }
    }
    for(i = 0; i < 3; i++){
        cin>>j;
        if(j>m2){
            id2 = i;
            m2 = j;
        }
    }
    for(i = 0; i < 3; i++){
        cin>>j;
        if(j>m3){
            id3 = i;
            m3 = j;
        }
    }
    cout<<mp[id0]<<" "<<mp[id2]<<" "<<mp[id3]<<" ";
    sum = (m0 * m2 * m3 * 0.65 - 1) * 2;
    printf("%.2f", sum);
    return 0;
}
