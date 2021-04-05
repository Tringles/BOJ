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

int n, k, cnt;
ll seg[250005 * 4], s[250005], ans;

ll update(int pos, ll val, int node = 1, int x = 0, int y = 65536) {
	if (pos > y || x > pos)return seg[node];
	if (x == y)return seg[node] += val;
	int mid = (x + y) >> 1;
	return seg[node] = update(pos, val, node * 2, x, mid) + update(pos, val, node * 2 + 1, mid + 1, y);
}
ll query(ll val, int node = 1, int x = 0, int y = 65536) {
	int mid = (x + y) >> 1;
	if (x == y)return x;
	if (seg[node * 2] >= val)return query(val, node * 2, x, mid);
	return query(val - seg[node * 2], node * 2 + 1, mid + 1, y);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		update(s[i], 1);
		if (i >= k - 1) {
			ans += query((k + 1) / 2);
			update(s[cnt++], -1);
		}
	}
	cout << ans << endl;
	return 0;
}