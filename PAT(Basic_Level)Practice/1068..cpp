#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n, m, num, inputs, TOL;
    cin>>n>>m>>TOL;
    int pixels[m][n];
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>inputs;
            pixels[i][j] = inputs;
        }
    }
    int x0, x1, x2, y0, y1, y2, cor=0, tmp, tx, ty;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            num = pixels[i][j];
            x0 = j - 1;
            x1 = j;
            x2 = j + 1;
            y0 = i - 1;
            y1 = i;
            y2 = i + 1;
            if(x0<0||y0<0||x2>=n||y2>=m) continue;
            if((num - pixels[y0][x0])<=TOL) continue;
            if((num - pixels[y1][x0])<=TOL) continue;
            if((num - pixels[y2][x0])<=TOL) continue;
            if((num - pixels[y0][x1])<=TOL) continue;
            if((num - pixels[y2][x1])<=TOL) continue;
            if((num - pixels[y0][x2])<=TOL) continue;
            if((num - pixels[y1][x2])<=TOL) continue;
            if((num - pixels[y2][x2])<=TOL) continue;
            cor++;
            if(cor==2){
                cout<<"Not Unique";
                return 0;
            }
            tmp = num;
            tx = j+1;
            ty = i+1;
        }
    }
    if(cor==1) printf("(%d, %d): %d", tx, ty, tmp);
    else cout<<"Not Exist";
    return 0;
}
