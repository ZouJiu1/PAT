#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

struct student{
    string ID;
    int scores;
};

struct datettime{
    string ID;
    int num;
};

struct structure{
    string ji;
    string kaochangbianhao;
    string kaoshiriqi;
    string bianhao;
};

bool compare_firstly(const student a, const student b){
    if(a.scores == b.scores){
        if(a.ID < b.ID) return true;
        else return false;
    }
    return a.scores > b.scores;
}

bool compare_thirdly(const datettime a, const datettime b){
    if(a.num == b.num){
        if(a.ID < b.ID) return true;
        else return false;
    }
    return a.num > b.num;
}

int main(void){
    int n, m, k, res, num;
    cin>>n>>k;
    string s0, s2, s3, s6, ss, s9;
    vector<string> vec, zhi;
    vector<int> vec0, zhi0;
    for(int i=0; i<n; i++){
        cin>>s0>>res;
        vec.push_back(s0);
        vec0.push_back(res);
    }
    for(int i=0; i<k; i++){
        cin>>res>>s0;
        zhi.push_back(s0);
        zhi0.push_back(res);
    }
    vector<structure> str;
    for(int j=0; j<n; j++){
        structure stt;
        stt.ji = vec[j][0];
        stt.kaochangbianhao = vec[j].substr(1, 3);
        stt.kaoshiriqi = vec[j].substr(4, 6);
        stt.bianhao = vec[j].substr(10, 3);
        str.push_back(stt);
    }
    for(int i=0; i<k; i++){
        s0 = zhi[i];
        num = zhi0[i];
        vector<student> ste;
        vector<datettime> dte;
        map<string, int> mp;
        int kaochangrenshu=0, zongscores=0;
        for(int j=0; j<n; j++){
            s2 = str[j].ji;
            s3 = str[j].kaochangbianhao;
            s6 = str[j].kaoshiriqi;
            s9 = str[j].bianhao;
            if(num==1&&s2==s0){
                student stt;
                stt.ID = vec[j];
                stt.scores = vec0[j];
                ste.push_back(stt);
            }else if(num==2&&s3==s0){
                kaochangrenshu++;
                zongscores += vec0[j];
            }else if(num==3&&s0==s6){
                mp[s3] += 1;
            }
        }
        cout<<"Case "<<(i+1)<<": "<<num<<" "<<s0<<endl;
        if(num==1){
            if(ste.size()==0){
                cout<<"NA"<<endl;
                continue;
            }
            sort(ste.begin(), ste.end(), compare_firstly);
            for(m = 0; m < ste.size(); m++){
                cout<<ste[m].ID<<" "<<ste[m].scores<<endl;
            }
        }else if(num==2){
            if(kaochangrenshu==0&&zongscores==0){
                cout<<"NA"<<endl;
                continue;
            }
            cout<<kaochangrenshu<<" "<<zongscores<<endl;
        }
        else if(num==3){
            for(auto it=mp.begin(); it!=mp.end(); it++){
                datettime dtt;
                dtt.ID = it->first;
                dtt.num = it->second;
                dte.push_back(dtt);
            }
            if(dte.size()==0){
                cout<<"NA"<<endl;
                continue;
            }
            sort(dte.begin(), dte.end(), compare_thirdly);
            for(m = 0; m < dte.size(); m++){
                cout<<dte[m].ID<<" "<<dte[m].num<<endl;
            }
        }
    }
    return 0;
}
