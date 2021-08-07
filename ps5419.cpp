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

int t, n, seg[75005 * 4];

ll update(int pos, int val, int node, int x, int y) {
	if (pos<x || pos>y)return seg[node];
	if (x == y)return seg[node] = val;
	int mid = (x + y) >> 1;
	return seg[node] = update(pos, val, node * 2, x, mid) + update(pos, val, node * 2 + 1, mid + 1, y);
}
ll query(int lo, int hi, int node, int x, int y) {
	if (lo > y || hi < x)return 0;
	if (lo <= x && y <= hi)return seg[node];
	int mid = (x + y) >> 1;
	return query(lo, hi, node * 2, x, mid) + query(lo, hi, node * 2 + 1, mid + 1, y);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	while (t--) {
		int cnt[75005] = { 0, };
		PI p[75005];
		vector<int> v;
		memset(seg, 0, sizeof(seg));
		cin >> n;
		for (int i = 1;i <= n;i++) {
			cin >> p[i].first >> p[i].second;
			v.push_back(p[i].second);
		}
		sort(p + 1, p + n + 1, [](PI& a, PI& b) {
			if (a.first == b.first)return a.second > b.second;
			return a.first < b.first;
			});
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		ll ans = 0;
		for (int i = 1;i <= n;i++) {
			int idx = lower_bound(v.begin(), v.end(), p[i].second) - v.begin();
			ans += query(idx, n - 1, 1, 0, n - 1);
			update(idx, ++cnt[idx], 1, 0, n - 1);
		}
		cout << ans << endl;
	}
	return 0;
}