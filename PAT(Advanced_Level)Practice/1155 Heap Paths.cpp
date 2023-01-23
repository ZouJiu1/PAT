update2

要使用i/2来遍历根节点，在递归左节点的时候送入栈，右节点可能不是叶子节点左节点也没有才是叶子节点 

#include<iostream>
#include<vector>
using namespace std;
vector<int> res[1006], v;
int N, cnt = 0;
void recursion(int index, vector<int> tmp) {
    if(index > N) {
        if(index%2==0) res[cnt++] = tmp;
        return;
    }
    tmp.push_back(v[index]);
    recursion(index * 2 + 1, tmp);
    recursion(index * 2, tmp);
}
int main(void) {
    int i, j, k, m, n, maxmax = 9, minmin = 9;
    cin>>N;
    vector<int> tmp;
    v.resize(N+1);
    for(i = 1; i <= N; i++) cin>>v[i];
    for(i = 2; i <= N; i++) {
        if(v[i] > v[i/2]) maxmax = -9;
        if(v[i] < v[i/2]) minmin = -9;
    }
    recursion(1, tmp);
    for(i = 0; i < cnt; i++) {
        for(j = 0; j < res[i].size(); j++) {
            printf("%d", res[i][j]);
            if(j!=res[i].size() - 1) printf(" ");
        }
        printf("\n");
    }
    if(maxmax==9) printf("Max Heap\n");
    else if(minmin==9) printf("Min Heap\n");
    else printf("Not Heap\n");
    return 0;
}

update

#include<iostream>
#include<vector>
using namespace std;
vector<int> res[1006], v;
int N, cnt = 0;
void recursion(int index, vector<int> tmp) {
    if(index >= N) {
        if(index%2==1) res[cnt++] = tmp;
        return;
    }
    tmp.push_back(v[index]);
    recursion(index * 2 + 2, tmp);
    recursion(index * 2 + 1, tmp);
}
int main(void) {
    int i, j, k, m, n;
    cin>>N;
    vector<int> tmp;
    v.resize(N);
    for(i = 0; i < N; i++) cin>>v[i];
    recursion(0, tmp);
    if(v[0] >= v[N-1]) m = 9;
    else m = -9;
    for(i = 0; i < cnt; i++) {
        for(j = 0; j < res[i].size(); j++) {
            printf("%d", res[i][j]);
            if(m > 0 && j!=0 && res[i][j - 1] < res[i][j]) m = -100; //存在一条路径不满足条件
            if(m < 0 && j!=0 && res[i][j - 1] > res[i][j]) m = -100;
            if(j!=res[i].size() - 1) printf(" ");
        }
        printf("\n");
    }
    if(m==9) printf("Max Heap\n");
    else if(m==-9) printf("Min Heap\n");
    else printf("Not Heap\n");
    return 0;
}

可用    for(i = 2; i <= m; i++) {
        if(v[i] > v[i/2]) maxmax = -9;
        if(v[i] < v[i/2]) minmin = -9;
    }    i/2   拿到根节点的数值 

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
