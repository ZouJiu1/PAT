#include<iostream>
#include<algorithm>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    vector<int> vec;
    int num, pre, aft, res;
    int count = 0;
    while(cin>>num){
        if(cin.get()=='\n'){
            break;
        }
        if(count%2==0)
            pre = num;
        else{
            aft = num;
            res = pre * aft;
            if(res!=0){
                vec.push_back(res);
                vec.push_back(aft-1);
            }
        }
        count++;
    }
    if(vec.size()==0&&count!=0)
        cout<<"0 0";
    for(unsigned int i=0; i<vec.size(); i++){
        cout<<vec[i];
        if(i!=vec.size()-1){cout<<" ";}
    }
    return 0;
}
