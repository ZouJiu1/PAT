/*
属于排队问题的，先排序，然后先将窗口填满，
并计算小于8时来的人等待的时间；填满以后看哪个窗口的人最先办理好业务，
也就是花的时间最少，当前时间要加上这个人的时间，
其他几个窗口的时间要减去这个人的时间；最开始要注意来的人可能很晚，
以至于其他人业务都办理完了，这时就不用排队了
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

struct tom{
    string s;
    int t;
};

bool compare(const tom& a, const tom& b){
    if(a.s<b.s) return true;
    else return false;
}

int main(){
    int a, b, c, d, e, f, i, j, hour0, min0, sec0, hour2, min2, sec2;
    vector<tom> v;
    cin>>a>>b;
    string s, s0;
    tom tm;
    bool occupied[b]={true};
    int process[b]={0};
    int times[b][3]={0};
    for(i = 0; i < a; i++){
        cin>>tm.s>>tm.t;
        v.push_back(tm);
    }
    sort(v.begin(), v.end(), compare);
    c = 0;
    j = 0;
    int counts = 0, h0, m0, e0;
    while(v.size()>0){
        d = 666;
        tm = v[0];
        hour0 = stoi(tm.s.substr(0, 2));
        min0 = stoi(tm.s.substr(3, 2));
        sec0 = stoi(tm.s.substr(6, 2));
        h0 = hour0;
        m0 = min0;
        e0 = sec0;
        v.erase(v.begin());
        if(hour0<8){
            hour0 = 8;
            min0 = 0;
            sec0 = 0;
        }else if(hour0>17||(hour0==17&&min0>0)
                ||(hour0==17&&min0==0&&sec0>0))
            continue;
        counts++;
        for(i = 0; i < b; i++){
            min2 = (process[i] + times[i][1])%60;
            hour2 = (process[i] + times[i][1])/60 + times[i][0];
            if(hour0>hour2||(hour0==hour2&&min0>min2)
              ||(hour0==hour2&&min0==min2&&sec0>sec2)){
                occupied[i] = false;
            }
        }

        c++;
        for(i = 0; i < b; i++){
            if(!occupied[i]){
                process[i] = tm.t;
                occupied[i] = true;
                times[i][0] = hour0;
                times[i][1] = min0;
                times[i][2] = sec0;
                d = -666;
                if(h0<8){
                    hour2 = 8;
                    min2 = 0;
                    if(hour2==h0&&min2==m0)
                        j += times[i][2] - e0;
                    else if(hour2==h0&&min2!=m0)
                        j += times[i][2] + 60 - e0 + (min2 - m0 - 1) * 60;
                    else if(hour2>h0&&min2==m0)
                        j += (hour2 - h0) * 3600 - m0 + min2;
                    else if(hour2>h0&&min2!=m0)
                        j += (hour2 - h0 - 1) * 3600 + (3600 - m0*60-e0 + min2*60+times[i][2]);
                }
                break;
            }
        }
        if(d<0) continue;
        d = 666;
        e = 9999999;
        for(i = 0; i < b; i++){
            if(process[i] < e){
                e = process[i];
                f = i;
                d = -666;
            }
        }
        min2 = (e + times[f][1])%60;
        hour2 = (e + times[f][1])/60 + times[f][0];
        if(hour2==h0&&min2==m0)
            j += times[f][2] - e0;
        else if(hour2==h0&&min2!=m0)
            j += times[f][2] + 60 - e0 + (min2 - m0 - 1) * 60;
        else if(hour2>h0&&min2==m0)
            j += (hour2 - h0) * 3600 - m0 + min2;
        else if(hour2>h0&&min2!=m0)
            j += (hour2 - h0 - 1) * 3600 + (3600 - m0*60-e0 + min2*60+times[f][2]);
        for(i = 0; i < b; i++){
            process[i] = process[i] - e;
            min2 = (e + times[i][1])%60;
            hour2 = (e + times[i][1])/60 + times[i][0];
            times[i][0] = hour2;
            times[i][1] = min2;
        }
        process[f] = tm.t;
    }
    printf("%.1f\n", (float)j/60.0/(float)counts);
    return  0;
}
