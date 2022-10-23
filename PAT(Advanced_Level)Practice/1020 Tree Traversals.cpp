update
#include<iostream>
#include<vector>
#include<map>
using namespace std;
int post[31], in[31];
map<int, int> mp, inm;
void pre(int root, int start, int end, int index){
    if(start > end) return;
    int i = inm[post[root]];
    mp[index] = post[root];
    pre(root - (end - i + 1), start, i - 1, 2 * index + 1);
    pre(root - 1, i + 1, end, 2 * index + 2);
}
int main(int argc, char **argv){
    int i, j, k, m, n;
    cin>>m;
    for(i = 0; i < m; i++) scanf("%d", &post[i]);
    for(i = 0; i < m; i++) {
        scanf("%d", &in[i]);
        inm[in[i]] = i;
    }
    pre(m-1, 0, m-1, 0);
    map<int, int>::iterator it = mp.begin();
    cout<<it++->second;
    while(it!=mp.end()) printf(" %d", (it++)->second);
    return EXIT_SUCCESS;
}

old before
/*
已经二叉树的中序遍历序列，以及后序遍历序列，求层序遍历序列

中序遍历序列：[left, root, right]，后序遍历序列：[left, right, root]

postorder: 4 5 2 3 1  inorder: 4 2 5 1 3

 先看后续遍历序列，最后一位就是root节点1，然后inorder可以被1化为左右两侧  

得到4 2 5 和 3；然后相应的根据元素，postorder可化为4 5 2 和 3。1被删除了的

将1存到二叉树结构体的value，然后postorder变为2个了，inorder也变为2个了

postorder1: 4 5 2   inorder1: 4 2 5

postorder2: 3     inorder2: 3

然后根据后续遍历最后1位，可以得到根节点root1=2，然后inorder1被2划开，将左支继续划为两支

postorder3: 4     inorder  4

postorder4: 5     inorder4: 5

可以使用递归的方式得到二叉树的整体结构，要注意二叉树赋值要提前malloc内存

*/
#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;
int x, y, z;

struct nodees{
    struct nodees *left;
    struct nodees *right;
    int values;
};

void gettree(nodees *nd, vector<int> v, vector<int> v0){
    if(v.size()==0||v0.size()==0) return;
    x = v[v.size()-1];
    nd->values = x;
    vector<int> left0, right0, tmp, left, right;
    tmp = v0;
    for(int i=0; i<v0.size(); i++){
        if(v0[i]==x){
            y = i;
            break;
        }
    }
    v.pop_back();
    v0.erase(v0.begin() + y, v0.end());
    left0 = v0;
    set<int> st;
    set<int>::iterator it;
    for(int i = 0; i < left0.size(); i++) st.insert(left0[i]);
    tmp.erase(tmp.begin(), tmp.begin() + y + 1);
    right0 = tmp;
    for(int i = 0; i < v.size(); i++){
        it = st.find(v[i]);
        if(it==st.end()){
            y = i;
            break;
        }
    }
    tmp = v;
    v.erase(v.begin() + y, v.end());
    left = v;
    tmp.erase(tmp.begin(), tmp.begin() + y);
    right = tmp;
    nd->left = (struct nodees *)malloc(sizeof(struct nodees));
    nd->right = (struct nodees *)malloc(sizeof(struct nodees));
    nd->left->values = -9;
    nd->right->values = -9;
    gettree(nd->left, left, left0);
    gettree(nd->right, right, right0);
}

int main(){
    int n, i, j, a, c;
    cin>>n;
    vector<int> v, v0;
    map<int, int> m, m0;
    struct nodees *nd = (struct nodees *)malloc(sizeof(struct nodees));
    for(i = 0; i < n; i++){
        cin>>a;
        v.push_back(a);
        m[a] = i;
    }
    for(i = 0; i < n; i++){
        cin>>a;
        v0.push_back(a);
        m0[a] = i;
    }
    gettree(nd, v, v0);
    vector<long long> add;
    add.push_back((long long)nd);
    struct nodees *ndd;
    vector<int> www;
    while(add.size()!=0){
        ndd = (struct nodees *)add[0];
        add.erase(add.begin());
        www.push_back(ndd->values);
        if(ndd->left->values > 0) add.push_back((long long)ndd->left);
        if(ndd->right->values > 0) add.push_back((long long)ndd->right);
    }
    for(int i = 0; i < www.size(); i++){
        cout<<www[i];
        if(i!=(www.size()-1)) cout<<" ";
    }
    return 0;
}
