#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    string credits;
    int i, n, j, sum, marked;
    cin>>n;
    vector<string> vec;
    int weight[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    int M[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
    for(i=0; i<n; i++){
        cin>>credits;
        sum = 0;
        marked = -6;
        for(j=0; j<17; j++){
            if(credits[j]>='0'&&credits[j]<='9')
                sum += weight[j] * (credits[j] - '0');
            else{
                marked=6;
                break;
            }
        }
        sum = sum%11;
        if(M[sum]!=credits[17]||marked>0)
        {
            vec.push_back(credits);
            continue;
        }
    }
    if(vec.size()==0)
        cout<<"All passed";
    else{
        for(i=0; i<vec.size(); i++){
            cout<<vec[i]<<endl;
        }
    }
    return 0;
}
