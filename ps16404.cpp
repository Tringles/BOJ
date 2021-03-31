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

int n, m, s, p1, p2, p3, cnt;
int visit[100005], check[100005], seg[100005 * 4], lazy[100005 * 4];
vector<vector<int>> v;

void dfs(int cur) {
	visit[cur] = ++cnt;
	for (auto& i : v[cur])
		if (!visit[i])dfs(i);
	check[cur] = cnt;
}
void propagate(int lo, int hi, int node) {
	if (!lazy[node])return;
	else {
		if (lo != hi) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
	}
	seg[node] += lazy[node] * (hi - lo + 1);
	lazy[node] = 0;
}
int update(int lo, int hi, int val, int node, int x, int y) {
	propagate(x, y, node);
	if (hi < x || y < lo)return seg[node];
	if (lo <= x && y <= hi) {
		lazy[node] += val;
		propagate(x, y, node);
		return seg[node];
	}
	int mid = (x + y) >> 1;
	return seg[node] = update(lo, hi, val, node * 2, x, mid) + update(lo, hi, val, node * 2 + 1, mid + 1, y);
}
int query(int lo, int hi, int node, int x, int y) {
	propagate(x, y, node);
	if (hi < x || y < lo)return 0;
	if (lo <= x && y <= hi)return seg[node];
	int mid = (x + y) >> 1;
	return query(lo, hi, node * 2, x, mid) + query(lo, hi, node * 2 + 1, mid + 1, y);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	v.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> s;
		if (s != -1)v[s].push_back(i);
	}
	dfs(1);
	while (m--) {
		cin >> p1;
		if (p1 == 1) {
			cin >> p2 >> p3;
			update(visit[p2], check[p2], p3, 1, 1, n);
		}
		else {
			cin >> p2;
			cout << query(visit[p2], visit[p2], 1, 1, n) << endl;
		}
	}
	return 0;
}
