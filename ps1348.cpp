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

int n, m, ccnt, pcnt, ans = -1, cnt;
int p[55][55], chk[55][55], visit[2555];
PI car[2555];
int dy[] = { 0,0,-1,1 }, dx[] = { 1,-1,0,0 };
char c[55][55];
bool check[2555];
vector<vector<PI>> v;
queue<PI> q;

bool dfs(int cur, int dist) {
	for (int i = 0; i < v[cur].size(); i++) {
		int next = v[cur][i].second, d = v[cur][i].first;
		if (check[next] || d > dist)continue;
		check[next] = true;
		if (!visit[next] || dfs(visit[next], dist)) {
			visit[next] = cur;
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c[i][j];
			if (c[i][j] == 'C')
				car[++ccnt] = { i,j };
			else if (c[i][j] == 'X')
				p[i][j] = -1;
			else if (c[i][j] == 'P')
				p[i][j] = ++pcnt;
		}
	}
	if (!ccnt) {
		cout << 0 << endl;
		return 0;
	}
	if (ccnt > pcnt) {
		cout << -1 << endl;
		return 0;
	}
	v.resize(ccnt + 1);
	for (int i = 1; i <= ccnt; i++) {
		memset(chk, 0, sizeof(chk));
		chk[car[i].first][car[i].second] = 1;
		q.push({ car[i].first,car[i].second });
		while (!q.empty()) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			for (int j = 0; j < 4; j++) {
				int ny = y + dy[j];
				int nx = x + dx[j];
				if (ny<0 || ny>n - 1 || nx<0 || nx>m - 1)continue;
				if (!chk[ny][nx] && p[ny][nx] != -1) {
					chk[ny][nx] = chk[y][x] + 1;
					if (p[ny][nx])
						v[i].push_back({ chk[ny][nx] - 1,p[ny][nx] });
					q.push({ ny,nx });
				}
			}
		}
	}
	for (int i = 1; i <= ccnt; i++)
		sort(v[i].begin(), v[i].end());
	int lo = 0, hi = 5555;
	while (lo <= hi) {
		memset(visit, 0, sizeof(visit));
		cnt = 0;
		int mid = (lo + hi) >> 1;
		for (int i = 1; i <= ccnt; i++) {
			memset(check, 0, sizeof(check));
			if (dfs(i, mid))cnt++;
		}
		if (cnt == ccnt) {
			ans = mid;
			hi = mid - 1;
		}
		else lo = mid + 1;
	}
	cout << ans << endl;
	return 0;
}
