/*
注意ranking是累加
*/
#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
#include<vector>

using namespace std;

struct testee{
    string ID;
    int score;
    int loc;
    int wholerank;
    int locrank;
};

bool compareloc(const testee &a, const testee &b){
    if(a.score > b.score) return true;
    else if(a.score < b.score) return false;
    else if(a.score == b.score){
        if(a.ID <= b.ID) return true;
        else return false;
    }
}

int main(void){
    string s, s0, sk;
    int m, n, k, i, j, f, h;
    cin>>n;
    vector<testee> v, vx;
    testee tst;
    vector<int> vtr;
    for(i = 0; i < n; i++){
        cin>>m;
        vtr.push_back(m);
        for(j = 0; j < m; j++){
            cin>>tst.ID>>tst.score;
            tst.loc = i + 1;
            vx.push_back(tst);
        }
    }
    h = 0;
    for(i = 0; i < n; i++){
        vector<testee> v0;
        k = 1;
        for(j = 0; j < vtr[i]; j++){
            tst = vx[h++];
            v0.push_back(tst);
        }
        sort(v0.begin(), v0.end(), compareloc);
        if(v0.size()>0) v0[0].locrank = k;
        for(j = 1; j < vtr[i]; j++){
            k++;
            if(v0[j - 1].score==v0[j].score) v0[j].locrank = v0[j - 1].locrank;
            else v0[j].locrank = k;
        }
        for(j = 0; j < vtr[i]; j++) v.push_back(v0[j]);
    }
    k = 1;
    sort(v.begin(), v.end(), compareloc);
    if(v.size()>0) v[0].wholerank = k;
    for(j = 1; j < v.size(); j++){
        k++;
        if(v[j - 1].score==v[j].score) v[j].wholerank = v[j - 1].wholerank;
        else v[j].wholerank = k;
    }
    cout<<v.size()<<endl;
    for(j = 0; j < v.size(); j++) cout<<v[j].ID<<" "<<v[j].wholerank<<" "<<v[j].loc<<" "<<v[j].locrank<<endl;
    return 0;
}
