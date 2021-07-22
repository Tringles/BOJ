#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PI;
typedef pair<ll, ll> PL;
typedef pair<int, pair<int, int>> PII;
typedef pair<ll, pair<ll, ll>> PLL;
#define endl '\n'
#define INF 2e9
#define LINF 2e15
#define MOD 1000000007

int n, m, cnt;
int seg[100004 * 4], visit[100004], check[100004], depth[100004], p[20][100004];
vector<vector<int>> v;

void dfs(int cur) {
	visit[cur] = ++cnt;
	for (auto& i : v[cur]) {
		if (cur == i)continue;
		if (!visit[i]) {
			depth[i] = depth[cur] + 1;
			p[0][i] = cur;
			dfs(i);
		}
	}
	check[cur] = cnt;
}
int update(int pos, int val, int node, int x, int y) {
	if (pos<x || pos>y)return seg[node];
	if (x == y)return seg[node] += val;
	int mid = (x + y) >> 1;
	return seg[node] = update(pos, val, node * 2, x, mid) + update(pos, val, node * 2 + 1, mid + 1, y);
}
int query(int lo, int hi, int node, int x, int y) {
	if (lo > y || hi < x)return 0;
	if (lo <= x && y <= hi)return seg[node];
	int mid = (x + y) >> 1;
	return query(lo, hi, node * 2, x, mid) + query(lo, hi, node * 2 + 1, mid + 1, y);
}
int lca(int x, int y) {
	if (depth[x] > depth[y])swap(x, y);
	for (int i = 19; i >= 0; i--) {
		int dif = depth[y] - depth[x];
		if (dif >= (1 << i))y = p[i][y];
	}
	if (x == y)return x;
	for (int i = 19; i >= 0; i--) {
		if (p[i][x] != p[i][y]) {
			x = p[i][x];
			y = p[i][y];
		}
	}
	return p[0][x];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	v.resize(n + 1);
	for (int i = 1, p1, p2; i < n; i++) {
		cin >> p1 >> p2;
		v[p1].push_back(p2);
		v[p2].push_back(p1);
	}
	depth[1] = 1;
	dfs(1);
	for (int i = 1; i < 20; i++)
		for (int j = 1; j <= n; j++)
			p[i][j] = p[i - 1][p[i - 1][j]];
	for (int i = 0, p1, p2; i < m; i++) {
		char cmd;
		cin >> cmd >> p1 >> p2;
		if (cmd == 'P') {
			update(visit[lca(p1, p2)], -2, 1, 1, n);
			update(visit[p1], 1, 1, 1, n);
			update(visit[p2], 1, 1, 1, n);
		}
		else {
			int x;
			if (visit[p1] < visit[p2])x = p2;
			else x = p1;
			cout << query(visit[x], check[x], 1, 1, n) << endl;
		}
	}
	return 0;
}