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

char c;
int n, m, k, visit[2][11][1005][1005], wall[1005][1005], ans = INF;
int dy[] = { 0,0,-1,1 }, dx[] = { 1,-1,0,0 };
queue<pair<int, PII>> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c;
			wall[i][j] = c - '0';
		}
	}
	visit[0][0][0][0] = 1;
	q.push({ 0,{0,{0,0}} });
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second.first;
		int cnt = q.front().second.second.first;
		int when = q.front().second.second.second;
		q.pop();
		if (cnt > k)continue;
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny<0 || ny>n - 1 || nx<0 || nx>m - 1)continue;
			if (!visit[!when][cnt][ny][nx]) {
				if (!wall[ny][nx]) {
					visit[!when][cnt][ny][nx] = visit[when][cnt][y][x] + 1;
					q.push({ ny,{nx,{cnt,!when}} });
				}
				else {
					if (cnt + 1 <= k && !when) {
						visit[!when][cnt + 1][ny][nx] = visit[when][cnt][y][x] + 1;
						q.push({ ny,{nx,{cnt + 1,!when}} });
					}
				}
			}
			if (!visit[!when][cnt][y][x]) {
				visit[!when][cnt][y][x] = visit[when][cnt][y][x] + 1;
				q.push({ y,{x,{cnt,!when}} });
			}
		}
	}
	for (int i = 0; i < 2; i++)
		for (int j = 0; j <= k; j++)
			if (visit[i][j][n - 1][m - 1]) ans = min(ans, visit[i][j][n - 1][m - 1]);
	cout << (ans == INF ? -1 : ans) << endl;
	return 0;
}