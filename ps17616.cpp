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

int n, m, k;
int visited[2][100005], cnt[2];
vector<vector<int>> v[2];

void dfs(int r, int cur) {
	cnt[r]++;
	visited[r][cur] = 1;
	for (auto& i : v[r][cur])
		if (!visited[r][i]) dfs(r, i);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> k;
	v[0].resize(n + 1);
	v[1].resize(n + 1);
	for (int i = 0, p1, p2;i < m;i++) {
		cin >> p1 >> p2;
		v[0][p1].push_back(p2);
		v[1][p2].push_back(p1);
	}
	dfs(1, k);
	dfs(0, k);
	cout << cnt[1] << ' ' << n - cnt[0] + 1 << endl;
	return 0;
}