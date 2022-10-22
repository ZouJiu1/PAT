///update
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int status[506], dis[506], tim[506], pre[506], nodnum[506], t[506][506], w[506][506];
int i, j, m, n, k, x1, x2, x3, x4, x5;
int inf = 999999999, minmin;

int main(void) {
    cin>>m>>n;
    fill(status, status+506, 0);
    fill(dis, dis+506, inf);
    fill(t[0], t[0]+506*506, inf);
    fill(tim, tim+506, inf);
    fill(w[0], w[0]+506*506, inf);
    for(i = 0; i < n; i++) {
        scanf("%d %d %d %d %d", &x1, &x2, &x3, &x4, &x5);
        w[x1][x2] = x4;
        t[x1][x2] = x5;
        if(x3==0){
            w[x2][x1] = x4;
            t[x2][x1] = x5;
        }
    }
    cin>>x1>>x2;
    x4 = x2;
    dis[x1] = 0;
    for(i = 0; i < m; i++) pre[i] = i;
    for(i = 0; i < m; i++) {
        minmin = inf;
        for(j = 0; j < m; j++) {
            if(status[j]==0 && dis[j] < minmin) {
                minmin = dis[j];
                x3 = j;
            }
        }
        status[x3] = 1;
        for(j = 0; j < m; j++) {
            if(status[j]==0 && dis[j] > dis[x3] + w[x3][j]) {
                dis[j] = dis[x3] + w[x3][j];
                pre[j] = x3;
                tim[j] = tim[x3] + t[x3][j];
            } else if(status[j]==0 && dis[j]==dis[x3]+w[x3][j] && tim[j] > tim[x3] + t[x3][j]) {
                dis[j] = dis[x3] + w[x3][j];
                pre[j] = x3;
                tim[j] = tim[x3] + t[x3][j];
            }
        }
    }
    vector<int> v1, v2;
    while(pre[x2]!=x1) {
        v1.push_back(x2);
        x2 = pre[x2];
    }
    v1.push_back(x2);
    v1.push_back(x1);
    reverse(v1.begin(), v1.end());
    fill(status, status+506, 0);
    fill(tim, tim+506, inf);
    tim[x1] = 0;
    for(i = 0; i < m; i++) pre[i] = i;
    for(i = 0; i < m; i++) {
        minmin = inf;
        for(j = 0; j < m; j++) {
            if(status[j]==0 && tim[j] < minmin) {
                minmin = tim[j];
                x3 = j;
            }
        }
        status[x3] = 1;
        for(j = 0; j < m; j++) {
            if(status[j]==0 && tim[j] > tim[x3] + t[x3][j]) {
                nodnum[j] = nodnum[x3] + 1;
                pre[j] = x3;
                tim[j] = tim[x3] + t[x3][j];
            } else if(status[j]==0 && tim[j] == tim[x3] + t[x3][j] && nodnum[j] > nodnum[x3] + 1) {
                nodnum[j] = nodnum[x3] + 1;
                pre[j] = x3;
                tim[j] = tim[x3] + t[x3][j];
            }
        }
    }
    x2 = x4;
    while(pre[x2]!=x1) {
        v2.push_back(x2);
        x2 = pre[x2];
    }
    v2.push_back(x2);
    v2.push_back(x1);
    reverse(v2.begin(), v2.end());
    int sum0 = 0, sum1 = 0;
    for(i = 0; i < v1.size() - 1; i++){
        sum0 += w[v1[i]][v1[i+1]];
    }
    for(i = 0; i < v2.size() - 1; i++){
        sum1 += t[v2[i]][v2[i+1]];
    }
    if(v2==v1){
        printf("Distance = %d; Time = %d: ", sum0, sum1);
        for(i = 0; i < v2.size(); i++){
            cout<<v2[i];
            if(i!=v2.size()-1) cout<<" -> ";
        }
    } else {
        printf("Distance = %d: ", sum0);
        for(i = 0; i < v1.size(); i++){
            cout<<v1[i];
            if(i!=v1.size()-1) cout<<" -> ";
        }
        printf("\nTime = %d: ", sum1);
        for(i = 0; i < v2.size(); i++){
            cout<<v2[i];
            if(i!=v2.size()-1) cout<<" -> ";
        }
    }
    return 0;
}



///before
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
