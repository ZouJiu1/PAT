#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

struct wolfes{
    int l0;
    int l2;
    int lie0;
    int lie2;
};

struct bianhao{
    int num;
    int hua;
};

struct langren{
    int l0;
    int l2;
};

int main(void){
    int n, m, num, i, j, w, counts=0;
    cin>>n;
    string s0;
    vector<int> vec, vec9;
    for(int i=0; i<n; i++){
        cin>>s0;
        num = stoi(s0);
        vec.push_back(num);
    }
    map<int, int> mp;
    vector<wolfes> wft;
    for(i=0; i<n; i++) mp[i+1] = 1;
    for(i = 0; i < n-1; i++){
        for(j = i+1; j < n; j++){
            for(w = 0; w < n; w++){
                if(w==i||w==j) continue;
                wolfes wf, wf0;
                wf.l0 = i; 
                wf0.l0 = i;
                wf.l2 = j;
                wf0.l2 = j;

                wf.lie0 = i;
                wf.lie2 = w;
                wft.push_back(wf);
                wf0.lie0 = j;
                wf0.lie2 = w;
                wft.push_back(wf0);
            }
        }
    }
    int pos;
    vector<langren> res;
    for(i = 0; i<wft.size(); i++){
        vec9 = vec;
        wolfes wf = wft[i];
        vec9[wf.lie0] = vec9[wf.lie0] * (-1);
        vec9[wf.lie2] = vec9[wf.lie2] * (-1);
        vector<bianhao> neg;
        int all[n]={1};
        for(j = 0; j < vec.size(); j++){
            if(vec9[j]<0){
                bianhao bh;
                bh.hua = vec9[j];
                bh.num = j+1;
                neg.push_back(bh);
                if(neg.size()>2) break;
            }
        }
        if(neg.size()>2) continue;
        pos = -666;
        for(j = 0; j < vec9.size(); j++){
            for(m = 0; m < vec.size(); m++){
                if(j==m) continue;
                if(abs(vec9[j])==abs(vec9[m])&&vec9[j]!=vec9[m]){
                    pos = 666;
                    break;
                }
            }
            if(pos>0) break;
        }
        if(neg.size()>2) continue;
        pos = -666;
        for(m = 0; m<neg.size(); m++) {
            if((-neg[m].hua - 1)!=wf.l0 && (-neg[m].hua - 1)!=wf.l2) {pos = -666; break;}
            else pos = 666;
        }
        for(j = 0; j < vec9.size(); j++){
            if(wf.l0==abs(vec9[j] - 1) && vec9[j]>0) {pos = -666; break;}
            else if(wf.l2==abs(vec9[j] - 1) && vec9[j]>0) {pos = -666; break;}
        }
        if(pos>0){
            langren lr;
            lr.l0 = wf.l0+1;
            lr.l2 = wf.l2+1;
            res.push_back(lr);
            break;
        }
    }
    if(res.size()==0){
        cout<<"No Solution";
        return 0;
    }
    cout<<res[0].l0<<" "<<res[0].l2<<endl;
    return 0;
}
