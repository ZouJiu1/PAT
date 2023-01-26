update202301   并查集或者DFS：使用map，用数组存好set和areas，并查集路径化简对应到同一个根节点
update202301  并查集，全局变量默认自动初始化0，所以累加时只会加id处的值，其他的都是0，主要是赋值时只给id赋值了
//         mp[findfather(it)].sett += allset[it];
//         mp[findfather(it)].are += allarea[it];
//         allset[id] = Mestate;
//         allarea[id] = Areas;
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<cmath>
using namespace std;
int arr[10006], allset[10006], allarea[10006];
int findfather(int a) {
    int t = a;
    while(a!=arr[a]) a = arr[a];
    arr[t] = a;
    return a;
}
void unionjoin(int a, int c) {
    int A = findfather(a);
    int C = findfather(c);
    if(A >= C) arr[A] = C;
    else arr[C] = A;
}
struct don{
    int sett=0, are=0, num=0, id;
};
bool cmp(don &a, don &c) {
    if(a.are/(float)a.num > c.are/(float)c.num) return true;
    else if(fabs(a.are/(float)a.num - c.are/(float)c.num)<0.000000001) {
        return a.id < c.id;
    }else return false;
}
int main(void) {
    int i, j, N, id, fa, mo, k, chi, Mestate, Areas, num = 0;
    cin>>N;
    for(i = 0; i < 10006; i++) arr[i] = i;
    set<int> idcol;
    map<int, don> mp;
    for(i = 0; i < N; i++) {
        cin>>id>>fa>>mo>>k;
        if(fa!=-1) {
            unionjoin(id, fa);
            idcol.insert(fa);
        }
        if(mo!=-1) {
            unionjoin(id, mo);
            idcol.insert(mo);
        }
        for(j = 0; j < k; j++) {
            cin>>chi;
            unionjoin(id, chi);
            idcol.insert(chi);
        }
        cin>>Mestate>>Areas;
        allset[id] = Mestate;
        allarea[id] = Areas;
        idcol.insert(id);
    }
    for(auto it:idcol) {
        mp[findfather(it)].num++;
        mp[findfather(it)].id = findfather(it);
        mp[findfather(it)].sett += allset[it];
        mp[findfather(it)].are += allarea[it];
    }
    vector<don> v;
    for(auto it:mp) {v.push_back(it.second);}
    sort(v.begin(), v.end(), cmp);
    printf("%d\n", v.size());
    for(i = 0; i < v.size(); i++) {
        printf("%04d %d %.3f %.3f\n", v[i].id, v[i].num, v[i].sett/(float)v[i].num, v[i].are/(float)v[i].num);
    }
    return 0;
}

update202301  DFS，全局变量默认自动初始化0，所以累加时只会加id处的值，其他的都是0，主要是赋值时只给id赋值了
//     setal += allset[start];
//     areaal += allarea[start];
//     allset[id] = Mestate;
//     allarea[id] = Areas;
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<set>
using namespace std;
int allset[10006], allarea[10006], status[10006], setal, areaal, num, minmin;
struct don{
    int sett=0, are=0, num=0, id;
};
bool cmp(don &a, don &c) {
    if(a.are/(float)a.num > c.are/(float)c.num) return true;
    else if(a.are/(float)a.num == c.are/(float)c.num) {
        return a.id < c.id;
    }else return false;
}
vector<int> v[10006];
void recursion(int start) {
    if(status[start]==1) return;
    setal += allset[start];
    areaal += allarea[start];
    num++;
    if(minmin > start) minmin = start;
    status[start] = 1;
    for(int i = 0; i < v[start].size(); i++) {
        if(status[v[start][i]]==0) {
            recursion(v[start][i]);
        }
    }
}
int main(void) {
    int i, j, N, id, fa, mo, k, chi, Mestate, Areas;
    cin>>N;
    set<int> idcol;
    for(i = 0; i < N; i++) {
        cin>>id>>fa>>mo>>k;
        idcol.insert(id);
        if(fa!=-1) {
            v[id].push_back(fa);
            v[fa].push_back(id);
            idcol.insert(fa);
        }
        if(mo!=-1) {
            v[id].push_back(mo);
            v[mo].push_back(id);
            idcol.insert(mo);
        }
        for(j = 0; j < k; j++) {
            cin>>chi;
            v[id].push_back(chi);
            v[chi].push_back(id);
            idcol.insert(chi);
        }
        cin>>Mestate>>Areas;
        allset[id] = Mestate;
        allarea[id] = Areas;
        idcol.insert(id);
    }
    vector<don> v;
    for(auto it:idcol) {
        if(status[it]==0) {
            num = setal = areaal = 0;
            minmin = 999999999;
            recursion(it);
            v.push_back(don{setal, areaal, num, minmin});
        }
    }
    sort(v.begin(), v.end(), cmp);
    printf("%d\n", v.size());
    for(i = 0; i < v.size(); i++) {
        printf("%04d %d %.3f %.3f\n", v[i].id, v[i].num, v[i].sett/(float)v[i].num, v[i].are/(float)v[i].num);
    }

    return 0;
}

old before
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<bits/stdc++.h>

using namespace std;

int joinsearch[100000];

int findfather(int a) {
    int tmp = a;
    while(a!=joinsearch[a]) 
        a = joinsearch[a];
    joinsearch[tmp] = a;
    return a;
}

void unionjoin(int a, int c) {
    int x = findfather(a);
    int y = findfather(c);
    joinsearch[y] = x; 
}

struct nod{
    int minmin;
    int count;
    float sum0;
    float sum1;
};

bool compare(struct nod &a, struct nod &c) {
    if(a.sum1 > c.sum1) return true;
    else if(a.sum1==c.sum1) {
        if(a.minmin < c.minmin) return true;
        else return false;
    }
    else return false;
}

int main(void) {
    int i, j, k, m, n;
    for(i = 0; i < 100000; i++) 
        joinsearch[i] = i;
    cin>>n;
    int x1, x2, x3, x6, x9, x10;
    set<int> st;
    map<int, vector<int>> mp;
    for(i = 0; i < n; i++) {
        cin>>x1>>x2>>x3>>m;
        if(x2!=-1)
            unionjoin(x2, x1);
        if(x3!=-1)
            unionjoin(x3, x1);
        st.insert(x1);
        st.insert(x2);
        st.insert(x3);
        // cout<<joinsearch[x1]<<" ";
        // if(x2!=-1)
        //     cout<<joinsearch[x2]<<" ";
        // if(x3!=-1)
        //     cout<<joinsearch[x3];
        // cout<<endl;
        for(j = 0; j < m; j++) {
            cin>>x6;
            st.insert(x6);
            unionjoin(x1, x6);
            // cout<<joinsearch[x6]<<endl;
        }
        cin>>x6>>x9;
        mp[x1].push_back(x6);
        mp[x1].push_back(x9);
    }
    vector<int> vtr;
    for(set<int>::iterator it=st.begin(); it!=st.end(); it++) {
        if(*it==-1) continue;
        vtr.push_back(*it);
    }
    int cnt = 0;
    set<int> vt;
    for(i = 0; i < vtr.size(); i++) {
        if(vtr[i]==findfather(vtr[i])) {
            vt.insert(findfather(vtr[i]));
        }
        // cout<<vtr[i]<<"-->"<<joinsearch[vtr[i]]<<"-->"<<findfather(vtr[i])<<endl;
    }
    vector<struct nod> rtv;
    cnt = 0;
    struct nod nd;
    for(set<int>::iterator it = vt.begin(); it!=vt.end(); it++) {
        int minmin = 9999999;
        int sum0=0, sum1=0, count = 0;
        for(j = 0; j < vtr.size(); j++) {
            if(findfather(vtr[j])==*it) {
                if(minmin > vtr[j]) {
                    minmin = vtr[j];
                }
                count++;
                if(mp[vtr[j]].size() > 0) {
                    sum0 += mp[vtr[j]][0];
                    sum1 += mp[vtr[j]][1];
                }
            }
        }
        nd.minmin = minmin;
        nd.count = count;
        nd.sum0 = sum0/(float)count;
        nd.sum1 = sum1/(float)count;
        rtv.push_back(nd);
    }
    sort(rtv.begin(), rtv.end(), compare);
    cout<<rtv.size()<<endl;
    for(i = 0; i < rtv.size(); i++) {
        printf("%04d %d %.3f %.3f\n", rtv[i].minmin, 
            rtv[i].count, rtv[i].sum0,
            rtv[i].sum1);
    }
    return 0;
}
update1
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
int arr[100000];
struct nod{int num, areas, person;};
struct nod2{
    float avgnum=0, avgarea=0;
    int person=0, num=0;
};
int findfather(int a){
    int tmp = a;
    while(arr[a]!=a) a=arr[a];
    arr[tmp] = a;
    return a;
}
void unionjoin(int a, int c) {
    int aa = findfather(a);
    int cc = findfather(c);
    if(aa > cc) arr[aa] = cc;
    else arr[cc] = aa;
}
bool compare(nod2 a, nod2 c) {
    if(a.avgarea > c.avgarea) return true;
    else if(abs(a.avgarea - c.avgarea) < 0.0000001) {
        return a.person < c.person;
    }else return false;
}
int main(int argc, char **argv) {
    int i, j, k, m, n, y, z, p0, p1, num, areas;
    for(i = 0; i < 100000; i++) arr[i] = i;
    cin>>m;
    nod nd;
    vector<int> all;
    map<int, nod> nda;
    set<int> st;
    for(i = 0; i < m; i++) {
        vector<int> vec;
        cin>>z>>p0>>p1>>n;
        nd.person = z;
        vec.push_back(z);
        if(p0!=-1) vec.push_back(p0);
        if(p1!=-1) vec.push_back(p1);
        for(j = 0; j < n; j++) {
            cin>>y;
            vec.push_back(y);
        }
        cin>>num>>areas;
        nd.num = num;
        nd.areas = areas;
        nda[nd.person] = nd;
        sort(vec.begin(), vec.end());
        for(j=0; j < vec.size() - 1; j++) {
            unionjoin(vec[j], vec[j+1]);
            // all.push_back(vec[j]);
            st.insert(vec[j]);
        }
        // all.push_back(vec[vec.size() - 1]);
        st.insert(vec[vec.size() - 1]);
    }
    y = 0;
    nod2 nd2={0};
    map<int, int> mp0, mp1, mp2;
    int w;
    for(set<int>::iterator it=st.begin(); it!=st.end(); it++){
        w = *it;
        if(findfather(w)==w) y++;
        z = findfather(w);
        mp0[z]++;
        mp1[z] += nda[w].num;
        mp2[z] += nda[w].areas;

    }
    vector<nod2> vv;
    for(map<int, int>::iterator it=mp0.begin(); it!=mp0.end(); it++) {
        nd2.person = it->first;
        nd2.num = mp0[it->first];
        nd2.avgnum = mp1[it->first] / (float)nd2.num;
        nd2.avgarea = mp2[it->first] / (float)nd2.num;
        vv.push_back(nd2);
    }
    sort(vv.begin(), vv.end(), compare);
    printf("%d\n", vv.size());
    for(i = 0; i < vv.size(); i++) {
        printf("%04d %d %.3f %.3f\n", vv[i].person, vv[i].num, vv[i].avgnum, vv[i].avgarea);
    }
    return 0;
}
