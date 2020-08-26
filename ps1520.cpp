#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, pair<int, int>> P;
#define endl '\n'
#define INF 2e9
#define LINF 2e11
#define MOD 1000000007

int n, m, visit[501][501], road[501][501];
int dy[] = { 0,0,-1,1 }, dx[] = { 1,-1,0,0 };

int func(int y, int x) {
	if (!x && !y)return 1;
	int& ret = visit[y][x];
	if (ret != -1)return ret;
	ret = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny<0 || ny>n - 1 || nx<0 || nx>m - 1)continue;
		if (road[y][x] < road[ny][nx])
			ret += func(ny, nx);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	memset(visit, -1, sizeof(visit));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> road[i][j];
	cout << func(n - 1, m - 1) << endl;
	return 0;
}
