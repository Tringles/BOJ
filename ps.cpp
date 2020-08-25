#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, pair<int, int>> P;
#define endl '\n'
#define INF 2e9
#define LINF 2e11
#define MOD 1000000007

char p;
int n, m, c, ans;
int visit[31][31][31], b[31][31][31];
int dy[] = { 0,0,-1,1,0,0 }, dx[] = { 1,-1,0,0,0,0 }, dz[] = { 0,0,0,0,1,-1 };
queue<P> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (1) {
		cin >> n >> m >> c;
		if (!n && !m && !c)break;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				for (int k = 0; k < c; k++) {
					cin >> p;
					b[i][j][k] = p;
					if (p == 'S') {
						visit[i][j][k] = 1;
						q.push({ i,{j,k} });
					}
				}
			}
		}
		while (!q.empty()) {
			int z = q.front().first;
			int y = q.front().second.first;
			int x = q.front().second.second;
			q.pop();
			for (int i = 0; i < 6; i++) {
				int nz = z + dz[i];
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (nz<0 || nz>n - 1 || ny<0 || ny>m - 1 || nx<0 || nx>c - 1)continue;
				if (b[nz][ny][nx] != '#' && !visit[nz][ny][nx]) {
					if (b[nz][ny][nx] == 'E') {
						ans = visit[z][y][x];
						break;
					}
					else {
						visit[nz][ny][nx] = visit[z][y][x] + 1;
						q.push({ nz,{ny,nx} });
					}
				}
			}
			if (ans)break;
		}
		if (ans)cout << "Escaped in " << ans << " minute(s)." << endl;
		else cout << "Trapped!" << endl;
		ans = 0;
		memset(visit, 0, sizeof(visit));
		while (!q.empty())q.pop();
	}
	return 0;
}