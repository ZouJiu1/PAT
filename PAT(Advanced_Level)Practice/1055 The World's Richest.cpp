#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>

using namespace std;

typedef struct {
    string nam;
    int age;
    int mon;
}worthy;

bool compare(const worthy& a, const worthy& c){
    if(a.age==c.age and a.mon==c.mon){
        if(a.nam < c.nam) return true;
        else return false;
    }else if(a.mon==c.mon){
        if(a.age < c.age) return true;
        else return false;
    }else{
        if(a.mon > c.mon) return true;
        else return false;
    }
}

int main(void){
    int i, j, k, m, n, h, mm, nn, age, mar, cnt;
    cin>>m>>n;
    vector<worthy> v;
    worthy wy;
    for(i = 0; i < m; i++){
        cin>>wy.nam>>wy.age>>wy.mon;
        v.push_back(wy);
    }
    sort(v.begin(), v.end(), compare);
    for(i = 0; i < n; i++){
        cin>>h>>mm>>nn;
        cout<<"Case #"<<i+1<<":"<<endl;
        mar = 999;
        cnt = 0;
        for(j = 0; j < m; j++){
            age = v[j].age;
            if(age >= mm && age <= nn){
                cnt++;
                if(cnt>h) break;
                cout<<v[j].nam<<" "<<v[j].age<<" "<<v[j].mon<<endl;
                mar = -999;
            }
        }
        if(mar>0){
            cout<<"None"<<endl;
        }
    }
    return 0;
}
