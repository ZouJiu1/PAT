#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
string tk;
struct nod {int n, A;};
nod nd;
vector<nod> res;
int gcd(int a, int c) {
    int tmp;
    while(c%a!=0) {
        tmp = c;
        c = a;
        a = tmp%a;
    }
    return a;
}
bool prime(int a) {
    if(a==2||a==5||a==7||a==11||a==13) return true;
    for(int i = 2; i * i <= a; i++) {
        if(a%i==0) return false;
    }
    return true;
}
void dfs(string t, int K, int m, int sum, int start) {
    int i, j, x1, x2;
    nd.n = 0;
    if(sum==m){
        x1 = stoi(t);
        tk = to_string(x1 + 1);
        for(j = 0; j < tk.length(); j++) nd.n += tk[j] - '0';
        x2 = gcd(nd.n, m);
        nd.A = x1;
        if(x2>2 && prime(x2)==true) res.push_back(nd);
        return;
    }
    if(start>K) return;
    for(i = 0; i <10; i++) {
        if(start==1&&i==0) continue;
        x1 = sum + i + (K-t.length()-1)*9;
        if(x1 < m) continue;
        if(sum < m) {
            dfs(t + to_string(i), K, m, sum + i, start + 1);
        }
        else return;
    }
}
bool compare(nod &a, nod &c){
    if(a.n < c.n) return true;
    else if(a.n==c.n){
        return a.A < c.A;
    }else return false;
}
int main(void) {
    int i, j, K, m, n, x, y;
    cin>>x;
    for(i = 0; i < x; i++) {
        cin>>K>>m;
        dfs("", K, m, 0, 1);
        printf("Case %d\n", i + 1);
        if(res.size()==0) printf("No Solution\n");
        sort(res.begin(), res.end(), compare);
        for(j = 0; j < res.size(); j++) {
            cout<<res[j].n<<" "<<res[j].A<<endl;
        }
        res.clear();
    }
    return 0;
}
