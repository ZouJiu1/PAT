#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
int uniona[1006];
int findfather(int a) {
	int tmp = a;
	while (a != uniona[a]) a = uniona[a];
	//uniona[tmp] = a;
	return a;
}
void unionjoin(int a, int c) {
	int x = findfather(a);
	int y = findfather(c);
	if (x >= y) uniona[x] = y;
	else uniona[y] = x;
}
int main(void) {
	int i, j, k, m, n, x1, x2, x3, rev;
	cin >> k >> m >> n;
	vector<vector<int>> rmp;
	rmp.resize(1006);
	for (i = 0; i < 1006; i++) {
		rmp[i].resize(1006);
	}
	for (i = 0; i < 1006; i++) {
		for (j = 0; j < 1006; j++) {
			rmp[i][j] = 0;
		}
	}
	for (i = 0; i < n; i++) {
		cin >> x1 >> x2 >> x3;
		rmp[x1][x2] += x3;
	}
	vector<int> v;
	for (i = 1; i <= m; i++) {
		x3 = 0;
		rev = 0;
		for (j = 1; j <= m; j++) {
			if (rmp[i][j] <= 5 && rmp[i][j]) {
				if (rmp[j][i] > 0) rev++;
				x3++;
			}
		}
		if (x3 > k && rev * 5 <= x3) v.push_back(i);
	}
	if (v.size() == 0) {
		cout << "None" << endl;
		return 0;
	}
	sort(v.begin(), v.end());
	for (i = 0; i < 1006; i++) uniona[i] = i;
	for (i = 0; i < v.size(); i++) {
		for (j = i + 1; j < v.size(); j++) {
			if (rmp[v[i]][v[j]] > 0 && rmp[v[j]][v[i]] > 0)
				unionjoin(v[i], v[j]);
		}
	}
	vector<int> status(v.size(), 0);
	vector<vector<int>> vvv;
	vvv.resize(1000);
	int cnt = 0;
	for (i = 0; i < v.size(); i++) {
		if (status[i] == 0) {
			vvv[cnt].push_back(v[i]);
		}
		for (j = i + 1; j < v.size(); j++) {
			if (status[j] == 0 && findfather(v[j])==findfather(v[i])) {
				vvv[cnt].push_back(v[j]);
				status[j] = 1;
			}
		}
		if (status[i] == 0) cnt++;
		status[i] = 1;
	}
	for (i = 0; i < 1000; i++) {
		if (vvv[i].size() == 0) break;
		for (j = 0; j < vvv[i].size(); j++) {
			cout << vvv[i][j];
			if (j != vvv[i].size() - 1) cout << " ";
		}
		cout << endl;
	}
	return 0;
}
