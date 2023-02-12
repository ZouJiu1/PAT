昨晚失眠了，午睡会也没啥用思路不怎么好可以看看

#include<iostream>
#include<cmath>
#include<unordered_map>
using namespace std;
int main(void) {
    int i, j, k, m, n, N, M, K, t0[3], t1[3];
    unordered_map<int, string> ump={
                        {0, "Sunday"}, {1, "Monday"}, {2, "Tuesday"}, 
                        {3, "Wednesday"}, {4, "Thursday"}, 
                        {5,"Friday"}, {6,"Saturday"}
                        };
    unordered_map<int, string> kk={{0, "yesterday"}, {1, "today"}, {2, "tomorrow"}};
    for(i = 0; i < 3; i++) scanf("%d", &t0[i]);
    for(i = 0; i < 3; i++) scanf("%d", &t1[i]);
    for(i = 0; i < 3; i++) {
        int mr = 9;
        for(j = 0; j < 3; j++) {
            if(i > j) {
                m = t0[i] - t1[j];
                n = i - j;
            }
            else {
                m = t1[j] - t0[i];
                n =  j - i;
            }
            if(m==n || (t0[i]==6 && t1[j]==0 && j - i==1) ||
            (t1[j]==6 && t0[i]==0 && i - j==1)) {    //星期六星期日越界
                mr = -9;
                break;
            }
        }
        if(mr < 0) break;
    }
    if(i==0) cout<<ump[(t0[i]+1)%7];
    else if(i==1) cout<<ump[t0[i]];
    else if(i==2) {
        if(t0[i]==0) cout<<"Saturday";    //星期日越界
        else cout<<ump[(t0[i]-1)%7];
    }
    cout<<endl<<kk[i]<<endl<<kk[j]<<endl;
    return 0;
}
