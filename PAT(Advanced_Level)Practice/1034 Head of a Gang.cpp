update
#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<string>
#include<set>
#include<algorithm>
using namespace std;
unordered_map<string, int> ump;
map<string, int> res;
unordered_map<int, string> rev;
struct nod{int y, z;};
vector<nod> v[1006];
int status[1006][1006], num_person, tat[1006], allsum[1006], ind, maxmax;
set<int> st;
void recursion(int start, int &sum) {
    tat[start] = 1;
    st.insert(start);
    for(int i = 0; i < v[start].size(); i++) {
        int y = v[start][i].y, tmp;
        if(status[start][y]==0) {
            status[start][y] = 1;
            sum += v[start][i].z;
            allsum[start] += v[start][i].z;
            allsum[y] += v[start][i].z;
            if(allsum[y] >= allsum[start] && allsum[y] > maxmax) {
                maxmax = allsum[y];
                ind = y;
            }else if(allsum[y] <= allsum[start] && allsum[start] > maxmax) {
                maxmax = allsum[start];
                ind = start;
            }
            recursion(y, sum);
        }
    }
}
int main(void) {
    int i, j, k, m, n, x, y, z, N, K, cnt = 1;
    string t0, t1;
    cin>>N>>K;
    nod nd;
    for(i = 0; i < N; i++) {
        cin>>t0>>t1>>z;
        if(ump[t0]==0) {
            ump[t0] = cnt;
            rev[cnt++] = t0;
        }
        if(ump[t1]==0) {
            ump[t1] = cnt;
            rev[cnt++] = t1;
        }
        nd.y = ump[t1];
        nd.z = z;
        v[ump[t0]].push_back(nd);
    }
    fill(status[0], status[0] + 1006 * 1006, 0);
    fill(tat, tat + 1006, 0);
    for(i = 1; i <= cnt; i++) {
        int sum = 0;
        maxmax = -999999999;
        st.clear();
        if(tat[i]==0) {
            tat[i] = 1;
            recursion(i, sum);
            if(sum > K && st.size() > 2) {
                res[rev[ind]] = st.size();
            }
        }
    }
    printf("%d\n", res.size());
    for(map<string, int>::iterator it=res.begin(); it!=res.end(); it++) {
        cout<<it->first<<" "<<it->second<<endl;
    }
    return 0;
}

old before
/* 使用set集合进行编号，然后map进行统计加和，最后遍历的时候要注意不要重复加和*/
#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<bits/stdc++.h>

using namespace std;

typedef struct _gan{
    string s;
    string s0;
    int k;
}gan;

typedef struct _save{
    string s;
    int sum;
}save;

int main(void){
    int i, j, k, m, n, t;
    cin>>m>>n;
    string s, s0, st;
    vector<string> vs;
    vector<gan> vec;
    set<string> stg;
    map<string, int> mp;
    gan gn;
    for(i = 0; i < m; i++){
        cin>>gn.s>>gn.s0>>gn.k;
        stg.insert(gn.s);
        stg.insert(gn.s0);
        vec.push_back(gn);
    }
    for(set<string>::iterator it=stg.begin(); it!=stg.end(); it++) 
        vs.push_back(*it);
    sort(vs.begin(), vs.end());
    for(i = 0; i < vs.size(); i++)
        mp[vs[i]] = i;
    short all[vs.size()][vs.size()] = {0};
    for(i = 0; i < vs.size(); i++)
        for(j = 0; j < vs.size(); j++)
            all[i][j] = 0;
    int kkk, www;
    for(i = 0; i < vec.size(); i++){
        kkk = mp[vec[i].s];
        www = mp[vec[i].s0];
        all[kkk][www] += vec[i].k;
        all[www][kkk] += vec[i].k;
    }
    int cnt = 0, sum;
    vector<save> vsr;
    save sv;
    string pre = "k";
    set<int> setall;
    set<int>::iterator it;
    for(i = 0; i < vs.size(); i++){
        it = setall.find(i);
        if(it!=setall.end()){
            continue;
        }
        sum = 0;
        cnt = 0;
        vector<int> queue;
        queue.push_back(i);
        set<int> tes;
        int maxmax = -999, kkk, ttt;
        while(queue.size()>0){
            kkk = queue[0];
            tes.insert(kkk);
            setall.insert(kkk);
            int tmp = 0;
            for(j = 0; j < vs.size(); j++){
                if(all[kkk][j]!=0){
                    cnt++;
                    tmp += all[kkk][j];
                    it = tes.find(j);
                    if(it==tes.end()){
                        queue.push_back(j);
                    }else continue;
                    sum += all[kkk][j];
                }
            }
            queue.erase(queue.begin());
            if(tmp > maxmax){
                maxmax = tmp;
                ttt = kkk;
            }
        }
        if(sum > n && tes.size()>2 && pre!=vs[ttt]){
            sv.s = vs[ttt];
            sv.sum = tes.size();
            vsr.push_back(sv);
            pre = vs[ttt];
        }
    }
    cout<<vsr.size()<<endl;
    for(i = 0; i < vsr.size(); i++){
        cout<<vsr[i].s<<" "<<vsr[i].sum<<endl;
    }
    return 0;
}
