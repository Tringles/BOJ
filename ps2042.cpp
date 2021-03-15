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

ll n, m, k, seg[1000001 * 4], p1, p2, p3;

ll update(ll pos, ll val, ll node, ll x, ll y) {
	if (pos<x || pos>y)return seg[node];
	if (x == y)return seg[node] = val;
	ll mid = (x + y) >> 1;
	return seg[node] = update(pos, val, node * 2, x, mid) + update(pos, val, node * 2 + 1, mid + 1, y);
}
ll query(ll lo, ll hi, ll node, ll x, ll y) {
	if (lo > y || hi < x)return 0;
	if (lo <= x && y <= hi)return seg[node];
	ll mid = (x + y) >> 1;
	return query(lo, hi, node * 2, x, mid) + query(lo, hi, node * 2 + 1, mid + 1, y);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> p1;
		update(i + 1, p1, 1, 1, n);
	}
	for (int i = 0; i < m + k; i++) {
		cin >> p1 >> p2 >> p3;
		if (p1 == 1) update(p2, p3, 1, 1, n);
		else cout << query(p2, p3, 1, 1, n) << endl;
	}
	return 0;
}