#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int m, n, x, marked=-1;
    cin>>m>>n;
    vector<int> vec{2,3,5,7,11,13,17,19};
    for(unsigned int i=20; i<1000000; i++){
        x = (int)sqrt(i)+1;
        if((x-1)*(x-1)==i)
            continue;
        marked = -1;
        for(unsigned int j=2; j<x; j++){
            if(i%j==0){
                marked = 1;
                break;
            }
        }
        if(marked<0)
            vec.push_back(i);
        if(vec.size()>=n)
            break;
    }
    for(unsigned int i = m-1; i<n; i++){
        cout<<vec[i];
        x = i - m + 2;
        if(x%10==0&&i!=(n-1))
            cout<<endl;
        else if(x%10!=0&&i!=(n-1))
            cout<<" ";
    }
    return 0;
}
