#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, pair<int, int>> P;
#define endl '\n'
#define INF 2e9
#define LINF 2e11
#define MOD 1000000007

ll n, a[1000001], b[500001], seg[500001 * 4], p1, ans;

void update(int pos, ll val, int node, int x, int y) {
	if (pos<x || pos>y)return;
	seg[node] += val;
	if (x != y) {
		int mid = (x + y) >> 1;
		update(pos, val, node * 2, x, mid);
		update(pos, val, node * 2 + 1, mid + 1, y);
	}
}
ll query(int lo, int hi, int node, int x, int y) {
	if (hi<x || lo>y)return 0;
	if (lo <= x && y <= hi)return seg[node];
	int mid = (x + y) >> 1;
	return query(lo, hi, node * 2, x, mid) + query(lo, hi, node * 2 + 1, mid + 1, y);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p1;
		a[p1] = i;
	}
	for (int i = 1; i <= n; i++) {
		cin >> p1;
		b[i] = a[p1];
	}
	for (int i = 1; i <= n; i++) {
		ans += query(b[i] + 1, n, 1, 1, n);
		update(b[i], 1, 1, 1, n);
	}
	cout << ans << endl;
	return 0;
}