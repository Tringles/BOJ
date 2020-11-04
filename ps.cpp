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

int n, m, ans = INF;
int dy[] = { 0,0,1,-1 }, dx[] = { 1,-1,0,0 };
char c[22][22];
vector<PI> v;

bool check(int ny, int nx) { return (ny<0 || ny>n - 1 || nx<0 || nx>m - 1); }

void bfs(int fy, int fx, int sy, int sx, int cnt) {
	if (cnt >= ans || cnt >= 10)return;
	bool f, s;
	for (int i = 0; i < 4; i++) {
		int nfy = fy + dy[i];
		int nfx = fx + dx[i];
		int nsy = sy + dy[i];
		int nsx = sx + dx[i];
		f = s = false;
		f = check(nfy, nfx);
		s = check(nsy, nsx);
		if (f && s)continue;
		if (f || s) {
			ans = min(ans, cnt + 1);
			return;
		}
		if (!f && c[nfy][nfx] == '#') {
			nfy = fy;
			nfx = fx;
		}
		if (!s && c[nsy][nsx] == '#') {
			nsy = sy;
			nsx = sx;
		}
		if ((nfy == nsy) && (nfx == nsx))continue;
		bfs(nfy, nfx, nsy, nsx, cnt + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c[i][j];
			if (c[i][j] == 'o')
				v.push_back({ i,j });
		}
	}
	bfs(v[0].first, v[0].second, v[1].first, v[1].second, 0);
	if (ans > 10)cout << -1 << endl;
	else cout << ans << endl;
	return 0;
}