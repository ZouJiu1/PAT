/*注意vector sort的使用 */

#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

typedef struct _student{
    string ID;
    string name;
    int score;
}student;

bool compare1(const student &h, const student &k){
    if(h.ID < k.ID) return true;
    else return false;
}

bool compare2(const student &h, const student &k){
    if(h.name < k.name) return true;
    else if(h.name == k.name){
        if(h.ID < k.ID) return true;
        else return false;
    }
    else return false;
}

bool compare3(const student &h, const student &k){
    if(h.score < k.score) return true;
    else if(h.score == k.score){
        if(h.ID < k.ID) return true;
        else return false;
    }
    else return false;
}

int main(int argc, char **argv){
    int i, j, a, c, m, n;
    cin>>m>>n;
    vector<student> v;
    student stt;
    for(i = 0; i < m; i++){
        cin>>stt.ID>>stt.name>>stt.score;
        v.push_back(stt);
    }
    if(n==1) sort(v.begin(), v.end(), compare1);
    else if(n==2) sort(v.begin(), v.end(), compare2);
    else sort(v.begin(), v.end(), compare3);
    for(i = 0; i < m; i++)
        cout<<v[i].ID<<" "<<v[i].name<<" "<<v[i].score<<endl;
    return EXIT_SUCCESS;
}
