old before
#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;
int x, y, z, status = 0;

struct nodees{
    struct nodees *left = nullptr;
    struct nodees *right = nullptr;
    int values = -999;
};

void gettree(nodees *nd, vector<int> v, vector<int> v0){
    if(v.size()==1 && v0.size()==1 && v[0]==v0[0]) {
        nd->values = v[0]; 
        status = status|0;
        return;
    }
    if(v.size()==0||v0.size()==0) return;
    x = v0[v0.size() - 2];
    nd->values = v0[v0.size() - 1];
    vector<int> left0, right0, tmp, left, right;
    v.erase(v.begin());
    tmp = v;
    for(int i=0; i<v.size(); i++){
        if(v[i]==x){
            y = i;
            break;
        }
    }
    v0.pop_back();
    v.erase(v.begin() + y, v.end());
    left = v;
    set<int> st;
    set<int>::iterator it;
    for(int i = 0; i < left.size(); i++) st.insert(left[i]);
    tmp.erase(tmp.begin(), tmp.begin() + y);
    right = tmp;
    for(int i = 0; i < v0.size(); i++){
        it = st.find(v0[i]);
        if(it==st.end()){
            y = i;
            break;
        }
    }
    tmp = v0;
    v0.erase(v0.begin() + y, v0.end());
    left0 = v0;
    tmp.erase(tmp.begin(), tmp.begin() + y);
    right0 = tmp;
    nd->left = new(struct nodees);
    nd->right = new(struct nodees);
    gettree(nd->left, left, left0);
    gettree(nd->right, right, right0);
}

vector<int> vtr;

void inorder(struct nodees *root) {
    if(root->left!=nullptr)
        inorder(root->left);
    if(root->values > 0)
        vtr.push_back(root->values);
    if(root->values < 0)
        status = status|1;
    if(root->right!=nullptr)
        inorder(root->right);
    return;
}

int main(){
    int n, i, j, a, c;
    cin>>n;
    vector<int> v, v0;
    map<int, int> m, m0;
    struct nodees *nd = new(struct nodees);
    for(i = 0; i < n; i++){
        cin>>a;
        v.push_back(a);
        m[a] = i;
    }
    for(i = 0; i < n; i++) {
        cin>>a;
        v0.push_back(a);
        m0[a] = i;
    }
    gettree(nd, v, v0);
    inorder(nd);
    if(status==0) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    for(i = 0; i < vtr.size(); i++) {
        cout<<vtr[i];
        if(i!=vtr.size() - 1) cout<<" ";
    }
    cout<<endl;
    return 0;
}

update
#include<iostream>
#include<vector>
using namespace std;
int pre[31], post[31], m, in[31], cnt = 0, one = 1;
void recursion(int prel, int prer, int postl, int postr) {
    int k = prel, val = post[postr];
    if(prel==prer){
        in[cnt++] = pre[prel];
        return;
    }
    if(pre[prel]==post[postr]) {
        while(k<=prer&&pre[k]!=post[postr-1]) k++;
        if(k-prel>1)
            recursion(prel + 1, k - 1, postl, postl + (k - prel - 1) - 1);
        else
            one = 0;
        in[cnt++] = pre[prel];
        recursion(k, prer, postl + (k - prel - 1), postr - 1);
    }
}
int main(int argc, char **argv) {
    int i, j, k, n;
    cin>>m;
    for(i = 0; i < m; i++) scanf("%d", &pre[i]);
    for(i = 0; i < m; i++) scanf("%d", &post[i]);
    recursion(0, m-1, 0, m - 1);
    printf("%s\n%d", one==0? "No":"Yes", in[0]);
    for(i=1; i < m; i++) printf(" %d", in[i]);
    printf("\n");
    return 0;
}
