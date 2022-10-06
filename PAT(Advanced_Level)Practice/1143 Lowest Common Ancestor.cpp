#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int main(void) { //inorder从middle找，preorder从前找，postorder从后找
    int i, j, k, m, n, x1, x2;
    cin>>m>>n;
    vector<int> vtr(n);
    unordered_set<int> st;
    for(i = 0; i < n; i++) {
        scanf("%d", &vtr[i]);
        st.insert(vtr[i]);
    }
    for(i = 0; i < m; i++) {
        int mr1 = -9, mr2 = -9;
        scanf("%d %d", &x1, &x2);
        if(st.find(x1)==st.end()) mr1 = 9;
        if(st.find(x2)==st.end()) mr2 = 9;
        for(j = 0; j < n; j++)
            if((vtr[j]<=x1 && vtr[j]>=x2) || (vtr[j]>=x1 && vtr[j]<=x2)) break;
        if(mr1 > 0 && mr2 > 0) {
            printf("ERROR: %d and %d are not found.\n", x1, x2);
        } else if(mr1 > 0 && mr2 < 0) {
            printf("ERROR: %d is not found.\n", x1);
        } else if(mr1 < 0 && mr2 > 0) 
            printf("ERROR: %d is not found.\n", x2);
        else if(vtr[j] == x1 || vtr[j]==x2) printf("%d is an ancestor of %d.\n", vtr[j], vtr[j]==x1? x2:x1);
        else printf("LCA of %d and %d is %d.\n", x1, x2, vtr[j]);
    }
    return 0;
}
