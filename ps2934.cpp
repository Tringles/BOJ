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

ll n, seg[100004 * 4], lazy[100004 * 4];

void prop(ll x, ll y, ll node) {
	if (!lazy[node])return;
	if (x != y) {
		lazy[node * 2] += lazy[node];
		lazy[node * 2 + 1] += lazy[node];
	}
	seg[node] += lazy[node] * (y - x + 1);
	lazy[node] = 0;
}

ll update(ll lo, ll hi, ll node, ll val, ll x, ll y) {
	prop(x, y, node);
	if (hi < x || y < lo)return seg[node];
	if (lo <= x && y <= hi) {
		lazy[node] += val;
		prop(x, y, node);
		return seg[node];
	}
	ll mid = (x + y) >> 1;
	return seg[node] = update(lo, hi, node * 2, val, x, mid) + update(lo, hi, node * 2 + 1, val, mid + 1, y);
}
ll query(ll lo, ll hi, ll node, ll x, ll y) {
	prop(x, y, node);
	if (hi < x || y < lo)return 0;
	if (lo <= x && y <= hi)return seg[node];
	ll mid = (x + y) >> 1;
	return query(lo, hi, node * 2, x, mid) + query(lo, hi, node * 2 + 1, mid + 1, y);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0, p1, p2;i < n;i++) {
		cin >> p1 >> p2;
		int l = query(p1, p1, 1, 1, 100000), r = query(p2, p2, 1, 1, 100000);
		cout << l + r << endl;
		update(p1, p1, 1, -l, 1, 100000);
		update(p2, p2, 1, -r, 1, 100000);
		update(p1 + 1, p2 - 1, 1, 1, 1, 100000);
	}
	return 0;
}