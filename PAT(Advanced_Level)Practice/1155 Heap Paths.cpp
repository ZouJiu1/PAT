#include<iostream>
#include<vector>
using namespace std;
vector<int> pth[1006], v(1006), tmp;
int cnt = 0;
void dfs(int start, int end, vector<int> tp, int lr){
    if(start - 1 <= end && start > end && lr==0) return;
    if(start > end) {
        if(cnt > 0 && pth[cnt - 1]==tp) return;
        pth[cnt++] = tp;
        return;
    }
    tp.push_back(v[start]);
    dfs(start * 2 + 1, end, tp, 0);
    dfs(start * 2, end, tp, 1);
}
int main(void) {
    int i, j, k, m, n, maxmax = 9, minmin = 9;
    cin>>m;
    for(i = 1; i <= m; i++) scanf("%d", &v[i]);
    for(i = 2; i <= m; i++) {
        if(v[i] > v[i/2]) maxmax = -9;
        if(v[i] < v[i/2]) minmin = -9;
    }
    dfs(1, m, tmp, 0);
    for(i = 0; i < 1006; i++) {
        if(pth[i].size()==0) break;
        for(j = 0; j < pth[i].size(); j++)
            printf("%d%s", pth[i][j], j==pth[i].size()-1? "\n":" ");
    }
    if(maxmax==9) cout<<"Max Heap"<<endl;
    else if(minmin==9) cout<<"Min Heap"<<endl;
    else cout<<"Not Heap"<<endl;
    return 0;
}
