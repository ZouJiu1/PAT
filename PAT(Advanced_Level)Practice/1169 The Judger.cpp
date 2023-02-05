后序输入的数字，和之前的某个数字之和要在序列里，也就是序列里两个数字的sub要=输入的数字，用加号判断会方便些
然后就是不能和之前的重复 

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std; //不能重复是dif
int arr[13][1006], status[13], num[100000];
int main(void) {
    int i, j, k, N, M, K, y, z, t0, t1, mr = 9, cnt = 0, sum=0;
    unordered_map<int, int> ump;
    cin>>num[cnt++]>>num[cnt++];
    ump[num[0]] = 1;
    ump[num[1]] = 1;
    cin>>N>>M;
    for(i = 0; i < N; i++) {
        for(j = 0; j < M; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for(j = 0; j < M; j++) {
        for(i = 0; i < N; i++) {
            if(status[i]==1) continue;
            int mr = -9;
            if(ump[arr[i][j]]==0) {
                for(int ij = 0; ij < cnt; ij++) {
                    y = arr[i][j] + num[ij];
                    if(ump[y]==1 && y!=num[ij]) {
                        mr = 9;
                        break;
                    }
                }
            }
            if(mr < 0 || ump[arr[i][j]]==1) {
                printf("Round #%d: %d is out.\n", j+1, i+1);
                status[i] = 1;
                sum++;
            } else {
                num[cnt++] = arr[i][j];
                ump[arr[i][j]] = 1;
            }
        }
    }
    if(sum==N) printf("No winner.\n");
    else{
        vector<int> v;
        for(i = 0; i < N; i++) {
            if(status[i]==0) v.push_back(i+1);
        }
        printf("Winner(s): ");
        for(i = 0; i < v.size(); i++) {
            printf("%d", v[i]);
            if(i!=v.size() - 1) printf(" ");
        }
    }
    return 0;
}
