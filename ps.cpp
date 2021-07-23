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

int n, xcnt, ycnt, ans, bp_m[10005];
char mp[105][105];
PI visit[105][105];
bool check[10005];
queue<PI> q;
vector<vector<int>> v;

bool dfs(int cur) {
	for (int i = 0; i < v[cur].size(); i++) {
		int next = v[cur][i];
		if (check[next])continue;
		check[next] = true;
		if (!bp_m[next] || dfs(bp_m[next])) {
			bp_m[next] = cur;
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)cin >> mp[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visit[i][j].first && mp[i][j] == '.') {
				visit[i][j].first = ++xcnt;
				q.push({ i,j });
				while (!q.empty()) {
					int y = q.front().first;
					int x = q.front().second;
					q.pop();
					if (x + 1 > n - 1)continue;
					if (mp[y][x+1] == '.') {
						visit[y][x + 1].first = xcnt;
						q.push({ y,x + 1 });
					}
				}
			}
			if (!visit[i][j].second && mp[i][j] == '.') {
				visit[i][j].second = ++ycnt;
				q.push({ i,j });
				while (!q.empty()) {
					int y = q.front().first;
					int x = q.front().second;
					q.pop();
					if (y + 1 > n - 1)continue;
					if (mp[y + 1][x] == '.') {
						visit[y + 1][x].second = ycnt;
						q.push({ y + 1,x });
					}
				}
			}
		}
	}
	v.resize(max(xcnt, ycnt) + 1);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (mp[i][j] == '.')
				v[visit[i][j].first].push_back(visit[i][j].second);
	for (int i = 1; i <= xcnt; i++) {
		memset(check, 0, sizeof(check));
		if (dfs(i))ans++;
	}
	cout << ans << endl;
	return 0;
}