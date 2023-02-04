双指针方式一个行一个列，用来做递推的，理解方式是令k=0看最外面一圈是怎么顺时针填充的
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
bool cmp(int &a, int &c) {return a >= c;};
int main(void) {
    int i, j, k, m, n, y, z, cnt, N;
    cin>>N;
    for(i = (int)sqrt(N) + 1; i >= 0; i--) {
        if(N%i==0) break;
    }
    m = N/i > i? N/i:i;
    n = N/m;
    vector<int> v(N);
    vector<vector<int>> matrix(m);
    for(i = 0; i < m; i++) matrix[i].resize(n);
    for(i = 0; i < N; i++) scanf("%d", &v[i]);
    sort(v.begin(), v.end(), cmp);
    cnt = j = y = z = k = 0;
    while(cnt!=N) {
        for(i = k; i < n - k && cnt < N; i++)
            matrix[j][i] = v[cnt++];
        i--;
        for(j = 1 + k; j < m - k && cnt < N; j++)
            matrix[j][i] = v[cnt++];
        j--;
        for(i = n-2-k; i >=k && cnt < N; i--)
            matrix[j][i] = v[cnt++];
        i++;
        for(j = m-2-k; j >=1+k && cnt < N; j--)
            matrix[j][i] = v[cnt++];
        j++;
        k++;
    }
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            printf("%d%s", matrix[i][j], j==n-1? "\n":" ");
        }
    }
    return 0;
}


old before
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

bool compare(const int a, const int b){
    return a>=b;
}

int main(void){
    int count, num, m, n;
    vector<int> vec;
    cin>>count;
    for(int i=0; i<count; i++){
        cin>>num;
        vec.push_back(num);
    }
    sort(vec.begin(), vec.end(), compare);
    n = (int)sqrt(count);
    if((n*n)==count){
        m=n;
    }else{
        for(int i=n+1; i>=1; i--){
            if(count%i==0){
                m=i;
                n=count/i;
                break;
            }
        }
    }
    if(m<n){
        m = n+m;
        n = m - n;
        m = m - n;
    }
    int matrix[m][n], tmp, kd, countcount=0, ik=0, jk=0, i, j;
    int row = m, col = n;
    for(j=0; j<col; j++){
        matrix[ik][jk++] = vec[countcount++];
    }
    jk--;
    for(i=0; i<m; i++){
        if(i!=0){
            for(j=0; j<col; j++){
                matrix[ik][++jk] = vec[countcount++];
            }
        }
        row--;
        if(row==0)
            break;
        for(i=0; i<row; i++){
            matrix[++ik][jk] = vec[countcount++];
        }
        col--;
        if(col==0)
            break;
        for(j=0; j<col; j++){
            matrix[ik][--jk] = vec[countcount++];
        }
        row--;
        if(row==0)
            break;
        for(i=0; i<row; i++){
            matrix[--ik][jk] = vec[countcount++];
        }
        col--;
        if(col==0)
            break;
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout<<matrix[i][j];
            if(j!=(n-1))
                cout<<" ";
        }
        cout<<endl;
    }
    // cout<<m<<" "<<n<<endl;
    
    return 0;
}
