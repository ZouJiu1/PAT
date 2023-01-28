/*
2 9 6 1 5 8 7 11 100 30 31 38 60 50 30
upper_bound: 8 100
lower_bound: 7 11
100 60 50 38 31 30 30 11 9 8 7 6 5 2 1
upper_bound: greater()8 9
lower_bound: greater()7 11
*/
#include<iostream>
#include<algorithm>
using namespace std;
int arr[] = {2, 9, 6, 1, 5, 8, 7, 11, 100, 30, 31, 38, 60, 50, 30};
int len = sizeof(arr)/sizeof(arr[0]);
bool cmp(int &a, int &c) {return a > c;};
void printfvec(int chr[]) {
    for(int i = 0; i < len; i++) {
        printf("%d", chr[i]);
        if(i!=len - 1) printf(" ");
        else printf("\n");
    }
}
int main(void) {
    int len = sizeof(arr)/sizeof(arr[0]);
    printfvec(arr);
    int it = upper_bound(arr, arr+len, 11) - arr; //>的第一个值position
    cout<<"upper_bound: "<<it<<" "<<arr[it]<<endl;
    it = lower_bound(arr, arr+len, 11) - arr; //>=的第一个值position
    cout<<"lower_bound: "<<it<<" "<<arr[it]<<endl;

    sort(arr, arr+len, cmp);
    printfvec(arr);
    it = upper_bound(arr, arr+len, 11, greater<int>()) - arr; //<的第一个值position
    cout<<"upper_bound: greater()"<<it<<" "<<arr[it]<<endl;
    it = lower_bound(arr, arr+len, 11, greater<int>()) - arr; //<=的第一个值position
    cout<<"lower_bound: greater()"<<it<<" "<<arr[it]<<endl;
    return 0;
}
