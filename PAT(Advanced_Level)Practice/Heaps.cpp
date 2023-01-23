update
#include<iostream>
using namespace std;
int mr;
void recursion(int *ar, int index, int N) {
    if(index > N) return;
    recursion(ar, index * 2, N);
    recursion(ar, index * 2 + 1, N);
    printf("%s%d", mr!=-9? " ":"", ar[index]);
    mr = 9;
}
int main(void) {
    int i, j, k, m, n, M, N, arr[1006];
    cin>>M>>N;
    for(i = 0; i < M; i++) {
        int max = 9, min = 9;
        mr = -9;
        for(j = 1; j <= N; j++) scanf("%d", &arr[j]);
        for(k = 2; k <= N; k++) {
            if(arr[k] > arr[k/2]) max = -9;
            if(arr[k] < arr[k/2]) min = -9;
        }
        if(max==9) printf("Max Heap\n");
        else if(min==9) printf("Min Heap\n");
        else printf("Not Heap\n");
        recursion(arr, 1, N);
        printf("\n");
    }
    return 0;
}

old before
#include<iostream>
#include<string>
using namespace std;
int v[1006], n;

void postorder(int ind) {
    if(ind>n) return;
    postorder(ind * 2);
    postorder(ind * 2 + 1);
    printf("%d%s", v[ind], ind==1? "\n":" ");
}

int main(void) {
    int i, j, k, m, z;
    cin>>m>>n;
    for(i = 0; i < m; i++) {
        int max=9, min = 9;
        for(j = 1; j <= n; j++)
            scanf("%d", &v[j]);
        for(j = 2; j <= n; j++) {
            if(v[j] > v[j/2]) max = 0;
            if(v[j] < v[j/2]) min = 0; 
        }
        if(max==9) cout<<"Max Heap"<<endl;
        else if(min==9) cout<<"Min Heap"<<endl;
        else cout<<"Not Heap"<<endl;
        postorder(1);
    }
    return 0;
}
