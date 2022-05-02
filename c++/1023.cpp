#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n;
    vector<int> vec;
    for(int i=0; i<10; i++)
    {
        cin>>n;
        vec.push_back(n);
    }
    n = -9;
    for(int i=0; i<10; i++)
    {
        if(i==0&&vec[0]==0){
            for(int j=0; j<vec[i]; j++)
                cout<<i;
        }else{
            if(i==0)
                continue;
            if(vec[i]!=0&&n<0)
            {
                for(int j=0; j<vec[i]; j++)
                {
                    if(j==0){
                        cout<<i;
                        for(int j=0; j<vec[0]; j++)
                            cout<<0;
                    }else{
                        cout<<i;
                    }
                }
                n = 9;
                continue;
            }
            for(int j=0; j<vec[i]; j++)
                cout<<i;
        }
    }        
    return 0;
}
