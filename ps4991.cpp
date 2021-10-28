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

int n, m, node, visited[22][22], dvisited[22];
int dy[] = { 0,0,-1,1 }, dx[] = { 1,-1,0,0 };
vector<PI> li;
vector<vector<PI>> v;
map<PI, int> h;
char mp[22][22];

void bfs(int cur) {
	memset(visited, 0, sizeof(visited));
	queue<PI> q;
	int cy = li[cur].first;
	int cx = li[cur].second;
	q.push({ cy,cx });
	visited[cy][cx] = 1;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny<0 || ny>n - 1 || nx<0 || nx>m - 1)continue;
			if (!visited[ny][nx] && mp[ny][nx] != 'x') {
				visited[ny][nx] = visited[y][x] + 1;
				q.push({ ny,nx });
				if (mp[ny][nx] == 'o' || mp[ny][nx] == '*') {
					v[h[{cy, cx}]].push_back({ h[{ny,nx}],visited[ny][nx] - 1 });
				}
			}
		}
	}
}
int dfs(int cur, int cnt) {
	int ret = INF;
	if (cnt == node) {
		ret = dvisited[cur];
		dvisited[cur] = 0;
		return ret;
	}
	for (auto& i : v[cur]) {
		int next = i.first, dist = i.second;
		if (!dvisited[next]) {
			dvisited[next] = dvisited[cur] + dist;
			ret = min(ret, dfs(next, cnt + 1));
		}
	}
	dvisited[cur] = 0;
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> m >> n;
	while (m && n) {
		memset(dvisited, 0, sizeof(dvisited));
		v.clear();
		li.clear();
		h.clear();
		node = 1;
		for (int i = 0; i < n; i++)for (int j = 0; j < m; j++) {
			cin >> mp[i][j];
			if (mp[i][j] == 'o') {
				h[{i, j}] = 1;
				li.push_back({ i,j });
			}
			else if (mp[i][j] == '*') {
				h[{i, j}] = ++node;
				li.push_back({ i,j });
			}
		}
		v.resize(node + 1);
		for (int i = 0; i < node; i++) bfs(i);
		dvisited[1] = 1;
		int ans = dfs(1, 1);
		cout << (ans == INF ? -1 : ans - 1) << endl;
		cin >> m >> n;
	}
	return 0;
}