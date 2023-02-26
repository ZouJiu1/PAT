old before
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;
vector<int> s6;

void printvec(vector<int> a){
    for(int i=0; i<a.size();i++){
        cout<<a[i];
        if(i!=(a.size()-1))
            cout<<" ";
    }
    cout<<endl;
}

void max_heapify(int start, int end) {
    int dad = start;
    int son = dad * 2 + 1;
    while(son <= end) {
        if(son + 1 < end && s6[son] < s6[son + 1])
            son++;
        if(s6[dad] > s6[son]) {
            return;
        }
        else {
            swap(s6[son], s6[dad]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
    return;
}

int main(void){
    vector<int> s0, s1, s2;
    int n, num;
    bool res;
    cin>>n;
    int input[n];
    s6.resize(n);
    for(int i=0; i<n; i++){
        cin>>num;
        s0.push_back(num);
        s6[i] = num;
    }
    for(int i=0; i<n; i++){
        cin>>num;
        s1.push_back(num);
    }
    if(n==1)
    {
        cout<<"Insertion Sort"<<endl;
        cout<<s0[0];
        return 0;
    }
    s2 = s0;
    int marked = -3;
    for(int i=0; i<n-1; i++){
        if(s0[i+1]<s0[i]){
            for(int j=0; j<=i; j++){
                if(s0[j]>=s0[i+1]){
                    res = s0==s1;
                    if(marked>0){
                        cout<<"Insertion Sort"<<endl;
                        printvec(s0);
                        return 0;
                    }
                    if(res)
                        marked = 3;
                    s0.insert(s0.begin()+j, s0[i+1]);
                    s0.erase(s0.begin()+i+2);
                }
            }
        }
    }
    if(marked>0){
        cout<<"Insertion Sort"<<endl;
        printvec(s0);
        return 0;
    }
    s0=s2;
    s2.erase(s2.begin(), s2.end());
    marked = -3;
    int len = s0.size();
    for(int i = len/2 - 1; i >= 0; i--)   //create heap struct
        max_heapify(i, len - 1);
    for(int i = len - 1; i > 0; i--) { //move the largest to end and recreate heap struct
        if(marked>0){
            cout<<"Heap Sort"<<endl;
            printvec(s6);
            return 0;
        }
        if(s6==s1)
            marked = 3;
        swap(s6[0], s6[i]);
        max_heapify(0, i - 1);
        
    }
    if(marked>0){
        cout<<"Heap Sort"<<endl;
        printvec(s6);
    }
    return 0;
}

update
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> maxheapify(vector<int> arr, int start, int end) {
    int dad = start;
    int son = dad * 2 + 1;
    while(son <= end) {
        if(son + 1 <= end && arr[son+1] > arr[son]) son++;
        if(arr[dad] >= arr[son]) return arr;
        swap(arr[dad], arr[son]);
        dad = son;
        son = dad * 2 + 1;
    }
    return arr;
}
int main() {
    int i, j, m, n, k=1, z, y;
    cin>>m;
    vector<int> v1(m), v2(m);
    for(i = 0; i < m; i++) cin>>v1[i];
    for(i = 0; i < m; i++) cin>>v2[i];
    while(k < m && v2[k]>=v2[k-1]) k++; //要加=等号的
    y = k;
    while(k < m && v1[k]==v2[k]) k++;  //insertion前者是有序的，后面的和不排序的v1一致
    if(k==m) {
        printf("Insertion Sort\n");
        sort(v2.begin(), v2.begin() + y + 1);
    }else{
        printf("Heap Sort\n");
        z = m - 1;
        while(v2[z] > v2[z-1]) z--;
        swap(v2[0], v2[z]);
        v2 = maxheapify(v2, 0, z-1);
    }
    printf("%d", v2[0]);
    for(i = 1; i < m; i++) printf(" %d", v2[i]);
    return 0;
}


update202302
#include<iostream>
#include<algorithm>
using namespace std;
int arr[106], one[106];
void maxheapify(int ind, int endkk) {
    int dad = ind;
    int son = 2 * dad + 1;
    while(son <= endkk) {
        if(son + 1 <= endkk && one[son+1] > one[son]) son++;
        if(one[son] <= one[dad]) {
            return;
        }
        swap(one[dad], one[son]);
        dad = son;
        son = dad * 2 + 1;
    }
}
int main(void) {
    int i, j, k, n, m, N, M, K, x, y = 1, z;
    cin>>N;
    for(i = 0; i < N; i++) scanf("%d", &arr[i]);
    for(i = 0; i < N; i++) scanf("%d", &one[i]);
    while(y < N && one[y] >= one[y-1]) y++;
    z = y;
    while(z < N && arr[z]==one[z]) z++;
    if(z == N) {
        printf("Insertion Sort\n");
        sort(one, one + y + 1);
        for(i = 0; i < N; i++) printf("%d%s", one[i], i==N-1? "":" ");
    } else {
        printf("Heap Sort\n");
        y = N-1;
        while(one[y] >= one[0]) y--;
        swap(one[y], one[0]);
        maxheapify(0, y-1);
        for(i = 0; i < N; i++) printf("%d%s", one[i], i==N-1? "":" ");
    }
    return 0;
}
