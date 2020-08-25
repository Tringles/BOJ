#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, pair<int, int>> P;
#define endl '\n'
#define INF 2e9
#define LINF 2e11
#define MOD 1000000007

int n, m, p, p1, p2, ans;
int trash[101][101], visit[101][101];
int dy[] = { 0,0,-1,1 }, dx[] = { 1,-1,0,0 };
queue<pair<int, int>> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> p;
	while (p--) {
		cin >> p1 >> p2;
		trash[p1 - 1][p2 - 1] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (trash[i][j]) {
				visit[i][j] = 1;
				int cnt = 1;
				q.push({ i,j });
				while (!q.empty()) {
					int y = q.front().first;
					int x = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++) {
						int ny = y + dy[k];
						int nx = x + dx[k];
						if (ny<0 || ny>n - 1 || nx<0 || nx>m - 1)continue;
						if (!visit[ny][nx] && trash[ny][nx]) {
							visit[ny][nx] = ++cnt;
							q.push({ ny,nx });
						}
					}
				}
				ans = max(ans, cnt);
			}
		}
	}
	cout << ans << endl;
	return 0;
}