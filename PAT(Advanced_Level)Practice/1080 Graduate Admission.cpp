#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;
struct nodes{
    int ge;
    int gi;
    vector<int> apply;
    int ran;
    int ind;
};

bool compare(const nodes&a, const nodes&c){
    float avg0, avg1;
    avg0 = (float)(a.ge + a.gi)/2.0;
    avg1 = (float)(c.ge + c.gi)/2.0;
    if(avg0 > avg1) return true;
    else if(avg0==avg1){
        if(a.ge > c.ge) return true;
        else return false;
    }
    else return false;
}

int main(void){
    int i, j, m, n, k, w, q, xx, xy;
    vector<int> v, v0;
    nodes nd;
    cin>>m>>n>>k;
    for(i = 0; i < n; i++){
        cin>>q;
        v.push_back(q);
    }
    vector<nodes> vv;
    for(i = 0; i < m; i++){
        cin>>nd.ge>>nd.gi;
        for(j = 0; j < k; j++){
            cin>>q;
            nd.apply.push_back(q);
        }
        nd.ind = i;
        vv.push_back(nd);
        nd.apply.clear();
    }
    sort(vv.begin(), vv.end(), compare);
    xx = 0; 
    xy = 0;
    vv[0].ran = 1;
    int minval=9999999, maxval=-9999999;
    int marked_val[60000];
    int infff = -9999999999;
    memset((void *)marked_val, infff, sizeof(bool) * 60000); 
    for(i = 1; i < m; i++){
        xx++;
        if((vv[i].ge+vv[i].gi)==(vv[i-1].ge+vv[i-1].gi)&&
           vv[i].ge==vv[i-1].ge){
            vv[i].ran = vv[i - 1].ran;
            q = -999;
            xx = 0;
            for(j = 0; j < vv[i].apply.size(); j++){
                for(w = 0; w < vv[i-1].apply.size(); w++){
                    if(vv[i].apply[j]==vv[i-1].apply[w]){
                        q = 999;
                        xx = vv[i].apply[j];
                        break;
                    }
                }
            }
            if(q > 0){
                if(i-1 < minval) minval = i-1;
                if(i > maxval) maxval = i;
                marked_val[i] = xx;
                marked_val[i-1] = xx;
            }
        }else{
            vv[i].ran = xx;
        }
    }
    int admit = -999;
    vector<int> vtr[n];
    nd = {0};
    vv.push_back(nd);
    int status[m];
    memset((void *)status, 0, sizeof(int) * m);
    for(i = 0; i < m; i++){
        admit = -999;
        for(j = 0; j < vv[i].apply.size(); j++){
            q = vv[i].apply[j];
            if(v[q] > vtr[q].size()){
                admit = 999;
                break;
            }
            else if((marked_val[i]==q&&marked_val[i-1]==q)||
                (marked_val[i]==q&&marked_val[i+1]==q)){
                admit = 999;
                break;
            }
        }
        if(admit > 0){
            vtr[q].push_back(vv[i].ind);
            status[vv[i].ind] = 9;
        }
    }
    for(i = 0; i < n; i++){
        sort(vtr[i].begin(), vtr[i].end());
        for(j = 0; j < vtr[i].size(); j++){
            cout<<vtr[i][j];
            if(j!=vtr[i].size()-1) cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}
