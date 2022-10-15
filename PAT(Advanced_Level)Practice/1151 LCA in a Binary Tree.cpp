#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int> in, pre;
unordered_map<int, int> mp, mmp;
int x1_ind, x2_ind, x1, x2;

void lca(int rootind) {
    int root = pre[rootind];
    int in_ind = mp[root];
    if((x1_ind < in_ind) && (x2_ind > in_ind) || 
       (x1_ind > in_ind) && (x2_ind < in_ind))
        printf("LCA of %d and %d is %d.\n", x1, x2, root);
    else if(x1_ind==in_ind) 
        printf("%d is an ancestor of %d.\n", x1, x2);
    else if(x2_ind==in_ind)
        printf("%d is an ancestor of %d.\n", x2, x1);
    else if((x1_ind < in_ind && x2_ind < in_ind) ||
            (x1_ind > in_ind && x2_ind > in_ind))
        lca(rootind + 1);
}

int main(void) {
    int i, j, k, m, n;
    cin>>m>>n;
    in.resize(n + 1);
    pre.resize(n + 1);
    for(i = 0; i < n; i++) {
        scanf("%d", &in[i]);
        mp[in[i]] = i;
        mmp[in[i]] = 9;
    }
    for(i = 0; i < n; i++) scanf("%d", &pre[i]);
    for(i = 0; i < m; i++) {
        int mr1 = -9, mr2 = -9;
        scanf("%d %d", &x1, &x2);
        x1_ind = mp[x1];
        x2_ind = mp[x2];
        if(mmp[x1]+0 == 0) mr1 = 9;
        if(mmp[x2]+0 == 0) mr2 = 9;
        if(mr1 > 0 && mr2 > 0) {
            printf("ERROR: %d and %d are not found.\n", x1, x2);
        } else if(mr1 > 0 && mr2 < 0) {
            printf("ERROR: %d is not found.\n", x1);
        } else if(mr1 < 0 && mr2 > 0) 
            printf("ERROR: %d is not found.\n", x2);
        else lca(0);
    }
    return 0;
}
