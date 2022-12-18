#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
vector<vector<int>> v, vv, que;
bool status[1006];
int y, z;

void recursion(int st) {
    if (vv[st].size()==0||st==y) return;
    status[st] = true;
    for (int i = 0; i < vv[st].size(); i++)
        if(status[vv[st][i]] ==false&& vv[st][i]!=y) recursion(vv[st][i]);
}
int main() {
    int n, m, k, i, j;
    cin >> n >> m >> k;
    v.resize(n + 1);
    vv.resize(n + 1);
    for (i = 0; i < m; i++) {
        scanf("%d %d", &y, &z);
        vv[y].push_back(z);
        vv[z].push_back(y);
    }
    for (i = 0; i < k; i++) {
        cin >> y;
        fill(status, status + 1006, false);
        status[y] = true;
        if(y!=0) recursion(0);
        else recursion((y+1)%m);
        int res = -9;
        for (j = 0; j < n; j++) {
            if (j!= y && status[j] == false) {
                res = 9;
                break;
            }
        }
        if (res > 0) cout << "1";
        else cout << "0";
    }
    return 0;
}
