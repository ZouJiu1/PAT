#include<iostream>
using namespace std;
int arr[] = {2, 9, 6, 1, 5, 8, 7, 11, 100, 30, 31, 38, 60, 50, 30};
void printvec(int len) {
    printf("%d", arr[0]);
    for(int i = 1; i < len; i++) 
        printf(" %d", arr[i]);
}
void quicksort(int l, int r) {
    if(l>=r) return;
    int h = arr[l];
    int start = l;
    int end = r;
    while(l < r) {
        while(l < r && arr[r] >= h)
            r--;
        if(l<r) arr[l++]= arr[r];
        while(l < r && arr[l] < h)
            l++;
        if(l<r) arr[r--] = arr[l];
    }
    arr[l] = h; //l==r
    quicksort(start, l-1);
    quicksort(l+1, end);
}
int main(int argc, char **argv) {
    int len = sizeof(arr)/sizeof(*arr);
    if(len==1) {
        printvec(len);
        return EXIT_SUCCESS;
    }
    quicksort(0, len - 1);
    printvec(len);
    return EXIT_SUCCESS;
}
