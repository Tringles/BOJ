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

vector<int> solution(int m, int n, vector<vector<int>> p) {
	vector<int> ans(2);
	ans[1] = 0;
	int dy[] = { 0,0,-1,1 }, dx[] = { 1,-1,0,0 };
	int visited[101][101] = { 0, };
	queue<PI> q;

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			int cnt = 0;
			if (p[i][j] && !visited[i][j]) {
				ans[0]++;
				int cur = p[i][j];
				visited[i][j] = ++cnt;
				q.push({ i,j });
				while (!q.empty()) {
					int y = q.front().first;
					int x = q.front().second;
					q.pop();
					for (int k = 0;k < 4;k++) {
						int ny = y + dy[k];
						int nx = x + dx[k];
						if (ny<0 || ny>n - 1 || nx<0 || nx>m - 1)continue;
						if (p[ny][nx] == cur && !visited[ny][nx]) {
							visited[ny][nx] = ++cnt;
							q.push({ ny,nx });
						}
					}
				}
			}
			ans[1] = max(ans[1], cnt);
		}
	}

	return ans;
}