#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int i, j, num, first = 0, halfline, use;
    char buf;
    cin>>num>>buf;
    halfline = (int)sqrt((num + 1)/2);  //2n*n -1
    use = 2 * halfline * halfline - 1; //2n*n -1
    int remain = num - use;
    for(int m=halfline; m>=1; m--){
        for(j = 0; j < first; j++)
            cout<<" ";
        first++;
        for(i = 0; i < 2 * m - 1; i++)
            cout<<buf;
        cout<<endl;
    }
    for(int m=2; m<halfline+1; m++){
        for(j = first - 2; j > 0; j--)
            cout<<" ";
        first--;
        for(i = 0; i < 2 * m - 1; i++)
            cout<<buf;
        cout<<endl;
    }
    cout<<remain<<endl;
    return 0;
}
