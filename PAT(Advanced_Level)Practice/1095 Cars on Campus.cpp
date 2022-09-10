#include<iostream>
#include<string>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

struct nod{
    string s;
    int time;
    int inout; //in0 out1
};

bool compare(struct nod &a, struct nod &c) {
    if(a.time < c.time) return true;
    else return false;
}

int main(void){
    int i, j, k, m, n, hour, min, sec, time, w, dur;
    string s, s0;
    cin>>m>>n;
    struct nod nd, ndpre;
    vector<struct nod> v, v0;
    bool status[m];
    for(i = 0; i < m; i++) {
        cin>>nd.s;
        scanf("%d:%d:%d", &hour, &min, &sec);
        cin>>s0;
        time = hour * 3600 + min * 60 + sec;
        nd.time = time;
        if(s0[0] == 'i')  nd.inout = 0;
        else nd.inout = 1;
        v.push_back(nd);
        status[i] = false;
    }
    sort(v.begin(), v.end(), compare);
    vector<int> query;
    for(i = 0; i < n; i++) {
        scanf("%d:%d:%d", &hour, &min, &sec);
        time = hour * 3600 + min * 60 + sec;
        query.push_back(time);
    }
    k = 0;
    while(v[k].inout!=0)
        k++;
    w = k;
    dur = -9999999;
    for(j = k; j < m; j++) {
        ndpre = v[j];
        if(status[j]==true) continue;
        if(ndpre.inout==1) continue;
        status[j] = true;
        w = j;
        for(i = j + 1; i < m; i++) {
            if(status[i]==true) continue;
            if(v[i].s == ndpre.s && v[i].inout==1) {
                v0.push_back(ndpre);
                v0.push_back(v[i]);
                min = v[i].time - ndpre.time;
                if(dur < min) dur = min;
                status[i] = true;
                status[w] = true;
                break;
            } else if(v[i].s==ndpre.s && v[i].inout==0){
                ndpre = v[i];
                w = i;
            }
        }
    }
    vector<string> vs;
    for(i = 0; i < v0.size()/2; i++){
        min = v0[i*2 + 1].time - v0[i*2].time;
        if(min==dur) vs.push_back(v0[i*2].s);
    }
    sort(vs.begin(), vs.end());
    for(j = 0; j < n; j++) {
        time = query[j];
        hour = 0;
        for(i = 0; i < v0.size()/2; i++){
            if(time >= v0[i*2].time && time < v0[i*2 + 1].time)
                hour += 1;
        }
        cout<<hour<<endl;
    }
    for(i = 0; i < vs.size(); i++){
        cout<<vs[i]<<" ";
    }
    printf("%02d:%02d:%02d", dur/3600, dur%3600/60, dur%3600%60);
    return 0;
}
