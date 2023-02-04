https://blog.csdn.net/m0_50617544/article/details/128761866?csdn_share_tail=%7B%22type%22%3A%22blog%22%2C%22rType%22%3A%22article%22%2C%22rId%22%3A%22128761866%22%2C%22source%22%3A%22m0_50617544%22%7D

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
vector<int> arr = {2, 9, 6, 1, 5, 8, 7, 11, 100, 30, 31, 38, 60, 50, 30};
void printvec(int len) {
    printf("%d", arr[0]);
    for(int i = 1; i < len; i++) printf(" %d", arr[i]);
}
void mergesort(int len) {
    int i, j, ij, k = 1, start, end, Khalf, in, kk, ll;
    while(true) {
        Khalf = k;
        k = k * 2;
        if(k >= len) break;
        vector<int> tmp;
        for(i = 0; i < len; i+= k) {
            kk = start = i; // 0
            ll = in = i + k/2;
            end = min(i + k, len); //2 
            while(kk < in && ll < end) {  //归并
                if(arr[kk] < arr[ll]) tmp.push_back(arr[kk++]);
                else tmp.push_back(arr[ll++]);
            }
            while(kk < in) tmp.push_back(arr[kk++]);
            while(ll < end) tmp.push_back(arr[ll++]);
        }
        arr = tmp;
    }
}
int main(int argc, char **argv) {
    int len = arr.size();
    if(len==1) {
        printvec(len);
        return EXIT_SUCCESS;
    }
    mergesort(len);
    printvec(len);
    return EXIT_SUCCESS;
}

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
vector<int> arr = {2, 9, 6, 1, 5, 8, 7, 11, 100, 30, 31, 38, 60, 50, 30};
void printvec(int len) {
    printf("%d", arr[0]);
    for(int i = 1; i < len; i++) printf(" %d", arr[i]);
}
void mergesort(int len) {
    int i, j, ij, k = 1, start, end, Khalf, in, kk, ll;
    while(true) {
        Khalf = k;
        k = k * 2;
        if(k >= len) break;
        vector<int> tmp;
        for(i = 0; i < len / k + (int)(len%k>0); i++) {
            kk = start = i * k; // 0
            ll = in = i * k + Khalf;
            end = min((i + 1) * k, len); //2 
            while(kk < in && ll < end) {  //归并
                if(arr[kk] < arr[ll]) tmp.push_back(arr[kk++]);
                else tmp.push_back(arr[ll++]);
            }
            while(kk < in) tmp.push_back(arr[kk++]);
            while(ll < end) tmp.push_back(arr[ll++]);
        }
        arr = tmp;
    }
}
int main(int argc, char **argv) {
    int len = arr.size();
    if(len==1) {
        printvec(len);
        return EXIT_SUCCESS;
    }
    mergesort(len);
    printvec(len);
    return EXIT_SUCCESS;
}
