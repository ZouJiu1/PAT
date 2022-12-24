update1
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

struct nod {
    string nam;
    int tim;
    int typ=-1; //0 in //1 out
};
bool compare0(nod &a, nod &c) {
    return a.tim < c.tim;
}
/*
Any in records that are not paired with an out record are ignored, 
as are out records not paired with an in record.
任何“进入”记录不能和“出去”记录匹配的，要去掉；
也就是“in”记录后续的同个车辆的记录不是“out”而是“in”，
那么这个记录去掉，算后面那个“in”；同样，“out”不能和“in”匹配的也去掉，
多个“in”只要最后一个，多个“out”只要最开始那个
现象的reason是停在卡点了等车或者拿手机刷卡
所以“in”从车辆全部进入算起，也就是车后面离开卡点，多个“in”是车辆在卡点行驶
“out”从车辆的前端出去算起，多个“out”是车辆在卡点行驶
*/
int main(int argc, char **argv) {
    int i, j, k, m, n, l, y, z, hour, min, sec, status0[10006], cnt = 0, nowtime;
    fill(status0, status0+10006, 0);
    cin>>m>>n;
    string r0, r1, r2;
    nod nd, arr[10006][2];
    vector<nod> in, out;
    for(i = 0; i < m; i++) {
        cin>>nd.nam;
        scanf("%d:%d:%d", &hour, &min, &sec);
        nd.tim = hour * 3600 + min * 60 + sec;
        cin>>r0;
        if(r0=="in") {
            nd.typ = 0;
            in.push_back(nd);
        }
        else {
            nd.typ = 1;
            in.push_back(nd);
        }
    }
    sort(in.begin(), in.end(), compare0);
    for(i = 0; i < in.size(); i++) {
        int km = -9, outtim = -1;
        if(status0[i] == 1) continue;
        for(j = i; j < in.size(); j++) {
            if(in[j].typ==0 && status0[j]==0) {
                break;
            }
        }
        for(k = j + 1; k < in.size(); k++) {
            if(in[j].nam!=in[k].nam) continue;
            if(in[k].typ==0&&status0[k]==0) break;
            if(in[k].typ==1&&status0[k]==0) {
                status0[k] = 1;
                arr[cnt][0] = in[j];
                arr[cnt++][1] = in[k];
                km = 9;
                break;
            }
        }
        status0[j] = 1;
    }
    for(i = 0; i < n; i++) {
        scanf("%d:%d:%d", &hour, &min, &sec);
        nowtime = hour * 3600 + min * 60 + sec;
        int count = 0;
        for(j = 0; j < cnt; j++) {
            if(arr[j][0].typ < 0) continue;
            if(nowtime < arr[j][0].tim) break;
            if(nowtime < arr[j][1].tim && nowtime >= arr[j][0].tim) count++;
        }
        printf("%d\n", count);
    }
    int longtime = -999999999;
    vector<string> res;
    //give the plate number of the car that has parked for the longest time period, and the corresponding time length
    //总时间要加和，不是单个车辆单次最长时间!!!!!!
    unordered_map<string, int> ump;
    for(j = 0; j < cnt; j++) {
        ump[arr[j][0].nam] += arr[j][1].tim - arr[j][0].tim;
        if(longtime < ump[arr[j][0].nam]) {
            longtime = ump[arr[j][0].nam];
        }
    }
    for(unordered_map<string, int>::iterator j = ump.begin(); j != ump.end(); j++) {
        if(longtime==j->second)
            res.push_back(j->first);
    }
    sort(res.begin(), res.end());
    for(i = 0; i < res.size(); i++) cout<<res[i]<<" ";
    hour = longtime/3600;
    min = longtime%3600/60;
    sec = longtime%60;
    printf("%02d:%02d:%02d\n", hour, min, sec);
    return EXIT_SUCCESS;
}

update2
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

struct nod {
    string nam;
    int tim;
    int typ=0; //0 in //1 out
};
bool compare0(nod &a, nod &c) {
    if(a.nam < c.nam) return true;
    else if(a.nam==c.nam)
        return a.tim < c.tim;
    else return false;
}
bool compare1(nod &a, nod &c) {
    return a.tim < c.tim;
}
/*
Any in records that are not paired with an out record are ignored, 
as are out records not paired with an in record.
任何“进入”记录不能和“出去”记录匹配的，要去掉；
也就是“in”记录后续的同个车辆的记录不是“out”而是“in”，
那么这个记录去掉，算后面那个“in”；同样，“out”不能和“in”匹配的也去掉，
多个“in”只要最后一个，多个“out”只要最开始那个
现象的reason是停在卡点了等车或者拿手机刷卡
所以“in”从车辆全部进入算起，也就是车最后面离开卡点，多个“in”是车辆在卡点行驶
“out”从车辆的前端出去算起，多个“out”是车辆在卡点行驶
*/
int main(int argc, char **argv) {
    int i, j, k, m, n, l, y, z, hour, min, sec, cnt = 0, nowtime;
    cin>>m>>n;
    string r0, r1, r2;
    nod nd;
    vector<nod> in, tmp;
    for(i = 0; i < m; i++) {
        cin>>nd.nam;
        scanf("%d:%d:%d", &hour, &min, &sec);
        nd.tim = hour * 3600 + min * 60 + sec;
        cin>>r0;
        if(r0=="in") {
            nd.typ = 1;
            in.push_back(nd);
        }
        else {
            nd.typ = -1;
            in.push_back(nd);
        }
    }
    sort(in.begin(), in.end(), compare0);
    int longtime = -999999999;
    map<string, int> ump;
    for(i = 0; i < m - 1; i++) {
        if(in[i].typ==1 && in[i+1].typ==-1 && in[i].nam==in[i+1].nam) {
            tmp.push_back(in[i]);
            tmp.push_back(in[i+1]);
            ump[in[i].nam] += in[i+1].tim - in[i].tim;
            if(longtime < ump[in[i].nam]) {
                longtime = ump[in[i].nam];       //累计时间不是单次的停车时间
            }
            
        }
    }
    //Note: the queries are given in ascending order of the times.
    sort(tmp.begin(), tmp.end(), compare1);
    int v[10006];
    fill(v, v+10006, 0);
    v[0] = tmp[0].typ;
    for(i = 1; i < tmp.size(); i++) {
        v[i] = v[i-1] + tmp[i].typ;
    }
    int count = 0;
    for(i = 0; i < n; i++) {
        scanf("%d:%d:%d", &hour, &min, &sec);
        nowtime = hour * 3600 + min * 60 + sec;
        for(j = count; j < tmp.size(); j++) {
            if(nowtime < tmp[j].tim) {
                printf("%d\n", v[j-1]);
                break;
            }else if(j==tmp.size() - 1) {
                printf("%d\n", v[j]);
            }
        }
        count = j;
    }
    vector<string> res;
    for(map<string, int>::iterator j = ump.begin(); j != ump.end(); j++) {
        if(longtime==j->second)
            res.push_back(j->first);
    }
    sort(res.begin(), res.end());
    for(i = 0; i < res.size(); i++) cout<<res[i]<<" ";
    hour = longtime/3600;
    min = longtime%3600/60;
    sec = longtime%60;
    printf("%02d:%02d:%02d", hour, min, sec);
    return EXIT_SUCCESS;
}
old version

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
