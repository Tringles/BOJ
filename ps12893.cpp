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

int n, m, visit[2002];
vector<vector<int>> v;
bool flag = true;

void dfs(int s, int f) {
	visit[s] = f % 2 + 1;
	for (auto& i : v[s]) {
		if (!visit[i])dfs(i, f + 1);
		else if (visit[i] == visit[s])flag = false;
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	v.resize(n + 1);
	for (int i = 0, p1, p2;i < m;i++) {
		cin >> p1 >> p2;
		v[p1].push_back(p2);
		v[p2].push_back(p1);
	}
	for (int i = 1;i <= n;i++) {
		if (!visit[i])dfs(i, 0);
		if (!flag) {
			cout << 0 << endl;
			return 0;
		}
	}
	cout << 1 << endl;
	return 0;
}