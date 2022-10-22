update
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
#include<cmath>
using namespace std;
int mat[1016][1016], inf = 999999999, status[1016], dis[1016], i, j, k, y, m, n, mr, house, g, route, limit, z5, z6, minmin;
string t1, t2;
unordered_map<string, int> mp;
unordered_map<int, string> rmp;
struct nod {
    int sum, alp;   
    float avg, min;};
bool compare(nod &a, nod &c) {
    if(a.min > c.min) return true;
    else if(a.min==c.min){
        if(a.avg < c.avg) return true;
        else return a.alp < c.alp;
    }else return false;
}
int main(void){
    cin>>house>>g>>route>>limit;
    nod nd;
    fill(mat[0], mat[0] + 1016 * 1016, inf);
    for(i = 1; i <= g; i++) {
        mp["G" + to_string(i)] = i + house;
        rmp[i + house] = "G" + to_string(i);
    }
    for(i = 0; i < route; i++) {
        cin>>t1>>t2>>m;
        if(t1[0]=='G')  z5 = mp[t1];
        else z5 = stoi(t1);
        if(t2[0]=='G') z6 = mp[t2];
        else z6 = stoi(t2);
        mat[z5][z6] = mat[z6][z5] = m;
    }
    vector<nod> v;
    for(i = house+1; i <=house+ g; i++) {
        fill(status, status+1016, 0);
        fill(dis, dis+1016, inf);
        dis[i] = 0;
        for(j = 1; j <= g + house; j++) {
            minmin = inf;
            for(k = 1; k <= g+house; k++) {
                if(status[k]==0 && minmin > dis[k]){
                    minmin = dis[k];
                    z6 = k;
                }
            }
            status[z6] = 1;
            for(k = 1; k <= g+house; k++) {
                if(status[k]==0&&dis[k] > dis[z6] + mat[z6][k])
                    dis[k] = dis[z6] + mat[z6][k];
            }
        }
        mr = -9;
        nd.sum = 0;
        minmin = inf;
        for(j = 1; j <=house; j++) {
            if(dis[j] > limit) {
                mr = 9;
                break;
            }
            nd.sum += dis[j];
            if(minmin > dis[j]) minmin = dis[j];
        }
        if(mr < 0) {
            nd.alp = i;
            nd.avg = nd.sum/(float)house;
            nd.min = (float)minmin;
            v.push_back(nd);
        }
    }
    if(v.size()==0) {
        cout<<"No Solution\n";
        return 0;
    }
    sort(v.begin(), v.end(), compare);
    cout<<rmp[v[0].alp]<<endl;
    printf("%.1f %.1f\n", v[0].min, round(v[0].avg*10)/(float)10.0);
    return 0;
}



before old
/*
迪杰特斯拉算法，gas station地点要满足几个条件

要注意的是几个待选点和居民点都是现实存在的，所以待选点也要看作节点，计算最短路径的时候要用到待选点

i. 待选点到最近的居民住房的距离要尽可能地远，就是算法计算出的最短距离里的最小值要尽可能地大， 然后再根据待选点到居民点的最短总距离以及待选点编号排序
*/

#include<iostream>
#include<vector>
#include<map>
#include<bits/stdc++.h>

using namespace std;
struct nodes{
    string s;
    int sum;
    int minval;
};
bool compare(const nodes&a, const nodes&c){
    if(a.minval > c.minval) return true;
    else if(a.minval==c.minval&&a.sum==c.sum){
        if(a.s < c.s) return true;
        else return false;
    }
    else if(a.minval==c.minval){
        if(a.sum < c.sum) return true;
        else return false;
    }
    else return false;
}
int main(void){
    int i, j, x, y, z, kk;
    int N, M, K, D;
    string s0, s1, tmp="G";
    cin>>N>>M>>K>>D;
    int infff = 2139062143;
    map<string, int> mp;
    map<int, string> mp0;
    for(i = 1; i <= 10; i++){
        tmp += to_string(i);
        mp[tmp] = i;
        mp0[i]  = tmp;
        tmp = "G";
    }
    // int matrix[1016][1016];
    int *matrix[1016];
    for(i = 0; i<1016; i++){
        matrix[i] = (int *)malloc(sizeof(int)*1016);
        memset((void *)matrix[i], infff, sizeof(int) * 1016);
    }
    // memset((void *)matrix[i], infff, sizeof(int) * 1016 * 1016);
    for(i = 0; i < K; i++){
        cin>>s0>>s1>>x;
        if(s0[0]=='G') y = mp[s0] + N;
        else y = stoi(s0);
        if(s1[0]=='G') z = mp[s1] + N;
        else z = stoi(s1);
        matrix[y][z] = matrix[z][y] = x;
    }
    bool status[N+M+1];
    int dis[N+M+1];
    nodes nd;
    vector<nodes> vec;
    for(i = 1; i <= M; i++){
        memset((void *)dis, infff, sizeof(int) * (N+M+1));
        memset((void *)status, false, sizeof(bool) * (N+M+1));
        dis[N + i] = 0;
        for(j = 1; j <= N+M; j++){
            int min = infff;
            int ind;
            for(kk = 1; kk <=N+M; kk++){
                if(min > dis[kk]&&status[kk]==false){
                    min = dis[kk];
                    ind = kk;
                }
            }
            status[ind] = true;
            for(kk = 1; kk <=N+M; kk++){
                if(status[kk]==true||matrix[ind][kk]==infff) continue;
                if(dis[kk] >= matrix[ind][kk] + min){
                    dis[kk] = matrix[ind][kk] + min;
                }
            }
        }
        int mar = 999;
        nd.sum = 0;
        nd.s   = mp0[i];
        int val_min = infff;
        for(j = 1; j <= N; j++){
            if(dis[j] > D){
                mar = -999;
                break;
            }
            if(val_min > dis[j]) val_min = dis[j];
            nd.sum += dis[j];
        }
        nd.minval = val_min;
        if(mar > 0){
            vec.push_back(nd);
        }
    }
    if(vec.size()==0){
        cout<<"No Solution";
        return 0;
    }
    sort(vec.begin(), vec.end(), compare);
    cout<<vec[0].s<<endl;
    printf("%d.0 ", vec[0].minval);
    printf("%.1f", round(vec[0].sum*10/(float)N)/10.0);
    for(i = 0; i < 1016; i++)
        free(matrix[i]);
    return 0;
}
