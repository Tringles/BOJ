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

int n, m, seg[100004 * 4], visit[100004], check[100004], depth[100004], cnt;
vector<vector<int>> v;

void dfs(int cur) {
	visit[cur] = ++cnt;
	for (auto& i : v[cur]) {
		if (!visit[i]) {
			depth[i] = depth[cur] + 1;
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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	v.resize(n + 1);
	for (int i = 1, p1; i <= n; i++) {
		cin >> p1;
		if (p1 != -1)v[p1].push_back(i);
	}
	depth[1] = 1;
	dfs(1);
	for (int i = 0, p1, p2, p3; i < m; i++) {
		cin >> p1;
		if (p1 == 1) {
			cin >> p2 >> p3;
			update(visit[p2], p3, 1, 1, n);
		}
		else {
			cin >> p2;
			cout << query(visit[p2], check[p2], 1, 1, n) << endl;
		}
	}
	return 0;
}