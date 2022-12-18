#include<iostream>
#include<string>
#include<map>
#include<queue>
#include<vector>
using namespace std;
int main() {
    int i, j, k, m, n;
    cin >> m;
    vector<int> v;
    queue<int> q;
    for (i = 0; i < m; i++) {
        cin >> n;
        v.push_back(n);
        q.push(n);
    }
    int sum = 0, count = 0;
    for (i = 1; i <= m; i++) {
        n = q.front();
        int cnt = 0;
        while (n != i) {
            q.push(q.front());
            cnt++;
            q.pop();
            n = q.front();
        }
        q.pop();
        count += cnt + 1;
        sum += (m - i + 1) * (cnt+1);
    }
    printf("%d %.1f", count, sum / (float)m);
    return 0;
}
