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

int n, m, visit[255][255], scnt, wcnt, sans, wans;
char g[255][255];
int dy[] = { 0,0,-1,1 }, dx[] = { 1,-1,0,0 };
queue<PI> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> g[i][j];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (g[i][j] != '#' && !visit[i][j]) {
				scnt = wcnt = 0;
				visit[i][j] = true;
				if (g[i][j] == 'v')wcnt++;
				else if (g[i][j] == 'o')scnt++;
				q.push({ i,j });
				while (!q.empty()) {
					int y = q.front().first;
					int x = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++) {
						int ny = y + dy[k];
						int nx = x + dx[k];
						if (ny<0 || ny>n - 1 || nx<0 || nx>m - 1)continue;
						if (g[ny][nx] != '#' && !visit[ny][nx]) {
							if (g[ny][nx] == 'v')wcnt++;
							else if (g[ny][nx] == 'o')scnt++;
							visit[ny][nx] = true;
							q.push({ ny,nx });
						}
					}
				}
				if (scnt > wcnt)sans += scnt;
				else wans += wcnt;
			}
		}
	}
	cout << sans << ' ' << wans << endl;
	return 0;
}
