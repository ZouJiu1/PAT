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
    if(a.sum < c.sum) return true;
    else if(a.sum==c.sum){
        if(a.s < c.s) return true;
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
    int matrix[1016][1016];
    // for(i = 0; i<1016; i++){
    //     matrix[i] = (int *)malloc(sizeof(int)*1016);
    //     memset((void *)matrix[i], infff, sizeof(int) * 1016);
    // }
    memset((void *)matrix[i], infff, sizeof(int) * 1016 * 1016);
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
    memset((void *)status, false, sizeof(bool) * (N+M+1));
    memset((void *)dis, infff, sizeof(int) * (N+M+1));
    nodes nd;
    vector<nodes> vec;
    for(i = 1; i <= M; i++){
        memset((void *)dis, infff, sizeof(int) * (N+M+1));
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
    sort(vec.begin(), vec.end(), compare);
    cout<<vec[0].s<<endl;
    cout<<vec[0].minval<<" ";
    printf("%.1f", vec[0].sum/(float)N);
    return 0;
}
