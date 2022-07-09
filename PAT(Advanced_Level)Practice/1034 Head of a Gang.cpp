/* 使用set集合进行编号，然后map进行统计加和，最后遍历的时候要注意不要重复加和*/
#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<bits/stdc++.h>

using namespace std;

typedef struct _gan{
    string s;
    string s0;
    int k;
}gan;

typedef struct _save{
    string s;
    int sum;
}save;

int main(void){
    int i, j, k, m, n, t;
    cin>>m>>n;
    string s, s0, st;
    vector<string> vs;
    vector<gan> vec;
    set<string> stg;
    map<string, int> mp;
    gan gn;
    for(i = 0; i < m; i++){
        cin>>gn.s>>gn.s0>>gn.k;
        stg.insert(gn.s);
        stg.insert(gn.s0);
        vec.push_back(gn);
    }
    for(set<string>::iterator it=stg.begin(); it!=stg.end(); it++) 
        vs.push_back(*it);
    sort(vs.begin(), vs.end());
    for(i = 0; i < vs.size(); i++)
        mp[vs[i]] = i;
    short all[vs.size()][vs.size()] = {0};
    for(i = 0; i < vs.size(); i++)
        for(j = 0; j < vs.size(); j++)
            all[i][j] = 0;
    int kkk, www;
    for(i = 0; i < vec.size(); i++){
        kkk = mp[vec[i].s];
        www = mp[vec[i].s0];
        all[kkk][www] += vec[i].k;
        all[www][kkk] += vec[i].k;
    }
    int cnt = 0, sum;
    vector<save> vsr;
    save sv;
    string pre = "k";
    set<int> setall;
    set<int>::iterator it;
    for(i = 0; i < vs.size(); i++){
        it = setall.find(i);
        if(it!=setall.end()){
            continue;
        }
        sum = 0;
        cnt = 0;
        vector<int> queue;
        queue.push_back(i);
        set<int> tes;
        int maxmax = -999, kkk, ttt;
        while(queue.size()>0){
            kkk = queue[0];
            tes.insert(kkk);
            setall.insert(kkk);
            int tmp = 0;
            for(j = 0; j < vs.size(); j++){
                if(all[kkk][j]!=0){
                    cnt++;
                    tmp += all[kkk][j];
                    it = tes.find(j);
                    if(it==tes.end()){
                        queue.push_back(j);
                    }else continue;
                    sum += all[kkk][j];
                }
            }
            queue.erase(queue.begin());
            if(tmp > maxmax){
                maxmax = tmp;
                ttt = kkk;
            }
        }
        if(sum > n && tes.size()>2 && pre!=vs[ttt]){
            sv.s = vs[ttt];
            sv.sum = tes.size();
            vsr.push_back(sv);
            pre = vs[ttt];
        }
    }
    cout<<vsr.size()<<endl;
    for(i = 0; i < vsr.size(); i++){
        cout<<vsr[i].s<<" "<<vsr[i].sum<<endl;
    }
    return 0;
}
