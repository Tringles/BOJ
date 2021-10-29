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

int n, m, cnt, ans, scnt = 1;
int visited[100005], finish[100005], sn[100005], ind[100005];
vector<vector<int>> v, sv;
stack<int> s;

int dfs(int cur) {
	visited[cur] = ++cnt;
	s.push(cur);
	int result = visited[cur];
	for (auto& i : v[cur]) {
		if (!visited[i])result = min(result, dfs(i));
		else if (!finish[i])result = min(result, visited[i]);
	}
	if (result == visited[cur]) {
		while (true) {
			int t = s.top();
			s.pop();
			finish[t] = true;
			sn[t] = scnt;
			if (t == cur)break;
		}
		scnt++;
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	v.resize(n + 1);
	sv.resize(n + 1);
	for (int i = 0, p1, p2;i < m;i++) {
		cin >> p1 >> p2;
		v[p1].push_back(p2);
	}
	for (int i = 1;i <= n;i++)if (!visited[i])dfs(i);
	for (int i = 1;i <= n;i++)for (auto& j : v[i])
		if (sn[i] != sn[j]) ind[sn[j]]++;
	for (int i = 1;i < scnt;i++)if (!ind[i])ans++;
	cout << ans << endl;
	return 0;
}