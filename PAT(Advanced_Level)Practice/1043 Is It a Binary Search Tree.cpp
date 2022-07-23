/* 先根据题意产生二叉树，找到小于或者大于rootnode的位置，并排除不符合条件的序列，

然后使用递归，后续遍历即可*/
#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

typedef struct _binary{
    int val=999999999;
    _binary *l=NULL;
    _binary *r=NULL;
}binary;

vector<int> pos;
bool res = true;
void generate_binary(vector<int> v, binary *root, int way){
    vector<int> v0, v1, v0k;
    root->val = v[0];
    int i, j;
    for(i = 1; i < v.size(); i++){
        if(way==0&&v[i]>=v[0]) break;
        else if(way==1&&v[i]<v[0]) break;
    }
    if(res==false) return;
    if(way==0){
        for(j = 1; j <i; j++){
            if(v[j]>=v[0]){
                res = false;
                break;
            }
        }
        for(j = i; j < v.size(); j++){
            if(v[j] < v[0]){
                res = false;
                break;
            }
        }
    }else{
        for(j = 1; j <i; j++){
            if(v[j] < v[0]){
                res = false;
                break;
            }
        }
        for(j = i; j < v.size(); j++){
            if(v[j] >= v[0]){
                res = false;
                break;
            }
        }
    }
    v0 = v;
    v1 = v;
    v0.erase(v0.begin() + i, v0.end());
    v0.erase(v0.begin(), v0.begin()+1);
    v1.erase(v1.begin(), v1.begin() + i);
    if(v0.size()!=0){
        root->l = (binary *)malloc(sizeof(binary));
        root->l->l = nullptr;
        root->l->r = nullptr;
        generate_binary(v0, root->l, way);
    }
    if(v1.size()!=0){
        root->r = (binary *)malloc(sizeof(binary));
        root->r->l = nullptr;
        root->r->r = nullptr;
        generate_binary(v1, root->r, way);
    }
}

// void checkout(binary *root, int way){
//     int l, r, val;
//     val = root->val;
//     if(res==false)
//         return;
//     if(way==0){
//         l = -999999999;
//         r = 999999999;
//     }else{
//         r = -999999999;
//         l = 999999999;
//     }
//     if(root->l!=nullptr)
//         l = root->l->val;
//     if(root->r!=nullptr)
//         r = root->r->val;
//     if(way==0){
//         if(l >= val) res = false&&res;
//         if(r < val) res = false&&res;
//         if(l >= r) res = false&&res;
//     }else{
//         if(l < val) res = false&&res;
//         if(r >= val) res = false&&res;
//         if(l < r) res = false&&res;
//     }
//     res = true&&res;
//     if(root->l!=nullptr) {
//         checkout(root->l, way);
//     }
//     if(root->r!=nullptr) {
//         checkout(root->r, way);
//     }
// }

void postorder(binary *root){
    if(root->l!=nullptr) postorder(root->l);
    if(root->r!=nullptr) postorder(root->r);
    pos.push_back(root->val);
}

int main(void){
    int i, j, k, m, n, way;
    cin>>m;
    vector<int> v;
    for(i=0; i<m; i++){
        cin>>n;
        v.push_back(n);
    }
    if(v[0] <= v[v.size()-1]) way = 0;
    else way = 1;
    binary *root = (binary *)malloc(sizeof(binary));
    root->l = nullptr;
    root->r = nullptr;
    generate_binary(v, root, way);
    // checkout(root, way);
    if(res==false) {
        cout<<"NO";
        return 0;
    }
    postorder(root);
    cout<<"YES"<<endl;
    for(i = 0; i < pos.size(); i++){
        cout<<pos[i];
        if(i!=pos.size()-1) cout<<" ";
    }
    return 0;
}
