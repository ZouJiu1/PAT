#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

bool compare(const int a, const int b){
    return a>b;
}
int main(void){
    int n, num, mar, sum;
    vector<int> vec, v0, v2, v6;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>num;
        vec.push_back(num);
    }
    for(int i=0; i<n; i++){
        num = vec[i];
        v0.erase(v0.begin(), v0.end());
        v0.push_back(1);
        v0.push_back(num);
        for(int j=2; j<num; j++){
            if(num%j==0) v0.push_back(j);
        }
        if(v0.size()<4){
            cout<<"No"<<endl;
            continue;
        }
        sort(v0.begin(), v0.end(), compare);
        mar = 666;
        for(int ii=0; ii<v0.size()-3; ii++){
            for(int jj=ii+1; jj<v0.size()-2; jj++){
                for(int ww=jj+1; ww<v0.size()-1; ww++){
                    for(int hh=ww+1; hh<v0.size(); hh++){
                        sum = v0[hh] + v0[ww] + v0[ii] + v0[jj];
                        if(sum<num){
                            mar = -666;
                            break;
                        }
                        if(sum%num==0){
                            mar=999;
                            break;
                        }
                    }
                    if(mar<0) break;
                    else if(mar==999) break;
                }
                if(mar<0) break;
                else if(mar==999) break;
            }
            if(mar<0) break;
            else if(mar==999) break;
        }
        if(mar<0||mar==666) cout<<"No"<<endl;
        else if(mar==999) cout<<"Yes"<<endl;
    }
    return 0;
}
