#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

struct node{
    int addr;
    int data;
    int next;
};

int main(void){
    int add0, num, tet, i;
    node nodall[100006];
    vector<node> vec;
    cin>>add0>>num>>tet;
    for(i=0; i<num; i++){
        node nod;
        cin>>nod.addr>>nod.data>>nod.next;
        nodall[nod.addr] = nod;
    }
    for(i=0; i<num; i++){
        vec.push_back(nodall[add0]);
        add0 = nodall[add0].next;
        if(add0==-1)
            break;
    }
    int steps = vec.size()/tet;
    for(i=0; i < steps; i++){
        reverse(vec.begin() + i * tet, vec.begin() + i * tet + tet);
    }
    for(i=0; i<vec.size() - 1; i++){
        vec[i].next = vec[i + 1].addr;
        printf("%05d %d %05d\n", vec[i].addr, vec[i].data, vec[i].next);
    }
    i = vec.size() - 1;
    vec[i].next = -1;
    printf("%05d %d -1\n", vec[i].addr, vec[i].data);
    return 0;
}
