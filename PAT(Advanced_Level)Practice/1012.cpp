/*
立纵向列表A、C、M、E，保存数值的，然后从大到小排序
先要找到在A、C、M、E的排名，然后找出最小值也就是排名最好的位置，根据最小值依次找A、C、M、E，由于A>C>M>E，优先级，所以等于最小值就可以停止
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;
struct student{
    int A;
    int C;
    int M;
    int E;
    int max;
    char mar;
    string ID;
};
bool compare(const int &a, const int &b){
    if(a>b) return true;
    else return false;
}
int main(void){
    int a, b, c, i, j, k, m, n;
    cin>>n>>m;
    vector<int> vec, ve0, ve2, ve3, ve6, ve9;
    vector<student> stdent;
    string s0, s2, s3;
    student stt;
    int numbers[4], avg=0, sum=0, max;
    set<string> st;
    map<string, int> mp;
    for(i = 0; i < n; i++){
        cin>>stt.ID>>stt.C>>stt.M>>stt.E;
        mp[stt.ID] = i;
        ve0.push_back(stt.C);
        ve2.push_back(stt.M);
        ve3.push_back(stt.E);
        avg = (int)round((float)(stt.C + stt.M + stt.E)/3.0);
        ve6.push_back(avg);
        stt.A = avg;
        st.insert(stt.ID);
        stdent.push_back(stt);
    }
    vector<string> vtr;
    for(i = 0; i < m; i++){
        cin>>s0;
        vtr.push_back(s0);
    }
    sort(ve0.begin(), ve0.end(), compare);
    sort(ve2.begin(), ve2.end(), compare);
    sort(ve3.begin(), ve3.end(), compare);
    sort(ve6.begin(), ve6.end(), compare);
    for(i = 0; i < m; i++){
        set<string>::iterator it = st.find(vtr[i]);
        if(it==st.end()){
            cout<<"N/A"<<endl;
            continue;
        }
        stt = stdent[mp[vtr[i]]];
        k = -666;
        int number[4];
        for(j = 0; j<ve6.size(); j++){
            if(ve6[j]==stt.A){
                k=666;
                break;
            }
        }
        number[0] = j;
        for(j = 0; j<ve0.size(); j++){
            if(ve0[j]==stt.C){
                k=660;
                break;
            }
        }
        number[1] = j;
        for(j = 0; j<ve2.size(); j++){
            if(ve2[j]==stt.M){
                k=663;
                break;
            }
        }
        number[2] = j;
        for(j = 0; j<ve3.size(); j++){
            if(ve3[j]==stt.E){
                k=669;
                break;
            }
        }
        number[3] = j;
        int min = 666;
        for(j = 0; j < 4; j++){
            if(min>number[j]){
                min = number[j];
            }
        }
        for(j = 0; j < 4; j++){
            if(min==number[j]) break;
        }
        cout<<number[j]+1;
        if(j==0) cout<<" A"<<endl;
        else if(j==1) cout<<" C"<<endl;
        else if(j==2) cout<<" M"<<endl;
        else cout<<" E"<<endl;
    }
    return 0;
    
}
