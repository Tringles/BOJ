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

int t, maxseg[100004 * 4], minseg[100004 * 4], s[100004];
int n, q;

int minu(int pos, int val, int node, int x, int y) {
	if (pos<x || pos>y)return minseg[node];
	if (x == y)return minseg[node] = val;
	int mid = (x + y) >> 1;
	return minseg[node] = min(minu(pos, val, node * 2, x, mid), minu(pos, val, node * 2 + 1, mid + 1, y));
}
int maxu(int pos, int val, int node, int x, int y) {
	if (pos<x || pos>y)return maxseg[node];
	if (x == y)return maxseg[node] = val;
	int mid = (x + y) >> 1;
	return maxseg[node] = max(maxu(pos, val, node * 2, x, mid), maxu(pos, val, node * 2 + 1, mid + 1, y));
}
int maxq(int lo, int hi, int node, int x, int y) {
	if (lo > y || hi < x)return -1;
	if (lo <= x && y <= hi)return maxseg[node];
	int mid = (x + y) >> 1;
	return max(maxq(lo, hi, node * 2, x, mid), maxq(lo, hi, node * 2 + 1, mid + 1, y));
}
int minq(int lo, int hi, int node, int x, int y) {
	if (lo > y || hi < x)return INF;
	if (lo <= x && y <= hi)return minseg[node];
	int mid = (x + y) >> 1;
	return min(minq(lo, hi, node * 2, x, mid), minq(lo, hi, node * 2 + 1, mid + 1, y));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	while (t--) {
		memset(maxseg, 0, sizeof(maxseg));
		memset(minseg, 0, sizeof(minseg));
		memset(s, 0, sizeof(s));
		cin >> n >> q;
		for (int i = 1; i <= n; i++) {
			s[i] = i;
			minu(i, i, 1, 1, n);
			maxu(i, i, 1, 1, n);
		}
		while (q--) {
			int Q, p1, p2;
			cin >> Q >> p1 >> p2;
			p1++, p2++;
			if (!Q) {
				swap(s[p1], s[p2]);
				minu(p1, s[p1], 1, 1, n);
				minu(p2, s[p2], 1, 1, n);
				maxu(p1, s[p1], 1, 1, n);
				maxu(p2, s[p2], 1, 1, n);
			}
			else {
				int l = minq(p1, p2, 1, 1, n);
				int r = maxq(p1, p2, 1, 1, n);
				if (l == p1 && r == p2)cout << "YES" << endl;
				else cout << "NO" << endl;
			}
		}
	}
	return 0;
}