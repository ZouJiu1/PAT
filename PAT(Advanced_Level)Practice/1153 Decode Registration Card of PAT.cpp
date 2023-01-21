update
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;
struct nod {
    string id;
    int score;
};
bool cmp(nod &a, nod &c) {
    return a.score!=c.score? a.score > c.score : a.id < c.id;
}
int main(void) {
    int i, j, N, M, k, y, z;
    nod nd;
    vector<nod> v;
    string t;
    cin>>N>>M;
    for(i = 0; i < N; i++) {
        cin>>nd.id>>nd.score;
        v.push_back(nd);
    }
    for(i = 0; i < M; i++) {
        cin>>y>>t;
        printf("Case %d: %d %s\n", i+1, y, t.c_str());
        vector<nod> vt;
        if(y==1) {
            for(j = 0; j < N; j++) {
                if(v[j].id[0]==t[0]) vt.push_back(v[j]);
            }
        }else if(y==2) {
            int sum = 0, num = 0;
            for(j = 0; j < N; j++) {
                if(v[j].id.substr(1, 3)==t) {
                    num++;
                    sum += v[j].score;
                }
            }
            if(num!=0) printf("%d %d\n", num, sum);
            else printf("NA\n");
            continue;
        }else if(y==3) {
            unordered_map<string, int> ump;
            for(j = 0; j < N; j++) {
                if(v[j].id.substr(4, 6)==t) ump[v[j].id.substr(1, 3)]++;
            }
            for(auto it:ump) vt.push_back({it.first, it.second});
        }
        if(vt.size()==0) printf("NA\n");
        sort(vt.begin(), vt.end(), cmp);
        for(j = 0; j < vt.size(); j++) printf("%s %d\n", vt[j].id.c_str(), vt[j].score);
    }
    return 0;
}

old before
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
    int num;
};

bool compare_firstly(const student &a, const student &b){
    if(a.num == b.num){
        if(a.ID < b.ID) return true;
        else return false;
    }
    return a.num > b.num;
}

int main(void){
    int n, m, res;
    cin>>n>>m;
    vector<student> vec(n);
    for(int i=0; i<n; i++){
        cin>>vec[i].ID>>vec[i].num;
    }
    int num;
    string ID;
    for(int i=1; i<=m; i++){
        cin>>num>>ID;
        vector<student> res;
        cout<<"Case "<<i<<": "<<num<<" "<<ID<<endl;
        if(num==1){
            for(int j=0; j<vec.size(); j++){
                if(vec[j].ID[0]==ID[0]) res.push_back(vec[j]);
            }
        }else if(num==2){
            int counts=0, sum=0;
            for(int j=0; j<vec.size(); j++){
                if(vec[j].ID.substr(1, 3)==ID) {
                    counts++;
                    sum += vec[j].num;
                }
            }
            if(counts==0) cout<<"NA"<<endl;
            else cout<<counts<<" "<<sum<<endl;
        }else if(num==3){
            unordered_map<string, int> mp;
            for(int j=0; j<vec.size(); j++){
                if(vec[j].ID.substr(4, 6)==ID) mp[vec[j].ID.substr(1, 3)] += 1;
            }
            for(auto it:mp) res.push_back({it.first, it.second}) ;
        }
        sort(res.begin(), res.end(), compare_firstly);
        for(int j=0; j<res.size(); j++){
            cout<<res[j].ID<<" "<<res[j].num<<endl;
        }
        if((res.size()==0)&&(num!=2)) cout<<"NA"<<endl;
    }
    return 0;
}
