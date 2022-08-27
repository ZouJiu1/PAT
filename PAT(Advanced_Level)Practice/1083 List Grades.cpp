#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

struct nod{
    string nam;
    string sci;
    int score;
};
nod nd;

bool compare(nod &a, nod &c){
    if(a.score > c.score) return true;
    else return false;
}

int main(void){
    int i, j, k, m, n, w, x, y;
    cin>>n;
    vector<nod> v, v0;
    for(i = 0; i < n; i++){
        cin>>nd.nam>>nd.sci>>nd.score;
        v.push_back(nd);
    }
    sort(v.begin(), v.end(), compare);
    cin>>x>>y;
    w = -999;
    for(i = 0; i < n; i++){
        if(v[i].score>=x&&v[i].score<=y){
            w = 999;
            cout<<v[i].nam<<" "<<v[i].sci<<endl;
        }
    }
    if(w < 0)
        cout<<"NONE";
    return 0;
}
