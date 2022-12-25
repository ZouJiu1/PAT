update1
#include<iostream>
#include<vector>
using namespace std;
int main(int argc, char **argv) {
    int i, j, m, n, y, z, k;
    cin>>m>>n;
    vector<int> arr[1001], res, ru(1001), tmp(1001);
    fill(tmp.begin(), tmp.begin() + 1001, 0);
    for(i = 0; i < n; i++) {
        cin>>y>>z;
        arr[y].push_back(z); 
        tmp[z] += 1;
    }
    cin>>y;
    for(i = 0; i < y; i++) {
        int mr = -9;
        ru = tmp;
        for(k = 0; k < m; k++) {
            cin>>z;
            if(ru[z]==0 && mr < 0) {
                for(j = 0; j < arr[z].size(); j++) {
                    ru[arr[z][j]]--;
                }
            } else if(mr < 0) {
                mr = 9;
            }
        }
        if(mr > 0) res.push_back(i); 
    }
    printf("%d", res[0]);
    for(i = 1; i < res.size(); i++) printf(" %d", res[i]);
    return EXIT_SUCCESS;
}

old version

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int main(void) {
    int i, j, k = 0, m, n;
    cin>>m>>n;
    int x1, x2;
    unordered_map<int, vector<int>> mp;
    vector<int> degree(1006, 0), deg(1006, 0);
    for(i = 0; i < n; i++) {
        cin>>x1>>x2;
        mp[x1].push_back(x2);
        degree[x2]++;
    }
    cin>>n;
    vector<int> res;
    for(i = 0; i < n; i++) {
        deg = degree;
        x2 = -9;
        for(j = 0; j < m; j++) {
            scanf("%d", &x1);   
            if(deg[x1]!=0 && x2 < 0){
                res.push_back(i);
                x2 = 9;
            } else if(x2 < 0){
                for(k = 0; k < mp[x1].size(); k++)
                    deg[mp[x1][k]]--;
            }
        }
    }
    for(i = 0; i < res.size(); i++)
        printf("%d%s", res[i], i==res.size()-1? "\n":" ");
    return 0;
}
