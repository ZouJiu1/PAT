update202301   gentree正反可以用bool判断并合并，递归遍历可以同时保存前序遍历、后序遍历或者中序遍历的序列
不用写多个函数的，使用递归的前序序列和输入序列是否相等判断
#include<iostream>
#include<vector>
using namespace std;
vector<int> arr, pot, pre;
int cnt = 0;
struct nod {
    nod *l = NULL, *r = NULL;
    int val;
};
nod* gentree(nod *rot, int val, bool r) {
    if(rot==NULL) {
        rot = new(nod);
        rot->val = val;
    } else if((r==false && val < rot->val)||(r==true && val >= rot->val)) {
        rot->l = gentree(rot->l, val, r);
    } else if((r==false && val >= rot->val)||(r==true && val < rot->val)) {
        rot->r = gentree(rot->r, val, r);
    }
    return rot;
}

void postorder(nod *rot) {
    if(rot==NULL) return;
    pre.push_back(rot->val);
    postorder(rot->l);
    postorder(rot->r);
    pot.push_back(rot->val);
}

int main(void) {
    int i, j, k, m, n, N;
    cin>>N;
    for(i = 0; i < N; i++) {
        scanf("%d", &k);
        arr.push_back(k);
    }
    nod *rot = NULL;
    for(i = 0; i < N; i++) rot = gentree(rot, arr[i], (bool)(arr[0] > arr[N-1]));
    postorder(rot);
    if(pre!=arr) {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    for(i = 0; i <N; i++) {
        printf("%d", pot[i]);
        if(i!=N-1) printf(" ");
    }
    return 0;
}

update
#include<iostream>
#include<vector>
using namespace std;
struct nod{
    nod *l = NULL, *r = NULL;
    int val;
};
nod* gen_(nod *root, int val) {
    if(root==NULL) {
        root = new(nod);
        root->val = val;
    } else if(val < root->val)
        root->l = gen_(root->l, val);
    else if(val >= root->val) 
        root->r = gen_(root->r, val);
    return root;
}
nod* gen_rev(nod *root, int val) {
    if(root==NULL) {
        root = new(nod);
        root->val = val;
    } else if(val >= root->val)
        root->l = gen_rev(root->l, val);
    else if(val < root->val) 
        root->r = gen_rev(root->r, val);
    return root;
}
vector<int> pre_ord, pos_ord, sav;
void pre(nod *root){
    if(root==NULL) return;
    pre_ord.push_back(root->val);
    pre(root->l);
    pre(root->r);
}
void post(nod *root){
    if(root==NULL) return;
    post(root->l);
    post(root->r);
    pos_ord.push_back(root->val);
}
int main(int argc, char **argv) {
    int i, j, k, m, n;
    cin>>m;
    nod *root = NULL;
    for(i = 0; i < m; i++) {
        scanf("%d", &k);
        sav.push_back(k);
    }
    if(m==1) {
        cout<<"YES"<<endl<<sav[0]<<endl;
        return 0;
    }
    if(sav[0] <= sav[sav.size()-1]){
        for(i = 0; i < m; i++) 
            root = gen_(root, sav[i]);
    }
    else {
        for(i = 0; i < m; i++) 
            root = gen_rev(root, sav[i]);
    }
    pre(root);
    if(sav!=pre_ord){
        cout<<"NO"<<endl;
        return 0;
    }
    post(root);
    cout<<"YES\n"<<pos_ord[0];
    for(i = 1; i < pos_ord.size(); i++) cout<<" "<<pos_ord[i];
    return 0;
}


old before
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
