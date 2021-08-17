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

ll n, m, dist[404][404], ans = INF;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)for (int j = 1;j <= n;j++)dist[i][j] = INF;
	for (int i = 0, p1, p2, p3;i < m;i++) {
		cin >> p1 >> p2 >> p3;
		dist[p1][p2] = p3;
	}
	for (int k = 1;k <= n;k++)
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	for (int i = 1;i <= n;i++)
		ans = min(ans, dist[i][i]);
	cout << (ans == INF ? -1 : ans) << endl;
	return 0;
}