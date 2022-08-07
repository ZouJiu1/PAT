#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<bits/stdc++.h>

using namespace std;
typedef struct{
    int weight, index, index0, rank;
}record;

bool compare(record &rd, record &ld){
    if(rd.index0 < ld.index0) return true;
    else return false;
}

int main(void){
    int i, j, g, m, n, t, counts, x, y, cnt=0;
    cin>>m>>g;
    vector<int> v, v0;
    vector<record> vrt;
    for(i = 0; i < m; i++){
        cin>>t;
        v.push_back(t);
    }
    record rcr, tmp;
    for(i = 0; i < m; i++){
        cin>>rcr.index0;
        rcr.weight = v[rcr.index0];
        rcr.index = i;
        rcr.rank  = 0;
        vrt.push_back(rcr);
    }
    queue<record> q;
    for(i = 0; i < m; i++){
        q.push(vrt[i]);
    }
    int group, max=-9;
    while(q.size()!=0){
        x = q.size();
        group = x/g;
        if(x%g!=0) group += 1;
        cnt = 0;
        if(x==1){
            rcr = q.front();
            vrt[rcr.index].rank = 1;
            break;
        }
        for(i = 0; i < x; i++){
            rcr = q.front();
            vrt[rcr.index].rank = group + 1;
            q.pop();
            cnt++;
            if(max < rcr.weight){
                max = rcr.weight;
                tmp = rcr;
            }
            if(cnt%g==0 || i == (x - 1) ){
                max = -9;
                q.push(tmp);
            }
        }
    }
    sort(vrt.begin(), vrt.end(), compare);
    for(i=0; i<m; i++){
        printf("%d", vrt[i].rank);
        if(i!=m-1) printf(" ");
    }
    return 0;
}
