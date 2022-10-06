#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

int main(void) {
    int i, j, k, m, n, num;
    cin>>m>>n;
    num = m;
    int x1, x2;
    int matrix[206][206];
    for(i = 0; i < 206; i++) {
        for(j = 0; j < 206; j++) {
            matrix[i][j] = 0;
        }
    }
    for(i = 0; i < n; i++) {
        cin>>x1>>x2;
        matrix[x1][x2] = matrix[x2][x1] = 9;
    }
    cin>>n;
    vector<vector<int>> v;
    vector<set<int>> vet;
    v.resize(n);
    vet.resize(n);
    for(i = 0; i < n; i++) {
        cin>>m;
        for(j = 0; j < m; j++) {
            cin>>x1;
            v[i].push_back(x1);
            vet[i].insert(x1);
        }
    }
    int mr;
    vector<int> vt;
    for(i = 0; i < n; i++) {
        mr = -9;
        vt = v[i];
        for(j = 0; j < vt.size() - 1; j++) {
            x1 = vt[j];
            for(k = j + 1; k < vt.size(); k++) {
                if(matrix[x1][vt[k]] == 0) {
                    mr = 9;
                    break;
                }
            }
            if(mr == 9) break;
        }
        if(mr == 9) {
            cout<<"Not a Clique"<<endl;
            continue;
        }
        set<int> tmp;
        tmp = vet[i];
        int kkk = -9;
        for(j = 1; j <= num; j++) {
            if(tmp.find(j)!=tmp.end()) continue;
            mr = -9;
            for(k = 0; k < vt.size(); k++) {
                x1 = vt[k];
                if(matrix[j][x1] == 0) {
                    mr = 9;
                    break;
                }
            }
            if(mr < 0) {
                kkk = 9;
                break;
            }
            if(mr == 9) continue;
        }
        if(kkk == 9) {
            cout<<"Not Maximal"<<endl;
        }else cout<<"Yes"<<endl;
    }
    return 0;
}
