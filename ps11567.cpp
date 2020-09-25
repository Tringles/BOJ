#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PI;
typedef pair<double, double> PD;
typedef pair<ll, ll> PL;
typedef pair<double, pair<double, double>> PDD;
typedef pair<ll, pair<ll, ll>> PLL;
#define endl '\n'
#define INF 2e9
#define LINF 2e15
#define MOD 1000000007

int n, m, visit[555][555], s1, s2, e1, e2, det;
int dy[] = { 0,0,-1,1 }, dx[] = { 1,-1,0,0 };
char snow[555][555];
queue<PI> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> snow[i][j];
	cin >> s1 >> s2 >> e1 >> e2;
	s1--, s2--, e1--, e2--;
	q.push({ s1,s2 });
	visit[s1][s2] = true;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny<0 || ny>n - 1 || nx<0 || nx>m - 1)continue;
			if (ny == e1 && nx == e2) {
				if (snow[ny][nx] == '.') {
					snow[ny][nx] = 'X';
					q.push({ ny,nx });
				}
				else {
					cout << "YES" << endl;
					return 0;
				}
			}
			if (snow[ny][nx] == '.' && !visit[ny][nx]) {
				visit[ny][nx] = true;
				q.push({ ny,nx });
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}
