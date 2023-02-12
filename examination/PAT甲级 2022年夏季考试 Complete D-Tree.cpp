0开始公式更方便记忆

0开始  dx ~ dx+d

1开始   dx – (d-2) ~ dx+1
1、0开始  dx ~ dx+d

    index     从0开始

          0            0  

        1   2       1  2  3

    d=2 x=0   子节点：1 2  2x+1  2x+2

    d=3 x=0   子节点：1 2 3  dx+1  dx+2  dx+d

    同样可以用子节点的index拿到父节点的index

    d=2      x = 2   父节点：(2-1)//2 = 0

    d = 3    x = 3   父节点：(3-1)//d = 0

不记录父节点
#include<iostream>
#include<vector>
using namespace std;
int arr[60], d, cnt = 0, level[100], N;
void depth_first_recursion(int tat) {
    if(tat >= N) return;
    level[tat] = arr[cnt++];
    for(int i = d * tat + 1; i <= d * tat + d; i++) {
        depth_first_recursion(i);
    }
}
int main(void) {
    int i, j, k, M, K, n, m;
    cin>>N>>d;
    for(i = 0; i < N; i++) scanf("%d", &arr[i]);
    depth_first_recursion(0);
    vector<int> v;
    for(i = 0; i < N; i++) printf("%d%s", level[i], i==N-1? "\n":" ");
    cin>>K;
    for(i = 0; i < K; i++) {
        cin>>m;
        v.clear();
        while(true) {
            v.push_back(m);
            if(m==0) break;
            m = (m - 1) / d;
        }
        for(j = 0; j < v.size(); j++) printf("%d%s", level[v[j]], j==v.size()-1? "\n":" ");
    }
    return 0;
}

记录父节点
#include<iostream>
#include<vector>
using namespace std;
int arr[60], d, cnt = 0, level[100][2], N;
void depth_first_recursion(int tat, int father) {
    if(tat >= N) return;
    level[tat][0] = arr[cnt++];
    level[tat][1] = father;
    for(int i = d * tat + 1; i <= d * tat + d; i++) {
        depth_first_recursion(i, tat);
    }
}
int main(void) {
    int i, j, k, M, K, n, m;
    cin>>N>>d;
    for(i = 0; i < N; i++) scanf("%d", &arr[i]);
    depth_first_recursion(0, -1);
    vector<int> v;
    for(i = 0; i < N; i++) printf("%d%s", level[i][0], i==N-1? "\n":" ");
    cin>>K;
    for(i = 0; i < K; i++) {
        cin>>m;
        v.clear();
        while(true) {
            v.push_back(m);
            if(m==0) break;
            m = level[m][1];
        }
        for(j = 0; j < v.size(); j++) printf("%d%s", level[v[j]][0], j==v.size()-1? "\n":" ");
    }
    return 0;
}

指针 gen d-树, 而且不从子节点index推父节点index直接用指针
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int arr[60], d, cnt = 0, level[100], N;
struct nod{
    nod* child[10]={NULL};
    nod* father;
    int val;
};
unordered_map<int, nod*> ump;
nod* depth_first_recursion(int tat, nod* father, nod* rot) {
    if(tat >= N) return NULL;
    level[tat] = arr[cnt++];
    if(rot==NULL) {
        rot =new(nod);
        rot->father = father;
        rot->val = level[tat];
        ump[level[tat]] = rot;
    }
    int num = 0;
    for(int i = d * tat + 1; i <= d * tat + d; i++) {
        rot->child[num] = depth_first_recursion(i, rot, rot->child[num]);
        num++;
    }
    return rot;
}
int main(void) {
    int i, j, k, M, K, n, m;
    cin>>N>>d;
    for(i = 0; i < N; i++) scanf("%d", &arr[i]);
    nod *rot = NULL;
    rot = depth_first_recursion(0, NULL, rot);
    vector<int> v;
    for(i = 0; i < N; i++) printf("%d%s", level[i], i==N-1? "\n":" ");
    cin>>K;
    for(i = 0; i < K; i++) {
        cin>>m;
        v.clear();
        nod *nd = ump[level[m]];
        while(true) {
            v.push_back(nd->val);
            if(nd->father==NULL) break;
            nd = nd->father;
        }
        for(j = 0; j < v.size(); j++) printf("%d%s", v[j], j==v.size()-1? "\n":" ");
    }
    return 0;
}

2、1开始   dx – (d-2) ~ dx+1

    index     从1开始

          1            1  

        2   3       2  3  4

    d=2 x=1   子节点：2 3  2x+(2-2):2x  2x+(2-2)+1:2x+1

    d=3 x=1   子节点：2 3 4 d*x - (d-2) dx-(d-2)+1 ...  dx+1...   子节点index

    同样可以用子节点的index拿到父节点的index

    d=2      x = 3   父节点：3+(2-2)//2 = 1

    d = 3    x = 3   父节点：3+(d-2)//d = 1

不记录父节点
#include<iostream>
#include<vector>
using namespace std;
int arr[60], d, cnt = 0, level[100], N;
void depth_first_recursion(int tat) {
    if(tat > N) return;
    level[tat] = arr[cnt++];
    for(int i = d * tat - (d - 2); i <= d * tat + 1; i++) {
        depth_first_recursion(i);
    }
}
int main(void) {
    int i, j, k, M, K, n, m;
    cin>>N>>d;
    for(i = 0; i < N; i++) scanf("%d", &arr[i]);
    depth_first_recursion(1);
    vector<int> v;
    for(i = 1; i <= N; i++) printf("%d%s", level[i], i==N? "\n":" ");
    cin>>K;
    for(i = 0; i < K; i++) {
        cin>>m;
        v.clear();
        m++;
        while(true) {
            if(m==0) break;
            v.push_back(m);
            m = (m + (d - 2)) / d;
        }
        for(j = 0; j < v.size(); j++) printf("%d%s", level[v[j]], j==v.size()-1? "\n":" ");
    }
    return 0;
}

记录父节点
#include<iostream>
#include<vector>
using namespace std;
int arr[60], d, cnt = 0, level[100][2], N;
void depth_first_recursion(int tat, int father) {
    if(tat > N) return;
    level[tat][0] = arr[cnt++];
    level[tat][1] = father;
    for(int i = d * tat - (d - 2); i <= d * tat + 1; i++) {
        depth_first_recursion(i, tat);
    }
}
int main(void) {
    int i, j, k, M, K, n, m;
    cin>>N>>d;
    for(i = 0; i < N; i++) scanf("%d", &arr[i]);
    depth_first_recursion(1, 0);
    vector<int> v;
    for(i = 1; i <= N; i++) printf("%d%s", level[i][0], i==N? "\n":" ");
    cin>>K;
    for(i = 0; i < K; i++) {
        cin>>m;
        v.clear();
        m++;
        while(true) {
            if(m==0) break;
            v.push_back(m);
            m = level[m][1];
        }
        for(j = 0; j < v.size(); j++) printf("%d%s", level[v[j]][0], j==v.size()-1? "\n":" ");
    }
    return 0;
}

指针 gen d-树, 而且不从子节点index推父节点index直接用指针
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int arr[60], d, cnt = 0, level[100], N;
struct nod{
    nod* child[10]={NULL};
    nod* father;
    int val;
};
unordered_map<int, nod*> ump;
nod* depth_first_recursion(int tat, nod* father, nod* rot) {
    if(tat > N) return NULL;
    level[tat] = arr[cnt++];
    if(rot==NULL) {
        rot =new(nod);
        rot->father = father;
        rot->val = level[tat];
        ump[level[tat]] = rot;
    }
    int num = 0;
    for(int i = d * tat - (d - 2); i <= d * tat + 1; i++) {
        rot->child[num] = depth_first_recursion(i, rot, rot->child[num]);
        num++;
    }
    return rot;
}
int main(void) {
    int i, j, k, M, K, n, m;
    cin>>N>>d;
    for(i = 0; i < N; i++) scanf("%d", &arr[i]);
    nod *rot = NULL;
    rot = depth_first_recursion(1, NULL, rot);
    vector<int> v;
    for(i = 1; i <= N; i++) printf("%d%s", level[i], i==N? "\n":" ");
    cin>>K;
    for(i = 0; i < K; i++) {
        cin>>m;
        v.clear();
        nod *nd = ump[level[m + 1]];
        while(true) {
            v.push_back(nd->val);
            if(nd->father==NULL) break;
            nd = nd->father;
        }
        for(j = 0; j < v.size(); j++) printf("%d%s", v[j], j==v.size()-1? "\n":" ");
    }
    return 0;
}
