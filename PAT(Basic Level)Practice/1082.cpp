#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>
using namespace std;
struct sport{
    string ID;
    int x;
    int y;
};

bool compare(const sport a, const sport b){
    int dis0, dis2;
    dis0 = a.x*a.x + a.y*a.y;
    dis2 = b.x*b.x + b.y*b.y;
    return dis0<dis2;
}
int main(void){
    int n;
    cin>>n;
    vector<sport> vec;
    for(int i=0; i<n; i++){
        sport st;
        cin>>st.ID>>st.x>>st.y;
        vec.push_back(st);
    }
    sort(vec.begin(), vec.end(), compare);
    cout<<vec[0].ID<<" "<<vec[vec.size()-1].ID;
    return 0;
}
