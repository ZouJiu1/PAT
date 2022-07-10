#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
#include<vector>
#include<queue>

using namespace std;

struct pairer{
    int timestamp;
    int oritime;
    int playtime;
    int waittime;
    int start;
    int leave;
    int tablenum;
    int vip;
};

bool compare(const pairer& a, const pairer& b){
    if(a.timestamp < b.timestamp) return true;
    else return false;
}

bool compare_cc(const pairer& a, const pairer& b){
    if(a.start < b.start) return true;
    else if(a.oritime < b.oritime && (a.oritime < 8*3600&&b.oritime <8*3600)) return true;
    else return false;
}

int minleave(vector<pairer> &c){
    int minval = 99999999;
    int i, k;
    for(i=0; i<c.size(); i++){
        if(minval > c[i].leave) {
            minval = c[i].leave;
            k = i;
        }
    }
    return k;
}

int main(void){
    int i, j, m, n, k, h, hour, min, sec, t0, t6;
    pairer pr, pr0, pr6;
    vector<pairer> v, vr;
    set<int> vipset;
    vector<int> vipvec;
    cin>>n;
    int mn;
    for(i=0; i<n; i++){
        scanf("%d:%d:%d %d %d", &hour, &min, &sec, &mn, &pr.vip);
        if(mn > 120){ mn = 120; }
        pr.playtime = mn * 60;
        pr.timestamp = hour * 3600 + min * 60 + sec;
        pr.oritime = hour * 3600 + min * 60 + sec;
        if(pr.timestamp < (3600 * 8)) pr.timestamp = 8 * 3600;
        if(pr.timestamp >= (3600 * 21)) continue;
        v.push_back(pr);
    }
    cin>>k>>m;
    for(i = 0; i < m; i++){
        cin>>h;
        vipvec.push_back(h);
        vipset.insert(h);
    }
    sort(v.begin(), v.end(), compare);
    vector<pairer> pq;
    for(int i = 0; i < k; i++) {
        pr.timestamp = 8 * 3600;
        pr.playtime = 0;
        pr.waittime = 0;
        pr.leave = 8 * 3600;
        pr.tablenum = i + 1;
        pq.push_back(pr);
    }
    int leave, counts = 0, ind, tabnum, mar;
    set<int>::iterator it, it0;
    set<int> vipserve;
    for(i = 0; i < v.size(); i++){
        // it0 = vipserve.find(i);
        // if(it0!=vipserve.end()) continue;
        ind = minleave(pq);
        tabnum = pq[ind].tablenum;
        it = vipset.find(tabnum);
        mar = 999;
        if(it!=vipset.end()){
            for(j = i + 1; j < v.size(); j++){
                // it0 = vipserve.find(j);
                // if(it0!=vipserve.end()) continue;
                if(v[j].vip==1){
                    pr = pq[ind];
                    if(pr.leave > v[j].timestamp){ //waitting
                        v[j].leave = pr.leave + v[j].playtime;  //pre leave + now playing
                        v[j].start = pr.leave;
                        v[j].waittime = pr.leave - v[j].oritime;
                        v[j].tablenum = pr.tablenum;
                        pq.push_back(v[j]);
                        pr0 = v[i];
                        pr6 = v[j];
                        v.erase(v.begin() + i);
                        v.erase(v.begin() + j - 1);
                        v.insert(v.begin() + i, pr6);
                        v.insert(v.begin() + i + 1, pr0);
                        pq.erase(pq.begin() + ind);
                        // vipserve.insert(i);
                        mar = -999;
                        break;
                    }
                }
            }
        }
        if(mar < 0) continue;
        pr = pq[ind];
        if(pr.leave > v[i].timestamp){ //waitting
            v[i].leave = pr.leave + v[i].playtime;  //pre leave + now playing
            v[i].start = pr.leave;
            v[i].waittime = pr.leave - v[i].oritime;
            v[i].tablenum = pr.tablenum;
            pq.erase(pq.begin() + ind);
        }else{ //no waitting
            int minmin = 9999999;
            if(v[i].vip==0){
                for(int ij = 0; ij < pq.size(); ij++){ //check someplace no people table
                    if(pq[ij].leave <= v[i].timestamp && pq[ij].tablenum < minmin){
                        minmin = pq[ij].tablenum;
                        ind = ij;
                    }
                }
            }
            else{
                for(int ij = 0; ij < pq.size(); ij++){ //check someplace no people table
                    it = vipset.find(pq[ij].tablenum);
                    if(pq[ij].leave <= v[i].timestamp && pq[ij].tablenum < minmin && it!=vipset.end()){
                        minmin = pq[ij].tablenum;
                        ind = ij;
                    }
                }
                if(minmin > 99999){ 
                    for(int ij = 0; ij < pq.size(); ij++){ //check someplace no people table
                        if(pq[ij].leave <= v[i].timestamp && pq[ij].tablenum < minmin){
                            minmin = pq[ij].tablenum;
                            ind = ij;
                        }
                    }   
                }
            }
            pr = pq[ind];
            v[i].leave = v[i].timestamp + v[i].playtime;
            v[i].start = v[i].timestamp;
            if(v[i].oritime < 8*3600)
                v[i].waittime = pr.leave - v[i].oritime;
            else
                v[i].waittime = 0;
            v[i].tablenum = pr.tablenum;
            pq.erase(pq.begin() + ind);
        }
        // if(v[i].vip==1) vipserve.insert(i);
        pq.push_back(v[i]);
    }
    sort(v.begin(), v.end(), compare_cc);
    string str0, str6;
    int cal, cal0, cal6;
    int tablecount[k] = {0};
    for(int i = 0; i < v.size(); i++){
        cal = v[i].oritime;
        cal0 = v[i].start;
        cal6 = v[i].waittime;
        if(v[i].start >= (3600 * 21)) continue;
        printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", 
            cal/3600, (cal%3600)/60, (cal%3600)%60, 
            cal0/3600, (cal0%3600)/60, (cal0%3600)%60,
            (int)round((float)cal6/60.0));
        tablecount[v[i].tablenum - 1]++;
    }
    for(int i = 0; i < k; i++){
        cout<<tablecount[i];
        if(i!=(k-1)) cout<<" ";
    }
    return 0;
}
