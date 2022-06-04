#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(void){
    int n, x0, x1, x2, x3, jia=0, yi=0, sum;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>x0>>x1>>x2>>x3;
        sum = x0+x2;
        if((sum==x1&&sum==x3)||(sum!=x1&&sum!=x3))
            continue;
        else if(sum==x1&&sum!=x3)
            yi+=1;
        else if(sum==x3&&sum!=x1)
            jia+=1;
    }
    cout<<jia<<" "<<yi<<endl;
    return 0;
}
