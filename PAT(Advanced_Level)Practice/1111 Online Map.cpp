#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

int main(void) {
    int matrix[505][506][2];
    int i, j, k, m, n, x1, x2, x3, x4, x5;
    int infinf = 9999999;
    for(i = 0; i < 505; i++) {
        for(j = 0; j < 505; j++) {
            matrix[i][j][0] = matrix[i][j][1] = infinf;
        }
    }
    cin>>m>>n;
    for(i = 0; i < n; i++) {
        cin>>x1>>x2>>x3>>x4>>x5;
        if(x3==0){
            matrix[x2][x1][0] = matrix[x1][x2][0] = x4;
            matrix[x2][x1][1] = matrix[x1][x2][1] = x5;
        } else {
            matrix[x1][x2][0] = x4;
            matrix[x1][x2][1] = x5;
        }
    }
    int start, end;
    cin>>start>>end;
    bool status[m + 1];
    int dis[m + 1];
    int tim[m + 1];
    int timecost[m + 1];
    int prenode[m + 1];
    int nodenum[m + 1];
    memset((void *)status, false, sizeof(bool) * (m + 1));
    for(i = 0; i<m+1; i++) {
        dis[i] = infinf;
        tim[i] = infinf;
        timecost[i] = infinf;
        nodenum[i] = 1;
    }
    dis[start] = 0;
    tim[start] = 0;
    timecost[start] = 0;
    int minmin, points;
    int cnt = 0;
    for(i = 0; i < m; i++) {
        minmin = infinf;
        for(j = 0; j < m; j++) {
            if(status[j]==false && minmin > dis[j]) {
                minmin = dis[j];
                points = j;
            }
        }
        status[points] = true;
        for(j = 0; j < m; j++) {
            cnt = j;
            if(status[j] == false && dis[j] > dis[points] + matrix[points][j][0]) {
                dis[j] = dis[points] + matrix[points][j][0];
                timecost[j] = timecost[points] + matrix[points][j][1];
                prenode[j] = points;
                nodenum[j] = 0;
                while(prenode[cnt]!=start) {
                    nodenum[j]++;
                    cnt = prenode[cnt];
                }
            }
            else if(status[j] == false && dis[j] == dis[points] + matrix[points][j][0] &&
                    dis[j] != infinf) {
                if(timecost[j]!=infinf && timecost[j] > timecost[points] + matrix[points][j][1]) {
                    dis[j] = dis[points] + matrix[points][j][0];
                    timecost[j] = timecost[points] + matrix[points][j][1];
                    prenode[j] = points;
                    nodenum[j] = 0;
                    while(prenode[cnt]!=start) {
                        nodenum[j]++;
                        cnt = prenode[cnt];
                    }
                } else if (timecost[j]!=infinf && timecost[j]==timecost[points] + matrix[points][j][1]) {
                    if(nodenum[j] > nodenum[points] + 1) {
                        dis[j] = dis[points] + matrix[points][j][0];
                        timecost[j] = timecost[points] + matrix[points][j][1];
                        prenode[j] = points;
                        nodenum[j] = 0;
                        while(prenode[cnt]!=start) {
                            nodenum[j]++;
                            cnt = prenode[cnt];
                        }
                    }
                }
            }
        }
    }
    vector<int> length, times;
    cnt = end;
    int sum0 = 0, sum1 = 0;
    while(prenode[cnt]!=start) {
        length.push_back(cnt);
        cnt = prenode[cnt];
    }
    length.push_back(cnt);
    length.push_back(start);
    reverse(length.begin(), length.end());
    for(i = 0; i < length.size() - 1; i++){
        sum0 += matrix[length[i]][length[i+1]][0];
    }

    memset((void *)status, false, sizeof(bool) * (m + 1));
    minmin = infinf;
    cnt = 0;
    for(i = 0; i < m; i++) {
        minmin = infinf;
        for(j = 0; j < m; j++) {
            if(status[j]==false && minmin > tim[j]) {
                minmin = tim[j];
                points = j;
            }
        }
        status[points] = true;
        for(j = 0; j < m; j++) {
            cnt = j;
            if(status[j] == false && tim[j] > tim[points] + matrix[points][j][1]) {
                tim[j] = tim[points] + matrix[points][j][1];
                prenode[j] = points;
            }
        }
    }

    cnt = end;
    while(prenode[cnt]!=start) {
        times.push_back(cnt);
        cnt = prenode[cnt];
    }
    times.push_back(cnt);
    times.push_back(start);
    reverse(times.begin(), times.end());
    for(i = 0; i < times.size() - 1; i++){
        sum1 += matrix[times[i]][times[i+1]][1];
    }
    if(times==length){
        printf("Distance = %d; Time = %d: ", sum0, sum1);
        for(i = 0; i < times.size(); i++){
            cout<<times[i];
            if(i!=times.size()-1) cout<<" -> ";
        }
    } else {
        printf("Distance = %d: ", sum0);
        for(i = 0; i < length.size(); i++){
            cout<<length[i];
            if(i!=length.size()-1) cout<<" -> ";
        }
        printf("\nTime = %d: ", sum1);
        for(i = 0; i < times.size(); i++){
            cout<<times[i];
            if(i!=times.size()-1) cout<<" -> ";
        }
    }
    return 0;
}
