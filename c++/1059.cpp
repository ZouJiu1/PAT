#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n, num;
    cin>>n;
    vector<string> vec, vec0;
    string ing;
    map<string, string> mp;
    map<string, int> check;
    set<string> st;
    for(int i=0; i<n; i++){
        cin>>ing;
        vec.push_back(ing);
        st.insert(ing);
        check[ing] = 0;
    }
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>ing;
        vec0.push_back(ing);
    }
    
    int mar;
    string s0{"Chocolate"}, s1{"Minion"}, s2{"Mystery Award"};
    mp[vec[0]] = s2;
    if(vec.size()>=2) mp[vec[1]] = s1;
    if(vec.size()>=3) mp[vec[2]] = s1;
    for(int i=3; i<vec.size(); i++){
        num = (int)sqrt(i)+1;
        mar = -6;
        for(int j=2; j<=num; j++){
            if((i+1)%j==0){
                mp[vec[i]] = s0;
                mar=6;
                break;
            }
        }
        if(mar<0){
            mp[vec[i]] = s1;
        }
    }
    for(int i=0; i<vec0.size(); i++){
        mar = -6;
        set<string>::iterator it = st.find(vec0[i]);
        if(it!=st.end()){
            if(check[vec0[i]]==0){
                cout<<vec0[i]<<": "<<mp[vec0[i]]<<endl;
                check[vec0[i]] = 1;
            }else{
                cout<<vec0[i]<<": Checked"<<endl;
            }

        }else{
            cout<<vec0[i]<<": Are you kidding?"<<endl;
        }
    }
    return 0;
}
