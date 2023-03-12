/*
set 运算符重载
两个queue都不存在
      若hq size满了，删掉最old的数字，访问次数置0
      放入historical access queue
两个queue最少之一存在
    访问次数是 < K
        update hq时间戳
    访问次数是 >= K
       删掉hq的记录
       删掉cq的记录
       若cq size 满了，删掉最old的数字，访问次数置0
       放入cache queue
*/
#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<cmath>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
int arr[100006], index[100006], arr2[100006];
struct nod {
    int val, num;
    bool operator <(const nod &a) const{
        return num < a.num;
    }
};

int main(void) {
    int i, j, k, m, n, N, M, K, inf = 999999999, cnt = 0;
    cin>>K>>N>>M;
    fill(arr, arr+100006, inf);
    fill(arr2, arr2+100006, inf);
    unordered_map<int, int> ump;
    set<nod> v;
    set<nod> c;
    for(i = 0; i < M; i++) {
        scanf("%d", &k);
        if(ump[k] > 0) {
            ump[k]++;
            if(ump[k] >= K) {
                if(v.find({k, arr[k]})!=v.end()) {
                    v.erase({k, arr[k]});
                }
                if(c.find({k, arr[k]})!=c.end()) {
                    c.erase({k, arr[k]});
                }
                if(c.size() >= N) {
                    for(auto it: c) {
                        c.erase({it.val, it.num});
                        ump[it.val] = 0;
                        break;
                    }
                } 
                ump[k]++;
                arr[k] = cnt;
                c.insert({k, cnt++});
            } else {
                v.erase({k, arr[k]});
                arr[k] = cnt;
                v.insert({k, cnt++});
            }
        } else {
            if(v.size() >= N) {
                for(auto it: v) {
                    v.erase({it.val, it.num});
                    ump[it.val] = 0;
                    break;
                }
            }
            ump[k]++;
            arr[k] = cnt;
            v.insert({k, cnt++});
        }
    }
    vector<int> r;
    for(auto it:v) {
        r.push_back(it.val);
    }
    if(v.size()==0) printf("-\n");
    else {
        for(i = 0; i < r.size(); i++) {
            printf("%d%s", r[i], i==r.size()-1? "\n":" ");
        }
    }
    r.clear();
    for(auto it:c) {
        r.push_back(it.val);
    }
    if(c.size()==0) printf("-\n");
    else {
        for(i = 0; i < r.size(); i++) {
            printf("%d%s", r[i], i==r.size()-1? "\n":" ");
        }
    }
    return 0;
}
