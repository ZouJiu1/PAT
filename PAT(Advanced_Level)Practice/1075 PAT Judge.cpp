#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;
struct nodes{
    int id;
    int sum;
    int max_score[6];
    int fullscore_num;
};
bool compare(const nodes &a, const nodes &b){
    if(a.sum==b.sum&&a.fullscore_num==b.fullscore_num){
        if(a.id < b.id) return true;
        else return false;
    }else if(a.sum==b.sum){
        if(a.fullscore_num > b.fullscore_num) return true;
        else return false;
    }else{
        if(a.sum > b.sum) return true;
        else return false;
    }
}

int main(void){
    int i, j, m, n, x, y, z, num, mar, score;
    cin>>m>>n>>x;
    int fullscore[6];
    vector<nodes> vec;
    nodes nd;
    for(i = 1; i <= n; i++){
        cin>>y;
        fullscore[i] = y;
    }
    int maxval[m+1][n+1];
    int fulval[m+1];
    int ng = -9999999;
    memset((void *)maxval, ng, sizeof(int) * (m+1) * (n+1));
    memset((void *)fulval, (int)0, sizeof(int) * (m+1));
    for(i = 1; i<=x; i++){
        cin>>num>>mar>>score;
        if(score==-1) {
            maxval[num][mar] = 0;
            continue;
        }
        if(maxval[num][mar] < score) maxval[num][mar] = score;
        if(score==fullscore[mar]) fulval[num] += 1;
    }
    for(i = 1; i <= m; i++){
        nd.sum = 0;
        nd.id  = i;
        for(j = 1; j<= n; j++){
            nd.max_score[j] = ng;
            if(maxval[i][j] >= 0){
                nd.sum += maxval[i][j];
                nd.max_score[j] = maxval[i][j];
            }
        }
        nd.fullscore_num = fulval[i];
        vec.push_back(nd);
    }
    sort(vec.begin(), vec.end(), compare);
    int rank = 1, allrank = 1;
    printf("1 %05d %d ", vec[0].id, vec[0].sum);
    for(i = 1; i <= n; i++){
        if(vec[0].max_score[i] < 0) cout<<"-";
        else cout<<vec[0].max_score[i];
        if(i!=n) cout<<" ";
    }
    cout<<endl;
    for(i = 1; i < vec.size(); i++){
        allrank++;
        if(vec[i].sum==0) continue;
        if(vec[i].sum==vec[i-1].sum)
            cout<<rank<<" ";
        else{
            rank = allrank;
            cout<<rank<<" ";
        }
        printf("%05d %d ", vec[i].id, vec[i].sum);
        for(j = 1; j <= n; j++){
            if(vec[i].max_score[j] < 0) cout<<"-";
            else cout<<vec[i].max_score[j];
            if(j!=n) cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}
