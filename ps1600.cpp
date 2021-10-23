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

int n, m, k, visited[33][222][222], mp[222][222], ans = INF;
int hy[] = { -1, -2, -2, -1, 1, 2, 2, 1 }, hx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
int dy[] = { 0,0,1,-1 }, dx[] = { -1,1,0,0 };
queue<PII> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> k >> m >> n;
	for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)cin >> mp[i][j];
	q.push({ 0,{0,0} });
	visited[0][0][0] = 1;
	while (!q.empty()) {
		int curk = q.front().first;
		int y = q.front().second.first;
		int x = q.front().second.second;
		q.pop();
		if (y == n - 1 && x == m - 1)ans = min(ans, visited[curk][y][x]);
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny<0 || ny>n - 1 || nx<0 || nx>m - 1)continue;
			if (!visited[curk][ny][nx] && !mp[ny][nx]) {
				visited[curk][ny][nx] = visited[curk][y][x] + 1;
				q.push({ curk,{ny,nx} });
			}
		}
		if (curk + 1 <= k) {
			for (int i = 0; i < 8; i++) {
				int ny = y + hy[i];
				int nx = x + hx[i];
				if (ny<0 || ny>n - 1 || nx<0 || nx>m - 1)continue;
				if (!visited[curk + 1][ny][nx] && !mp[ny][nx]) {
					visited[curk + 1][ny][nx] = visited[curk][y][x] + 1;
					q.push({ curk + 1,{ny,nx} });
				}
			}
		}
	}
	cout << (ans == INF ? -1 : ans - 1) << endl;
	return 0;
}