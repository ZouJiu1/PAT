/*
使用了多叉树，要注意这里要输出每代的人数，所以在结构体里添加了层次记录layers，以及是否存在child，使用了迭代，
逐次将每个人的结构体附着到上层，属于层次遍历，
第一次层次遍历是为了立多叉树，第二次层次遍历是为了记录每一层的无child的人数，每层的0值也要输出的
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

struct nodeinfo{
    string ID;
    int num;
    int layers;
    vector<nodeinfo> children;
};

int main(void){
    int n, m, a, b ,c, i, j, k;
    cin>>n>>m;
    if(m==0){cout<<"1"; return 0;}
    string s0, s2, s3;
    set<string> st0, st2;
    vector<nodeinfo> vec;
    vector<int> counts;
    int cts[1001];
    for(i = 0; i < m; i++){
        nodeinfo ni, ni0;
        cin>>s0>>b;
        if(m==1&&b==0) {cout<<"1"; return 0;}
        ni.ID = s0;
        ni.num = b;
        ni.layers = 0;
        for(j = 0; j < b; j++){
            cin>>s2;
            ni0.ID = s2;
            ni0.num = 0;
            ni0.layers = 1;
            ni.children.push_back(ni0);
        }
        vec.push_back(ni);
        if(s0=="01") c=i;
        else counts.push_back(i);
    }
    vector<nodeinfo> *starts = &vec[c].children;
    vector<int> vtr;
    vtr.push_back((long long)starts);
    while(vtr.size()){
        vector<nodeinfo> *sta = (vector<nodeinfo> *)vtr[0];
        vtr.erase(vtr.begin());
        for(i = 0; i < sta->size(); i++){
            for(j = 0; j < vec.size(); j++){
                if(sta->at(i).ID==vec[j].ID){
                    sta->at(i).children = vec[j].children;
                    sta->at(i).num = vec[j].children.size();
                    for(k = 0; k < sta->at(i).children.size(); k++){
                        sta->at(i).children[k].layers = sta->at(i).layers + 1;
                    }
                    vtr.push_back((long long)&(sta->at(i).children));
                    break;
                }
            }
        }
    }
    starts = &vec[c].children;
    vtr.push_back((long long)starts);
    map<int, int> mp;
    int max = -666;
    while(vtr.size()){
        vector<nodeinfo> *sta = (vector<nodeinfo> *)vtr[0];
        vtr.erase(vtr.begin());
        for(i = 0; i < sta->size(); i++){
            if(sta->at(i).children.size()>0)
                vtr.push_back((long long)&(sta->at(i).children));
            if(sta->at(i).num==0) mp[sta->at(i).layers] += 1;
            if(max<sta->at(i).layers) max = sta->at(i).layers;
        }
    }
    cout<<"0";

    for(i = 1; i < max+1; i++){
        printf(" %d", mp[i]+0);
    }
    return 0;
}
