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

int t, n, m, cnt, visit[101][101];
char s[101][101];
int dy[] = { 0,0,-1,1 }, dx[] = { 1,-1,0,0 };
queue<PI> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> s[i][j];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (s[i][j] == '#' && !visit[i][j]) {
					visit[i][j] = ++cnt;
					q.push({ i,j });
					while (!q.empty()) {
						int y = q.front().first;
						int x = q.front().second;
						q.pop();
						for (int k = 0; k < 4; k++) {
							int ny = y + dy[k];
							int nx = x + dx[k];
							if (ny<0 || ny>n - 1 || nx<0 || nx>m - 1)continue;
							if (s[ny][nx] == '#' && !visit[ny][nx]) {
								visit[ny][nx] = cnt;
								q.push({ ny,nx });
							}
						}
					}
				}
			}
		}
		cout << cnt << endl;
		memset(visit, 0, sizeof(visit));
		cnt = 0;
	}
	return 0;
}