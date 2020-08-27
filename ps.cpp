#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, pair<int, int>> P;
#define endl '\n'
#define INF 2e9
#define LINF 2e11
#define MOD 1000000007

int n, b[511][511], visit[511][511], ans;
int dy[] = { 0,0,1,-1 }, dx[] = { 1,-1,0,0 };

int dfs(int y,int x) {
	if (visit[y][x])return visit[y][x];
	visit[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny<0 || ny>n - 1 || nx<0 || nx>n - 1)continue;
		if (b[y][x] < b[ny][nx])
			visit[y][x] = max(visit[y][x], dfs(ny, nx) + 1);
	}
	return visit[y][x];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> b[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			ans = max(ans, dfs(i, j));
	cout << ans << endl;
	return 0;
}