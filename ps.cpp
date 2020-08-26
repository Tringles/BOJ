#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, pair<int, int>> P;
#define endl '\n'
#define INF 2e9
#define LINF 2e11
#define MOD 1000000007

int n, m, k, ans = INF;
int visit[11][1001][1001], wall[1001][1001];
int dy[] = { 0,0,-1,1 }, dx[] = { 1,-1,0,0 };
string str;
queue<P> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < m; j++) wall[i][j] = str[j] - '0';
	}
	visit[0][0][0] = 1;
	q.push({ 0,{0,0} });
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();
		if (cnt > k)continue;
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny<0 || ny>n - 1 || nx<0 || nx>m - 1)continue;
			if (wall[ny][nx]) {
				if (!visit[cnt + 1][ny][nx]) {
					visit[cnt + 1][ny][nx] = visit[cnt][y][x] + 1;
					q.push({ ny,{nx,cnt + 1} });
				}
			}
			else {
				if (!visit[cnt][ny][nx]) {
					visit[cnt][ny][nx] = visit[cnt][y][x] + 1;
					q.push({ ny,{nx,cnt} });
				}
			}
		}
	}
	for (int i = 0; i <= k; i++)
		if (visit[i][n - 1][m - 1])ans = min(ans, visit[i][n - 1][m - 1]);
	if (ans == INF)cout << -1 << endl;
	else cout << ans << endl;
	return 0;
}