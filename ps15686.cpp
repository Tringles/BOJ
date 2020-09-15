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

int n, m, c[55][55], visit[55][55], cnt[111][15], ctr, res = INF;
int dy[] = { 0,0,-1,1 }, dx[] = { 1,-1,0,0 };
vector<PI> v;
vector<int> ans;
queue<PI> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c[i][j];
			if (c[i][j] == 1) {
				v.push_back({ i,j });
				c[i][j] = 0;
			}
			if (c[i][j] == 2) {
				c[i][j] = ++ctr;
			}
		}
	}
	for (int i = 0; i < v.size(); i++) {
		q.push(v[i]);
		visit[v[i].first][v[i].second] = true;
		while (!q.empty()) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			for (int j = 0; j < 4; j++) {
				int ny = y + dy[j];
				int nx = x + dx[j];
				if (ny<0 || ny>n - 1 || nx<0 || nx>n - 1)continue;
				if (!visit[ny][nx]) {
					visit[ny][nx] = visit[y][x] + 1;
					if (c[ny][nx])cnt[i][c[ny][nx]] = visit[ny][nx] - 1;
					q.push({ ny,nx });
				}
			}
		}
		memset(visit, 0, sizeof(visit));
	}
	for (int i = 0; i < ctr; i++) {
		if (i < m)ans.push_back(1);
		else ans.push_back(0);
	}
	do {
		int sum = 0;
		for (int i = 0; i < v.size(); i++) {
			int tmp = INF;
			for (int j = 0; j < ctr; j++) {
				if (ans[j])
					tmp = min(tmp, cnt[i][j + 1]);
			}
			sum += tmp;
		}
		res = min(res, sum);
	} while (prev_permutation(ans.begin(), ans.end()));
	cout << res << endl;
	return 0;
}
