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

int n, k, r, ans;
int dy[] = { 0,0,-1,1 }, dx[] = { 1,-1,0,0 };
int group[10005], visited[105][105], cow[105][105];
queue<PI> q;

struct cord {
	int a, b, c, d;
};
vector<cord> c;

bool isblocked(int y, int x, int ny, int nx) {
	for (auto i : c)
		if ((y == i.a && x == i.b && ny == i.c && nx == i.d) || (y == i.c && x == i.d && ny == i.a && nx == i.b))return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k >> r;
	for (int i = 0, p1, p2, p3, p4;i < r;i++) {
		cin >> p1 >> p2 >> p3 >> p4;
		c.push_back({ p1, p2, p3, p4 });
	}

	for (int i = 0, p1, p2;i < k;i++) {
		cin >> p1 >> p2;
		cow[p1][p2] = 1;
	}

	int cnt = 0;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			if (!visited[i][j]) {
				q.push({ i, j });
				visited[i][j] = ++cnt;
				if (cow[i][j])
					group[cnt]++;
				while (!q.empty()) {
					int y = q.front().first;
					int x = q.front().second;
					q.pop();
					for (int d = 0;d < 4;d++) {
						int ny = y + dy[d];
						int nx = x + dx[d];
						if (ny<1 || ny>n || nx<1 || nx>n || isblocked(y, x, ny, nx))continue;
						if (!visited[ny][nx]) {
							visited[ny][nx] = cnt;
							q.push({ ny,nx });
							if (cow[ny][nx])
								group[cnt]++;
						}
					}
				}
			}
		}
	}
	for (int i = 1;i < cnt;i++)
		for (int j = i + 1;j <= cnt;j++)
			ans += group[i] * group[j];

	cout << ans << endl;
	return 0;
}