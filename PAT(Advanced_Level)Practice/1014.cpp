/*
排队问题要注意最开始队列要特殊处理，当线区内部人不满时，直接顺序添人排队，不用考虑队列的长度，只有线区填满以后，才开始考虑队列的长度，及时将人补到队列长度最短的地方；而且还要注意队列第一个人办完业务的时间，其他的队列第一个人要减去这个人的时间；所以第一个人较重要

输出的时候要注意>=17:00，是说刚开始排队的时间，不是结束时间
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

int main(){
    int N, M, K, Q, e, f, g, h, i, j, nm, filled;
    cin>>N>>M>>K>>Q;
    vector<int> v, v0;
    int times[N]={0};
    int person[K]={0};
    int num[N]={0};
    vector<int> vec[N];

    for(int i=0; i<K; i++){
        cin>>f;
        v.push_back(f);
    }
    for(int i=0; i<Q; i++){
        cin>>f;
        v0.push_back(f);
    }
    h = 0;
    nm = 0;
    filled = 666;
    vector<int> vtr = v;
    while(v.size() > 0){
        g = 999999;
        e = 0;
        f = v[0];
        v.erase(v.begin());
        nm++;
        if(nm <= (N*M)){
            times[(h++)%N] += f;
            person[h-1] = times[(h-1)%N];
            num[(h-1)%N]++;
            vec[(h-1)%N].push_back(f);
            if(filled > 0){
                g = 999999;
                e = 0;
                for(i = N-1; i >= 0; i--){
                    if(vec[i].size()>0&&vec[i][0]<=g) {
                        g = vec[i][0];
                        e = i;
                    }else if(vec[i].size()==0){
                        g = 0;
                        e = i;
                    }
                }
                if(num[e]>0){
                    num[e]--;
                    filled = -666;
                    for(j = 0; j<N; j++){
                        if(j!=e&&vec[j].size()>0) 
                            vec[j][0] = vec[j][0] - vec[e][0];
                    }
                    vec[e].erase(vec[e].begin());
                }
            }
            continue;
        }

        for(i = N-1; i >= 0; i--){
            if(num[i]<=g) {
                g = num[i];
                e = i;
            }
        }
        times[e] += f;
        person[h] = times[e];
        num[e]++;
        vec[e].push_back(f);
        h++;

        g = 999999;
        e = 0;
        for(i = N-1; i >= 0; i--){
            if(vec[i].size()>0&&vec[i][0]<=g) {
                g = vec[i][0];
                e = i;
            }else if(vec[i].size()==0){
                g = 0;
                e = i;
            }
        }
        if(num[e]>0){
            num[e]--;
            for(j = 0; j<N; j++){
                if(j!=e&&vec[j].size()>0) 
                    vec[j][0] = vec[j][0] - vec[e][0];
            }
            vec[e].erase(vec[e].begin());
        }
    }
    int hour, min, tmp, hor, mi;
    for(i = 0; i < Q; i++){
        hour = person[v0[i]-1]/60 + 8;
        min = person[v0[i]-1]%60;
        if(hour>=17){
            tmp = person[v0[i] -1 ] - vtr[v0[i] - 1];
            hor = tmp/60 + 8;
            if(hor>=17){
                cout<<"Sorry"<<endl;
                continue;
            }
        }
        printf("%02d:%02d\n", hour, min);
    }
    return 0;
}
