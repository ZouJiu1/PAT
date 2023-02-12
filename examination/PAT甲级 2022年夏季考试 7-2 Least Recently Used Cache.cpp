1、用另一个数组记录index，这样找最小值就不用排序了
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool status[200006];
int arr[200006], index[200006];
int main(void) {
    int i, j, k, m, n=0, N, M, K, cnt=0, num=0;
    cin>>N>>M;
    fill(arr, arr + 200006, 999999999);
    fill(index, index +200006, 999999999);
    vector<int> v;
    for(i = 0; i < M; i++) {
        scanf("%d", &k);
        if(arr[k] < 100000) {   //再次访问请求
            index[arr[k]] = 999999999;
            arr[k] = cnt;
            index[cnt++] = k;
            continue;
        }
        if(num < N) {             //没访问过或者被移除了
            arr[k] = cnt;
            index[cnt++] = k;
            num++;
        } else {    // remove
            while(index[n] > 100000) n++;
            arr[index[n]] = 999999999;
            v.push_back(index[n]);
            index[n] = 999999999;
            arr[k] = cnt;
            index[cnt++] = k;
        }
    }
    for(i = 0; i < v.size(); i++) {
        printf("%d", v[i]);
        if(i!=v.size() - 1) printf(" ");
    }
    return 0;
}

2、运算符重载
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
bool status[20006];
int arr[20006];
struct nod {
    int k, cnt;
    bool operator < (const nod &a) const{
        return cnt != a.cnt? cnt < a.cnt : k < a.k;
    }
};
int main(void) {
    int i, j, k, m, n, N, M, K, cnt=1, num;
    set<nod> te;
    cin>>N>>M;
    fill(arr, arr+20006, 999999999);
    vector<int> v;
    for(i = 0; i < M; i++) {
        scanf("%d", &k);
        if(status[k]==true) {   //再次访问或者请求
            auto it = te.find({k, arr[k]});
            if(it!=te.end()) te.erase({k, arr[k]});
            te.insert({k, cnt});
            arr[k] = cnt++;
            continue;
        }
        if(num < N) {              // < N
            te.insert({k, cnt});
            arr[k] = cnt++;
            num++;
            status[k] = true;
        } else {
            for(auto it=te.begin(); it!=te.end(); it++) {
                m = it->k;
                te.erase({m, arr[m]});
                break;
            }
            arr[m] = 999999999;
            status[m] = false;
            v.push_back(m);
            te.insert({k, cnt});
            arr[k] = cnt++;
            status[k] = true;
        }
    }
    for(i = 0; i < v.size(); i++) {
        printf("%d", v[i]);
        if(i!=v.size() - 1) printf(" ");
    }
    return 0;
}
