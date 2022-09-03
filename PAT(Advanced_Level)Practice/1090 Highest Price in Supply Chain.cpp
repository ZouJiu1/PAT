#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<queue>
using namespace std;

int main(void) {
    int i, j, m, rootsup, mar,tmp, samenum = 0, maxmax = -999999;
    double ori, per;
    cin>>m>>ori>>per;
    int level[m+1];
    for(i = 0; i < m+1; i++) level[i] = 0;
    vector<int> vec[m+1];
    for(i = 0; i < m; i++) {
        cin>>j;
        if(j==-1) {
            rootsup = i;
            continue;
        }
        vec[j].push_back(i);
    }
    double ratio = 1.0 + per/(double)100.0;
    double res[100003];
    res[0] = ori;
    for(i = 0; i < 100002; i++){
        res[i+1] = res[i] *  ratio;
    }
    queue<int> q;
    q.push(rootsup);
    int val;
    while(q.size()>0){
        mar = q.front();
        q.pop();
        if(vec[mar].size()==0) continue;
        tmp = level[mar] + 1;
        for(j = 0; j < vec[mar].size(); j++){
            val = vec[mar][j];
            level[val] = tmp;
            q.push(val);
        }
    }
    for(i = 0; i < m; i++)
        maxmax = max(level[i], maxmax);
    for(i = 0; i < m; i++)
        if(level[i]==maxmax)
            samenum++;
    printf("%.2f %d\n", res[maxmax], samenum);
    return 0;
}
