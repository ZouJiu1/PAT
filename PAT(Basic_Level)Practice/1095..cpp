#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

struct student{
    string ID;
    int num;
};

bool compare_firstly(const student &a, const student &b){
    if(a.num == b.num){
        if(a.ID < b.ID) return true;
        else return false;
    }
    return a.num > b.num;
}

int main(void){
    int n, m, res;
    cin>>n>>m;
    vector<student> vec(n);
    for(int i=0; i<n; i++){
        cin>>vec[i].ID>>vec[i].num;
    }
    int num;
    string ID;
    for(int i=1; i<=m; i++){
        cin>>num>>ID;
        vector<student> res;
        cout<<"Case "<<i<<": "<<num<<" "<<ID<<endl;
        if(num==1){
            for(int j=0; j<vec.size(); j++){
                if(vec[j].ID[0]==ID[0]) res.push_back(vec[j]);
            }
        }else if(num==2){
            int counts=0, sum=0;
            for(int j=0; j<vec.size(); j++){
                if(vec[j].ID.substr(1, 3)==ID) {
                    counts++;
                    sum += vec[j].num;
                }
            }
            if(counts==0) cout<<"NA"<<endl;
            else cout<<counts<<" "<<sum<<endl;
        }else if(num==3){
            unordered_map<string, int> mp;
            for(int j=0; j<vec.size(); j++){
                if(vec[j].ID.substr(4, 6)==ID) mp[vec[j].ID.substr(1, 3)] += 1;
            }
            for(auto it:mp) res.push_back({it.first, it.second}) ;
        }
        sort(res.begin(), res.end(), compare_firstly);
        for(int j=0; j<res.size(); j++){
            cout<<res[j].ID<<" "<<res[j].num<<endl;
        }
        if((res.size()==0)&&(num!=2)) cout<<"NA"<<endl;
    }
    return 0;
}
