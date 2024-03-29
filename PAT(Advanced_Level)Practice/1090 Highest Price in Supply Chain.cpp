update202301  使用int层数判断是否相等，而不是判断价格double是否相等会更好
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
vector<int> arr[100006];
int maxmax = -999999999, num = 0;
void recursion(int rot, int lev) {
    if(arr[rot].size()==0) {
        if(lev > maxmax) {
            maxmax = lev;
            num = 0;
        }
        if(maxmax == lev) num++;
    }
    for(int i = 0; i < arr[rot].size(); i++) {
        recursion(arr[rot][i], lev + 1);
    }
}
int main(void) {
    int i, j, k, m, n, N, rot;
    double P, r, sum;
    cin>>N>>P>>r;
    for(i = 0; i < N; i++) {
        cin>>k;
        if(k==-1) rot = i;
        else arr[k].push_back(i);
    }
    recursion(rot, 0);
    printf("%.2f %d\n", P * pow(1+r/100.0, maxmax), num);
    return 0;
}

update
#include<vector>
#include<iostream>
using namespace std;
int m, n, k;
double pri, per, maxmax = -999999999.0;
vector<int> v[100001];
vector<double> maxpri;
void dfs(int start, double price) {
    if(v[start].size() == 0) {
        maxpri.push_back(price);
        if(price > maxmax) maxmax = price;
    }
    for(int i = 0; i < v[start].size(); i++)
        dfs(v[start][i], price * (1.0 + per));
}
int main(int argc, char **argv) {
    int i, j = 0, rt;
    cin>>n>>pri>>per;
    per = per / (double)100.0;
    for(i = 0; i < n; i++) {
        scanf("%d", &k);
        if(k!=-1) v[k].push_back(i);
        else rt = i;
    }
    dfs(rt, pri);
    for(i = 0; i < maxpri.size(); i++) {
        if(maxpri[i]==maxmax) j++;
    }
    printf("%.2f %d", maxmax, j);
    return 0;
}

old before
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
