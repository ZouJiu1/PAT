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
