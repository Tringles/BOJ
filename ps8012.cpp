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

int n, m, p[20][30005], depth[30005], visit[30005];
int p1, p2, s, f, ans;
vector<vector<int>> v;

void dfs(int cur) {
	visit[cur] = true;
	for (auto& i : v[cur]) {
		if (!visit[i]) {
			depth[i] = depth[cur] + 1;
			p[0][i] = cur;
			dfs(i);
		}
	}
}
int lca(int x, int y) {
	if (depth[x] > depth[y])swap(x, y);
	for (int i = 19; i >= 0; i--) {
		int dif = depth[y] - depth[x];
		if (dif >= (1 << i))y = p[i][y];
	}
	if (x == y)return x;
	for (int i = 19; i >= 0; i--) {
		if (p[i][x] != p[i][y]) {
			x = p[i][x];
			y = p[i][y];
		}
	}
	return p[0][x];
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	v.resize(n + 1);
	for (int i = 0; i < n - 1; i++) {
		cin >> p1 >> p2;
		v[p1].push_back(p2);
		v[p2].push_back(p1);
	}
	dfs(1);
	s = 1;
	for (int i = 1; i < 20; i++)
		for (int j = 1; j <= n; j++)
			p[i][j] = p[i - 1][p[i - 1][j]];
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> f;
		int ca = lca(s, f);
		ans += depth[s] + depth[f] - 2 * depth[ca];
		s = f;
	}
	cout << ans << endl;
	return 0;
}
