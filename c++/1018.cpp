#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int n, C, J, B;
    int posJ=0, posB=0, posC=0, equal=0, neg=0, sum;
    int posYJ=0, posYB=0, posYC=0;
    char jia, yi, outJ, outY;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>jia>>yi;
        if(jia=='J'&&yi=='B')
            posJ++;
        else if(jia=='C'&&yi=='J')
            posC++;
        else if(jia=='B'&&yi=='C')
            posB++;
        else if(jia==yi)
            equal++;
        else
            neg++;

        if(yi=='J'&&jia=='B')
            posYJ++;
        else if(yi=='C'&&jia=='J')
            posYC++;
        else if(yi=='B'&&jia=='C')
            posYB++;
    }
    sum = posC + posB + posJ;
    cout<<sum<<" "<<equal<<" "<<neg<<endl;
    cout<<neg<<" "<<equal<<" "<<sum<<endl;
    if(posB>=posC&&posB>=posJ)
        cout<<"B ";
    else if(posC>=posB&&posC>=posJ)
        cout<<"C ";
    else if(posJ>=posC&&posJ>=posB)
        cout<<"J ";
    if(posYB>=posYC&&posYB>=posYJ)
        cout<<"B";
    else if(posYC>=posYB&&posYC>=posYJ)
        cout<<"C";
    else if(posYJ>=posYC&&posYJ>=posYB)
        cout<<"J";
    cout<<endl;
    return 0;
}
