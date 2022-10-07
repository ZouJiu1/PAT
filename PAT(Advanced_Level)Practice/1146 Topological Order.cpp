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
