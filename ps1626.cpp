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

int n, m, res, cnt, ans = INF;
int mstp[50005], visit[50005], depth[50005];
PII p[20][50005];
vector<vector<PI>> v;
vector<PII> edge;
priority_queue<PII, vector<PII>, greater<PII>> q;

PI dist(PI x, PI y) {
	vector<int> s;
	s.push_back(x.first);
	s.push_back(x.second);
	s.push_back(y.first);
	s.push_back(y.second);
	sort(s.rbegin(), s.rend());
	s.erase(unique(s.begin(), s.end()), s.end());
	if (s.size() < 2)s.push_back(-INF);
	return { s[0],s[1] };
}
int find(int x) {
	if (mstp[x] < 0)return x;
	return mstp[x] = find(mstp[x]);
}
bool merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)return false;
	mstp[x] = y;
	return true;
}
void dfs(int cur) {
	visit[cur] = true;
	for (auto& i : v[cur]) {
		int next = i.first, d = i.second;
		if (!visit[next]) {
			depth[next] = depth[cur] + 1;
			p[0][next] = { cur,{d,-INF} };
			dfs(next);
		}
	}
}
PI lca(int x, int y) {
	if (depth[x] > depth[y])swap(x, y);
	PI ret = { -INF,-INF };
	for (int i = 19;i >= 0;i--) {
		int dif = depth[y] - depth[x];
		if (dif >= (1 << i)) {
			ret = dist(ret, p[i][y].second);
			y = p[i][y].first;
		}
	}
	if (x == y)return ret;
	for (int i = 19;i >= 0;i--) {
		if (p[i][x].first != p[i][y].first) {
			ret = dist(ret, p[i][x].second);
			ret = dist(ret, p[i][y].second);
			x = p[i][x].first;
			y = p[i][y].first;
		}
	}
	ret = dist(ret, p[0][x].second);
	ret = dist(ret, p[0][y].second);
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(mstp, -1, sizeof(mstp));
	cin >> n >> m;
	v.resize(n + 1);
	for (int i = 0, p1, p2, p3;i < m;i++) {
		cin >> p1 >> p2 >> p3;
		q.push({ p3,{p1,p2} });
		edge.push_back({ p1,{p2,p3} });
	}
	while (!q.empty()) {
		int w = q.top().first;
		int x = q.top().second.first;
		int y = q.top().second.second;
		q.pop();
		if (merge(x, y)) {
			res += w;
			v[x].push_back({ y,w });
			v[y].push_back({ x,w });
			if (++cnt == n - 1)break;
		}
	}
	if (n - 1 > cnt || n - 1 > m) {
		cout << -1 << endl;
		return 0;
	}
	dfs(1);
	for (int i = 1;i < 20;i++) {
		for (int j = 1;j <= n;j++) {
			p[i][j].first = p[i - 1][p[i - 1][j].first].first;
			PI x = p[i - 1][j].second;
			PI y = p[i - 1][p[i - 1][j].first].second;
			p[i][j].second = dist(x, y);
		}
	}
	for (int i = 0;i < m;i++) {
		int x = edge[i].first;
		int y = edge[i].second.first;
		int w = edge[i].second.second;
		PI maxw = lca(x, y);
		if (maxw.first != w)ans = min(ans, res - maxw.first + w);
		else if (maxw.second != w)ans = min(ans, res - maxw.second + w);
	}
	if (ans == INF)cout << -1 << endl;
	else cout << ans << endl;
	return 0;
}