#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, pair<int, int>> P;
#define endl '\n'
#define INF 2e9
#define LINF 2e11
#define MOD 1000000007

ll n, s[100001], seg[100001 * 4], p1, ans;

ll update(int pos, ll val, int node, int x, int y) {
	if (pos<x || pos>y)return seg[node];
	if (x == y)return seg[node] = val;
	int mid = (x + y) >> 1;
	return seg[node] = update(pos, val, node * 2, x, mid) + update(pos, val, node * 2 + 1, mid + 1, y);
}
ll query(int val, int node, int x, int y) {
	if (!val || x == y)return x;
	int mid = (x + y) >> 1;
	if (val <= seg[node * 2])return query(val, node * 2, x, mid);
	return query(val - seg[node * 2], node * 2 + 1, mid + 1, y);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
		update(i, 1, 1, 1, n);
	for (int i = 1; i <= n; i++) {
		cin >> p1;
		ans = query(p1 + 1, 1, 1, n);
		s[ans] = i;
		update(ans, 0, 1, 1, n);
	}
	for (int i = 1; i <= n; i++)
		cout << s[i] << endl;
	return 0;
}