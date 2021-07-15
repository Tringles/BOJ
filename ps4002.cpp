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

ll n, m, root, ans;
ll parNode[100005], salary[100005], level[100005], p[100005];
vector<vector<int>> v;
priority_queue<int> q[100005];

int find(int x) {
	if (p[x] < 0)return x;
	return p[x] = find(p[x]);
}
void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)return;
	if (q[y].size() > q[x].size())swap(x, y);
	while (!q[y].empty()) {
		q[x].push(q[y].top());
		q[y].pop();
	}
	p[y] = x;
}

ll func(int cur) {
	int val = salary[cur];
	for (auto& i : v[cur]) {//tree -> no rdd
		val += func(i);
		merge(cur, i);
		int cp = find(cur);
		while (val > m) {
			val -= q[cp].top();
			q[cp].pop();
		}
	}
	ans = max(ans, (ll)(level[cur] * q[find(cur)].size()));
	return val;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	v.resize(n + 1);
	memset(p, -1, sizeof(p));
	for (int i = 1; i <= n; i++) {
		cin >> parNode[i] >> salary[i] >> level[i];
		if (!parNode[i])root = i;
		v[parNode[i]].push_back(i);
		q[i].push(salary[i]);
	}
	func(root);
	cout << ans << endl;
	return 0;
}
