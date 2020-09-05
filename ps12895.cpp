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

int n, t, q, p1, p2, p3, cnt, ans;
int seg[100001 * 4], lazy[100001 * 4];
char Q;

void propagate(int lo, int hi, int node) {
	if (!lazy[node])return;
	if (lo != hi) {
		lazy[node * 2] = lazy[node];
		lazy[node * 2 + 1] = lazy[node];
	}
	seg[node] = lazy[node];
	lazy[node] = 0;
}
void update(int lo, int hi, int val, int node, int x, int y) {
	propagate(x, y, node);
	if (hi < x || y < lo)return;
	if (lo <= x && y <= hi) {
		lazy[node] = val;
		propagate(x, y, node);
		return;
	}
	int mid = (x + y) >> 1;
	update(lo, hi, val, node * 2, x, mid);
	update(lo, hi, val, node * 2 + 1, mid + 1, y);
	seg[node] = seg[node * 2] | seg[node * 2 + 1];
}
int query(int lo, int hi, int node, int x, int y) {
	propagate(x, y, node);
	if (hi < x || y < lo)return 0;
	if (lo <= x && y <= hi)return seg[node];
	int mid = (x + y) >> 1;
	return query(lo, hi, node * 2, x, mid) | query(lo, hi, node * 2 + 1, mid + 1, y);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> t >> q;
	update(1, n, 1, 1, 1, n);
	for (int i = 0; i < q; i++) {
		cin >> Q;
		if (Q == 'C') {
			cin >> p1 >> p2 >> p3;
			if (p1 > p2)swap(p1, p2);
			update(p1, p2, 1 << (p3 - 1), 1, 1, n);
		}
		else {
			cin >> p1 >> p2;
			if (p1 > p2)swap(p1, p2);
			cnt = query(p1, p2, 1, 1, n);
			while (cnt) {
				ans += (cnt & 1);
				cnt >>= 1;
			}
			cout << ans << endl;
			ans = 0;
		}
	}
	return 0;
}
