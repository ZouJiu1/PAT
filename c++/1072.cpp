#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n0, n2, num, mar, counts=0;
    cin>>n0>>n2;
    string s0, s2, s3, s6;
    set<string> st;
    for(int i=0; i<n2; i++){
        cin>>s0;
        st.insert(s0);
    }
    vector<string> vec[n0];
    for(int i=0; i<n0; i++){
        cin>>s0>>num;
        mar = -666;
        for(int j=0; j<num; j++){
            cin>>s2;
            set<string>::iterator it = st.find(s2);
            if(it!=st.end()){
                if(mar<0){
                    vec[counts].push_back(s0);
                    vec[counts].push_back(s2);
                    mar = 6;
                }else{
                    vec[counts].push_back(s2);
                }
            }
        }
        if(mar>0)
            counts++;
    }
    counts = 0;
    num = 0;
    for(int i=0; i<n0; i++){
        if(vec[i].size()==0) break;
        for(int j=0; j<vec[i].size(); j++){
            if(j==0) cout<<vec[i][0]<<":";
            else cout<<vec[i][j];
            if(j!=vec[i].size()-1) cout<<" ";
            num++;
        }
        counts++;
        cout<<endl;
    }
    cout<<counts<<" "<<num-counts<<endl;
    return 0;
}
