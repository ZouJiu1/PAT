#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n, m, res, i, j, num, mar;
    cin>>n;
    vector<int> vec;
    string s0, s2;
    for(i = 0; i < n; i++){
        cin>>num;
        vec.push_back(num);
    }
    for(m = 0; m < vec.size(); m++){
        num = -666;
        for(i = 1; i < 10; i++){
            res = vec[m] * vec[m] * i;
            s0 = to_string(res - vec[m]);
            s2 = to_string(vec[m]);
            mar = -666;
            for(j = 0; j < s2.size(); j++){
                if(s0[s0.size()-1-j]!='0'){
                    mar = 666;
                    break;
                }
            }
            if(mar>0) continue;
            else{
                cout<<i<<" "<<res<<endl;
                num = 666;
                break;
            }
        }
        if(num<0) cout<<"No"<<endl;
    }
    return 0;
}
