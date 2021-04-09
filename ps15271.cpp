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

int visit[222];
int n, m, p1, p2, ans;
vector<vector<int>> v;
bool check[222];

bool dfs(int cur) {
	for (int i = 0; i < v[cur].size(); i++) {
		int next = v[cur][i];
		if (check[next])continue;
		check[next] = true;
		if (!visit[next] || dfs(visit[next])) {
			visit[next] = cur;
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	v.resize(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> p1 >> p2;
		if (p1 % 2 && p2 % 2)continue;
		if (!(p1 % 2) && !(p2 % 2))continue;
		if (p1 % 2)swap(p1, p2);
		v[p1].push_back(p2);
	}
	for (int i = 2; i <= n; i += 2) {
		memset(check, 0, sizeof(check));
		if (dfs(i))ans++;
	}
	ans *= 2;
	if (ans != n)ans++;
	cout << ans << endl;
	return 0;
}
