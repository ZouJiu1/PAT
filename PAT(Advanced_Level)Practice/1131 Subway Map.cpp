#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
unordered_map<int, int> ump;
vector<int> v[10006], tmp, res;
int starts, endst, minmin = 999999999, quick = 999999999; 
int status[10006];
int gettransf() {
    int preline = 0, z, cnt = 0;
    for(int i = 1; i < tmp.size(); i++) {
        z = ump[tmp[i-1]*10000 + tmp[i]];
        if(preline!=z) cnt++;
        preline = z;
    }
    return cnt;
}
void recursion(int st) {
    if(endst==st && tmp.size() <= quick) {
        int num_transf = gettransf();
        if(tmp.size() < quick||
        (tmp.size() == quick && minmin > num_transf)) {
            res = tmp;
            minmin = num_transf;
            quick = tmp.size();
        }
        return;
    }
    status[st]=1;
    vector<int> small = v[st];
    for(int i = 0; i < small.size(); i++) {
        if(status[small[i]]==1) continue;
        tmp.push_back(small[i]);
        status[small[i]]=1;
        recursion(small[i]);
        tmp.pop_back();
        status[small[i]]=0;
    }
}
int main(void){
    int i, j, k, m, n, y, z, pre;
    cin>>m;
    for(i = 0; i < m; i++) {
        cin>>n;
        for(j=0; j < n; j++) {
            cin>>y;
            if(j > 0) {
                ump[pre * 10000 + y] = ump[y*10000 + pre] = i+1;
                v[pre].push_back(y);
                v[y].push_back(pre);
            }
            pre = y;
        }
    }
    cin>>n;
    for(i = 0; i < n; i++) {
        cin>>starts>>endst;
        fill(status, status+10006, 0);
        tmp.clear();
        minmin = 999999999;
        quick = 999999999;
        tmp.push_back(starts);
        recursion(starts);
        printf("%d\n", res.size() - 1);
        int preline = 0, pretransf = starts;
        for(j = 1; j < res.size(); j++) {
            z = ump[res[j-1]*10000+res[j]];
            if(z!=preline){
                if(preline!=0) printf("Take Line#%d from %04d to %04d.\n", 
                                        preline, pretransf, res[j-1]);
                preline = z;
                pretransf = res[j-1];
            }
        }
        printf("Take Line#%d from %04d to %04d.\n", preline, pretransf, res[j-1]);
    }
    return 0;
}
