#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, pair<int, int>> P;
#define endl '\n'
#define INF 2e9
#define LINF 2e11
#define MOD 1000000007

int n, m, p1, p2, c[100005];
vector<vector<int>> v;

void dfs(int cur) {
	for (auto& i : v[cur]) {
		c[i] += c[cur];
		dfs(i);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	v.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> p1;
		if (p1 != -1)v[p1].push_back(i);
	}
	for (int i = 0; i < m; i++) {
		cin >> p1 >> p2;
		c[p1] += p2;
	}
	dfs(1);
	for (int i = 1; i <= n; i++)cout << c[i] << ' ';
	cout << endl;
	return 0;
}