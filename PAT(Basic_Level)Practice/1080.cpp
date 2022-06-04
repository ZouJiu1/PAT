#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

struct student{
    string xuehao;
    int score0;
    int score2;
    int score3;
    int score6;
};

bool compare(const student a, const student b){
    if(a.score6 == b.score6){
        if(a.xuehao < b.xuehao) return true;
        else return false;
    }
    return a.score6 > b.score6;
}

int main(void){
    int m, n, k, i, j, num;
    string s0, s2, s3;
    vector<student> vec, vec2, vec3, vec6;
    map<string, int> mp0, mp2, mp3;
    set<string> st0, st2, st3, st6;
    cin>>m>>n>>k;
    for(i=0; i<m; i++){
        cin>>s0>>num;
        mp0[s0] = num;
        st0.insert(s0);
        st6.insert(s0);
    }
    for(i=0; i<n; i++){
        cin>>s0>>num;
        mp2[s0] = num;
        st2.insert(s0);
        st6.insert(s0);
    }
    for(i=0; i<k; i++){
        cin>>s0>>num;
        mp3[s0] = num;
        st3.insert(s0);
        st6.insert(s0);
    }
    int tmp0, tmp2, tmp3, tmp6, G;
    for(set<string>::iterator it=st6.begin(); it!=st6.end(); it++){
        s0 = *it;
        set<string>::iterator it0 = st0.find(s0);
        if(it0==st0.end()){
            continue;
        }else if(mp0[s0]<200) continue;
        it0 = st2.find(s0);
        if(it0==st2.end()){
            tmp2 = -1;
        }else{
            tmp2 = mp2[s0];
        };
        it0 = st3.find(s0);
        if(it0==st3.end()){
            tmp3 = -1;
        }else{
            tmp3 = mp3[s0];
        };
        if(tmp2<0) tmp0 = 0;
        else tmp0 = tmp2;
        if(tmp3<0) tmp6 = 0;
        else tmp6 = tmp3;
        if(tmp0>tmp6)
            G = (int)round((float)tmp0 * 0.4 + (float)tmp6 * 0.6);
        else G = tmp6;
        if(G<60) continue;
        student stu;
        stu.xuehao = s0;
        stu.score0 = mp0[s0];
        stu.score2 = tmp2;
        stu.score3 = tmp3;
        stu.score6 = G;
        vec.push_back(stu);
    }   
    sort(vec.begin(), vec.end(), compare);
    for(i=0; i<vec.size(); i++){
        cout<<vec[i].xuehao<<" "<<vec[i].score0<<" "<<vec[i].score2<<" "<<vec[i].score3<<" "<<vec[i].score6<<endl;
    }
    return 0;
}
