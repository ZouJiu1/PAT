不想超时加内存，不要因内存而导致耗时变多
尽量不要使用map，set遍历，速度会很慢，直接用大数组，vector<vector<int>>推荐，不推荐vector<set<int>>！ 
Map或者set的嵌套循环比for嵌套循环更慢
所以尽量用数组存储, 多使用status数组来判断状态
考试用vector<set<int>>来存数组超时了，最开始最后两个测试点内存也超了

vector版本 
#include<iostream>
#include<vector>
#include<set>
using namespace std;
vector<int> ind;
bool status[10006];
int main(void) {
    int i, j, k, m, n, N, M, T, x, y, z, maxmax = -999999999;
    cin>>N>>T;
    vector<int> indeg(N+1, 0), outdeg(N+1, 0);
    vector<vector<int>> st(N+1);
    for(i = 1; i <= N; i++) {
        scanf("%d", &k);
        for(j = 0; j < k; j++) {
            scanf("%d", &y);
            st[y].push_back(i);
            outdeg[i]++;
            indeg[y]++;
        }
    }
    for(i = 1; i <= N; i++) {
        if(indeg[i]/(float)outdeg[i] >= T) {
            ind.emplace_back(i);
            status[i] = true;
        }
    }
    vector<int> res(ind.size(), 0), tp;
    for(i = 0; i < ind.size(); i++) {
        for(j = 0; j < st[ind[i]].size(); j++) {
            if(status[st[ind[i]][j]]==true) {
                res[i]++;
            }
        }
        if(maxmax < res[i]) maxmax = res[i];
    }
    for(i = 0; i < res.size(); i++) {
        if(res[i]==maxmax) tp.emplace_back(ind[i]);
    }
    for(i = 0; i < tp.size(); i++) {
        printf("%d", tp[i]);
        if(i!=tp.size() - 1) printf(" ");
    }
    return 0;
}

set版本
#include<iostream>
#include<vector>
#include<set>
using namespace std;
vector<int> ind;
bool status[100006];
int main(void) {
    int i, j, k, m, n, N, M, T, x, y, z, maxmax = -999999999;
    cin>>N>>T;
    vector<int> indeg(N+1, 0), outdeg(N+1, 0);
    vector<set<int>> rev(N+1);
    for(i = 1; i <= N; i++) {
        scanf("%d", &k);
        for(j = 0; j < k; j++) {
            scanf("%d", &y);
            rev[i].insert(y);
            outdeg[i]++;
            indeg[y]++;
        }
    }
    for(i = 1; i <= N; i++) {
        if(indeg[i]/(float)outdeg[i] >= T) {
            ind.emplace_back(i);
            status[i] = true;
        }
    }
    vector<int> res(N+1, 0), tp;
    for(i = 0; i < ind.size(); i++) {
        m = ind[i];
        for(auto it:rev[ind[i]]) {
            if(status[it]==true) {
                res[it]++;
            }
        }
    }
    for(i = 0; i < ind.size(); i++) {
        if(maxmax < res[ind[i]]) maxmax = res[ind[i]];
    }
    for(i = 0; i < ind.size(); i++) {
        if(res[ind[i]]==maxmax) tp.emplace_back(ind[i]);
    }
    for(i = 0; i < tp.size(); i++) {
        printf("%d", tp[i]);
        if(i!=tp.size() - 1) printf(" ");
    }
    return 0;
}

提交的超时版本
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
vector<int> ind;
bool status[10006];
int main(void) {
    int i, j, k, m, n, N, M, T, x, y, z, maxmax = -999999999;
    cin>>N>>T;
    vector<int> indeg(N+1, 0), outdeg(N+1, 0);
    vector<unordered_set<int>> st(N+1);
    for(i = 1; i <= N; i++) {
        scanf("%d", &k);
        for(j = 0; j < k; j++) {
            scanf("%d", &y);
            st[y].insert(i);
            outdeg[i]++;
            indeg[y]++;
        }
    }
    for(i = 1; i <= N; i++) {
        if(indeg[i]/(float)outdeg[i] >= T) {
            ind.emplace_back(i);
            status[i] = true;
        }
    }
    vector<int> res(ind.size(), 0), tp;
    for(i = 0; i < ind.size(); i++) {
        for(auto it : st[ind[i]]) {
            if(status[it]==true) {
                res[i]++;
            }
        }
        if(maxmax < res[i]) maxmax = res[i];
    }
    for(i = 0; i < res.size(); i++) {
        if(res[i]==maxmax) tp.emplace_back(ind[i]);
    }
    for(i = 0; i < tp.size(); i++) {
        printf("%d", tp[i]);
        if(i!=tp.size() - 1) printf(" ");
    }
    return 0;
}
