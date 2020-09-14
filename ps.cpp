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

int n, q, op, X, Y;
ll seg[100001 * 4], lazy[100001 * 4], s[100001], m[100001];

ll init(int node, int x, int y) {
	if (x == y)return seg[node] = s[x];
	int mid = (x + y) >> 1;
	return seg[node] = init(node * 2, x, mid) + init(node * 2 + 1, mid + 1, y);
}
void propagate(int node, int x, int y) {
	if (!lazy[node])return;
	if (x != y) {
		lazy[node * 2] += lazy[node];
		lazy[node * 2 + 1] += lazy[node];
	}
	seg[node] += (y - x + 1) * lazy[node];
	lazy[node] = 0;
}
void update(int lo, int hi, int node, int val, int x, int y) {
	propagate(node, x, y);
	if (hi < x || y < lo)return;
	if (lo <= x && y <= hi) {
		lazy[node] = val;
		propagate(node, x, y);
		return;
	}
	int mid = (x + y) >> 1;
	update(lo, hi, node * 2, val, x, mid);
	update(lo, hi, node * 2 + 1, val, mid + 1, y);
	seg[node] = seg[node * 2] + seg[node * 2 + 1];
}
ll query(int lo, int hi, int node, int x, int y) {
	propagate(node, x, y);
	if (hi < x || y < lo)return 0;
	if (lo <= x && y <= hi)return seg[node];
	int mid = (x + y) >> 1;
	return query(lo, hi, node * 2, x, mid) + query(lo, hi, node * 2 + 1, mid + 1, y);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> m[i];
		s[i] = m[i] - m[i - 1];
	}
	init(1, 1, n);
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> op;
		if (op == 1) {
			cin >> X >> Y; 
			update(X, Y, 1, 1, 1, n);
			update(Y + 1, Y + 1, 1, -(Y - X + 1), 1, n);
		}
		else {
			cin >> X;
			cout << query(1, X, 1, 1, n) << endl;
		}
	}
	return 0;
}