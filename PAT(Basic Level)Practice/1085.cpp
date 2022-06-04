#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

struct student{
    int paiming;
    string s0;
    int score;
    int num;
};

bool compare(const student a, const student b){
    if(a.score == b.score && a.num==b.num){
        if(a.s0 < b.s0) return true;
        else return false;
    }else if(a.score == b.score && a.num!=b.num){
        if(a.num < b.num) return true;
        else return false;
    }else{
        if(a.score > b.score) return true;
        else return false;
    }
}
struct shu{
    int A;
    int B;
    int T;
    int num;
};
struct stores{
    string ss0;
    int scores;
    string ss9;
};
int main(void){
    int n, m, i, j, num, sum;
    string s0, s2, s3;
    vector<student> vec;
    cin>>n;
    map<string, shu> mp;
    vector<stores> vec0;
    for(i=0; i<n; i++){
        stores srs;
        cin>>srs.ss0>>srs.scores>>srs.ss9;
        s3.erase(s3.begin(), s3.end());
        for(j=0; j<srs.ss9.size(); j++) s3 += tolower(srs.ss9[j]);
        shu zi={0};
        srs.ss9= s3;
        vec0.push_back(srs);
        mp[s3] = zi;
    }
    for(i=0; i<n; i++){
        s0 = vec0[i].ss0;
        num = vec0[i].scores;
        s2 = vec0[i].ss9;
        shu zi = mp[s2];
        if(s0[0]=='A') zi.A += num;
        else if(s0[0]=='B') zi.B += num;
        else zi.T += num;
        zi.num++;
        mp[s2] = zi; 
    }
    for(map<string, shu>::iterator it=mp.begin(); it!=mp.end(); it++){
        student stt={0};
        stt.s0 = it->first;
        stt.num = it->second.num;
        stt.score = (int)floor((float)(it->second.B/(float)1.5) + it->second.A + it->second.T*1.5);
        vec.push_back(stt);
    }
    sort(vec.begin(), vec.end(), compare);
    sum = 1;
    num = 0;
    cout<<mp.size()<<endl;
    for(i=0; i<vec.size(); i++){
        if(((i-1)>=0) && vec[i].score==vec[i-1].score) {
            num++; 
            cout<<(i+1 - num)<<" "<<vec[i].s0<<" "<<vec[i].score<<" "<<vec[i].num<<endl; 
        }
        else {
            cout<<(i+1)<<" "<<vec[i].s0<<" "<<vec[i].score<<" "<<vec[i].num<<endl;
            num = 0;
        }
    }
    return 0;
}
