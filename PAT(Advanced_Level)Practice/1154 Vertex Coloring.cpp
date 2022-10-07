#include<iostream>
#include<vector>
#include<set>
using namespace std;
int main(void) {
    int i, j, k, m, n, x1, x2;
    cin>>m>>n;
    int edgees[10006][2];
    for(i = 0; i < n; i++) scanf("%d %d", &edgees[i][0], &edgees[i][1]);
    cin>>k;
    vector<int> v(m, 0);
    for(i = 0; i < k; i++) {
        set<int> st;
        for(j = 0; j < m; j++) {
            scanf("%d", &v[j]);
            st.insert(v[j]);
        }
        x1 = 0;
        for(j = 0; j < n; j++) {
            if(v[edgees[j][0]]==v[edgees[j][1]]) {
                x1 = -9;
                break;
            }
        }
        if(x1 < 0) {
            cout<<"No"<<endl;
            continue;
        }
        printf("%d-coloring\n", st.size());
    }
    return 0;
}
