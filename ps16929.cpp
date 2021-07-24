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

bool ans;
int n, m, visit[55][55];
int dy[] = { 0,0,-1,1 }, dx[] = { 1,-1,0,0 };
char mp[55][55];

void dfs(int y, int x, int by, int bx) {
	visit[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny<0 || ny>n - 1 || nx<0 || nx>m - 1)continue;
		if (ny == by && nx == bx)continue;
		if (!visit[ny][nx] && mp[y][x] == mp[ny][nx])
			dfs(ny, nx, y, x);
		if (visit[ny][nx])ans = true;
	}
	visit[y][x] = 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> mp[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dfs(i, j, -1, -1);
			if (ans) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
	return 0;
}
