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

int n, m, p[200005], depth[200005], visit[200005];
PL lp[20][200005];
priority_queue<PII, vector<PII>, greater<PII>> q;
vector<vector<PI>> v;
vector<PII> eInfo;

int find(int x) {
	if (p[x] < 0)return x;
	return p[x] = find(p[x]);
}
bool merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)return false;
	p[x] = y;
	return true;
}
void dfs(int cur) {
	visit[cur] = true;
	for (auto& i : v[cur]) {
		if (!visit[i.first]) {
			depth[i.first] = depth[cur] + 1;
			lp[0][i.first] = { cur,i.second };
			dfs(i.first);
		}
	}
}
int lca(int x, int y) {
	if (depth[x] > depth[y])swap(x, y);
	ll ret = 0;
	for (int i = 19; i >= 0; i--) {
		int dif = depth[y] - depth[x];
		if (dif >= (1 << i)) {
			ret = max(ret, lp[i][y].second);
			y = lp[i][y].first;
		}
	}
	if (x == y)return ret;
	for (int i = 19; i >= 0; i--) {
		if (lp[i][x].first != lp[i][y].first) {
			ret = max(ret, max(lp[i][x].second, lp[i][y].second));
			x = lp[i][x].first;
			y = lp[i][y].first;
		}
	}
	return max(ret, max(lp[0][x].second, lp[0][y].second));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(p, -1, sizeof(p));
	cin >> n >> m;
	v.resize(n + 1);
	for (int i = 0, p1, p2, p3; i < m; i++) {
		cin >> p1 >> p2 >> p3;
		q.push({ p3,{p1,p2} });
		eInfo.push_back({ p1,{p2,p3} });
	}
	int cnt = 0;
	ll ans = 0;
	while (!q.empty()) {
		int w = q.top().first;
		int p1 = q.top().second.first;
		int p2 = q.top().second.second;
		q.pop();
		if (merge(p1, p2)) {
			v[p1].push_back({ p2,w });
			v[p2].push_back({ p1,w });
			ans += w;
			if (++cnt == n - 1)break;
		}
	}
	dfs(1);
	for (int i = 1; i < 20; i++) {
		for (int j = 1; j <= n; j++) {
			lp[i][j].first = lp[i - 1][lp[i - 1][j].first].first;
			lp[i][j].second = max(lp[i - 1][j].second, lp[i - 1][lp[i - 1][j].first].second);
		}
	}
	for (int i = 0; i < m; i++) {
		int x = eInfo[i].first;
		int y = eInfo[i].second.first;
		ll w = eInfo[i].second.second;
		ll maxw = lca(x, y);
		cout << ans + w - maxw << endl;
	}
	return 0;
}