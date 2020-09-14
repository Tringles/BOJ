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

ll n, seg[100001 * 4], s[100001];

void init(int node, int x, int y) {
	if (x == y)seg[node] = x;
	else {
		int mid = (x + y) >> 1;
		init(node * 2, x, mid);
		init(node * 2 + 1, mid + 1, y);
		if (s[seg[node * 2]] < s[seg[node * 2 + 1]])
			seg[node] = seg[node * 2];
		else seg[node] = seg[node * 2 + 1];
	}
}
ll query(int lo, int hi, int node, int x, int y) {
	if (hi < x || y < lo)return -1;
	if (lo <= x && y <= hi)return seg[node];
	int mid = (x + y) >> 1;
	ll left = query(lo, hi, node * 2, x, mid);
	ll right = query(lo, hi, node * 2 + 1, mid + 1, y);
	if (left == -1)return right;
	if (right == -1)return left;
	if (s[left] <= s[right])return left;
	else return right;
}
ll q(int lo, int hi) {
	int cur = query(lo, hi, 1, 1, n);
	ll ans = (hi - lo + 1) * s[cur];
	if (lo <= cur - 1) {
		ll tmp = q(lo, cur - 1);
		ans = max(ans, tmp);
	}
	if (cur + 1 <= hi) {
		ll tmp = q(cur + 1, hi);
		ans = max(ans, tmp);
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> s[i];
	init(1, 1, n);
	cout << q(1, n) << endl;
	return 0;
}