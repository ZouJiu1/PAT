update202302 归并排序不使用sort
rot[z] <= rot[z + 1]，要加=号，排序要注意=，sort的第二个参数是后面的一个position，不是所处的position
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main(void) {
    int i, j, m, N, M, y=0, z=0, k, pl, pr, pm, pk;
    cin>>N;
    vector<int> v, tmp, rot(N), arr(N);
    for(i = 0; i < N; i++) scanf("%d", &arr[i]);
    for(i = 0; i < N; i++) {
        scanf("%d", &rot[i]);
        v.push_back(rot[i]);
    }
    while(rot[z] <= rot[z + 1] && z + 1 < N) z++;
    k = ++z;
    while(arr[k]==rot[k] && k < N) k++;
    if(k==N) {
        printf("Insertion Sort\n");
        sort(rot.begin(), min(rot.begin() + z + 1, rot.end()));
        for(i = 0; i < N; i++) {
            printf("%d", rot[i]);
            if(i!=N-1) printf(" ");
        }
    } else {
        printf("Merge Sort\n");
        k = 1;
        int mr = -9;
        while(true) {
            k = k * 2;
            for(i = 0; i < N; i += k) {
                pl = i;
                pk = pm = min(N, i + k/2);
                pr = min(N, i + k);
                while(pl < pm && pk < pr) {
                    if(arr[pl] < arr[pk]) tmp.push_back(arr[pl++]);
                    else tmp.push_back(arr[pk++]);
                }
                while(pl < pm) tmp.push_back(arr[pl++]);
                while(pk < pr) tmp.push_back(arr[pk++]);
            }
            if(mr > 0) break;
            arr = tmp;
            if(tmp==v) mr = 9;
            if(k > N) break;
            tmp.clear();
        }
        for(i = 0; i < N; i++) {
            printf("%d", tmp[i]);
            if(i!=N-1) printf(" ");
        }
    }
    return 0;
}


update202301  直接使用的sort进行归并排序
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int arr[106], rra[106];
int main(void) {
    int i, j, y, k=1, m, mr, n, N, M;
    cin>>N;
    for(i = 0; i < N; i++) scanf("%d", &arr[i]);
    for(i = 0; i < N; i++) scanf("%d", &rra[i]);
    while(rra[k] >= rra[k-1]) k++;
    y = k;
    while(rra[y] == arr[y] && y < N) y++;
    if(y==N) {
        printf("Insertion Sort\n");
        sort(rra, rra+k+1);
        for(i = 0; i < N; i++) {
            printf("%d", rra[i]);
            if(i!=N-1) printf(" ");
        }
    } else {
        printf("Merge Sort\n");
        k = 1;
        int fl = -9;
        while(true) {
            k *= 2;
            for(i = 0; i < (int)N/k; i++)
                sort(arr + k * i, arr + k * (i + 1));
            sort(arr + k * i, arr + N);
            if(fl > 0) break;
            mr = -9;
            for(i = 0; i < N; i++) {
                if(arr[i]!=rra[i]) {
                    mr = 9;
                    break;
                }
            }
            if(mr < 0) fl = 9;
        }
        for(i = 0; i < N; i++) {
            printf("%d", arr[i]);
            if(i!=N-1) printf(" ");
        }
    }
    return 0;
}


update202302
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int arr[106], one[106];
int main(void) {
    int i, j, k, n, m, N, M, K, x, y = 1, z;
    cin>>N;
    vector<int> v0, v1, v2;
    for(i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
        v1.push_back(arr[i]);
    }
    
    for(i = 0; i < N; i++) {
        scanf("%d", &one[i]);
        v0.push_back(one[i]);
    }
    while(y < N && one[y] >= one[y-1]) y++;   // >=
    z = y;
    while(z < N && arr[z]==one[z]) z++;
    if(z == N) {
        printf("Insertion Sort\n");
        sort(one, one + y + 1);
        for(i = 0; i < N; i++) printf("%d%s", one[i], i==N-1? "":" ");
    } else {
        printf("Merge Sort\n");
        k = 1;
        int mr = -9;
        while(true) {
            for(i = 0; i < (int)N/k; i++) {
                sort(v1.begin() + i * k, v1.begin() + (i + 1) * k); 
            }
            if(N % k > 0) sort(v1.begin() + i * k, v1.end());
            k = k * 2;
            if(mr > 0) break;
            if(v1==v0) mr = 9;
        }
        for(i = 0; i < N; i++) printf("%d%s", v1[i], i==N-1? "":" ");
    }
    return 0;
}


old before
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

void printvec(vector<int> a){
    for(int i=0; i<a.size();i++){
        cout<<a[i];
        if(i!=(a.size()-1))
            cout<<" ";
    }
    cout<<endl;
}

int main(void){
    vector<int> s0, s1, s2;
    int n, num;
    bool res;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>num;
        s0.push_back(num);
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

    int seg = 1, left, right, length, count = 0;
    for(int i = 0; i < n; i++){
        if(seg>n)
            break;
        for(int j = 0; j < n; j = j + seg * 2){
            left = (n-j)>=seg? seg:(n-j);
            right = (n-j-seg)>=seg? seg:(n-j-seg);
            right = (right>=0)? right:0;
            length = (left>right)? left*2:right*2;
            int countl = 0, countr = 0;
            while(length--){
                if(s0[j+countl]>s0[j+countr+seg]&&right>0){
                    s2.push_back(s0[j+countr+seg]);
                    right--;
                    countr++;
                }else if(s0[j+countl]<s0[j+countr+seg]&&left>0){
                    s2.push_back(s0[j+countl]);
                    countl++;
                    left--;
                }
            }
            while(left--){
                s2.push_back(s0[j+countl]);
                countl++;
            }
            while(right--){
                s2.push_back(s0[j+countr+seg]);
                countr++;
            }
        }
        s0 = s2;
        res = s0==s1;
        if(marked>0){
            cout<<"Merge Sort"<<endl;
            printvec(s0);
            return 0;
        }
        if(res)
            marked = 3;
        s2.erase(s2.begin(),s2.end());
        seg = seg * 2;
    }
    return 0;
}
