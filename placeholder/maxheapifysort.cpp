#include<iostream>
using namespace std;
int arr[] = {2, 9, 6, 1, 5, 8, 7, 11, 100, 30, 31, 38, 60, 50, 30};
void printvec(int len) {
    printf("%d", arr[0]);
    for(int i = 1; i < len; i++) printf(" %d", arr[i]);
}
void maxheapify(int start, int end) {
    int dad = start;
    int son = dad * 2 + 1;
    while(son < end) {           //是while不是if
        if(son+1 < end && arr[son+1] > arr[son]) //子节点的最大值
            son++;
        if(arr[dad] > arr[son]) return;   //父节点是最大值返回
        if(arr[dad] < arr[son]) {
            swap(arr[dad], arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}
void heapsort(int len) {
    for(int i = len/2 - 1; i >= 0; i--) //len/2-1拿到最后一个父节点的序号，从0开始
        maxheapify(i, len);   //从下到上, generate heap
    for(int i = len - 1; i > 0; i--) {   
        swap(arr[0], arr[i]);
        maxheapify(0, i); //从上到下
    }
}
int main(int argc, char **argv) {
    int len = sizeof(arr)/sizeof(*arr);
    if(len==1) {
        printvec(len);
        return EXIT_SUCCESS;
    }
    heapsort(len);
    printvec(len);
    return EXIT_SUCCESS;
}

/*
    //max heap sort
    void maxheapify(vector<int>& nums, int i, int len) {
        int dad = i;
        int son = i*2;
        while(son <= len) {
            if(son + 1 <= len && nums[son] > nums[son-1]) son++;
            if(nums[dad-1] < nums[son-1]) swap(nums[dad-1], nums[son-1]);
            dad = son;
            son = dad * 2;
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = n / 2; i >= 1; i--) {
            maxheapify(nums, i, nums.size());
        }
        for(int i = n-1; i >= 0; i--) {
            swap(nums[i], nums[0]);
            maxheapify(nums, 1, i);
        }
        return nums[nums.size()-k];
————————————————

                            版权声明：本文为博主原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接和本声明。
                        
原文链接：https://blog.csdn.net/m0_50617544/article/details/137790146
*/
