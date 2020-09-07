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

char op;
int n, p1, p2, p[123666];
vector<vector<int>> v;
ll ans;

ll dfs(int cur) {
	ll ret = 0;
	if (v[cur].empty()) {
		if (p[cur] > 0)ret += p[cur];
		return ret;
	}
	for (auto& i : v[cur])
		ret += dfs(i);
	ret += p[cur];
	if (ret < 0)return 0;
	else return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	v.resize(n + 1);
	for (int i = 2; i <= n; i++) {
		cin >> op >> p1 >> p2;
		if (op == 'S') {
			v[p2].push_back(i);
			p[i] = p1;
		}
		else {
			v[p2].push_back(i);
			p[i] = -p1;
		}
	}
	ans = dfs(1);
	if (ans > 0)cout << ans << endl;
	else cout << 0 << endl;
	return 0;
}
