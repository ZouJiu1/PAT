/*注意计算出n1、n2、n3遍历，以及输出的次序即可*/
#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

int main(int argc, char **argv){
    string s, s0;
    int i, j, k;
    cin>>s;
    int n1, n2, n3, maxmax = -999, l, mar;
    l = s.length();
    for(i = 3; i <= l; i++){
        mar = 999;
        for(j = i; j >= 0; j--){
            if((j * 2 + i -2)== l){
                mar = -999;
                break;
            }
        }
        if(mar < 0 && maxmax < j){
            maxmax = j;
            n2 = i;
        }
    }
    n1 = n3 = maxmax;
    for(i = 0; i < n1; i++){
        cout<<s[i];
        if(i != (n1 - 1))
            for(j = 0; j < (n2 - 2); j++) cout<<" ";
        else
            for(j = 0; j < (n2 - 2); j++) cout<<s[i + j + 1];
        cout<<s[l - i - 1]<<endl;
    }
    return EXIT_SUCCESS;
}
