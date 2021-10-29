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

int n, cnt, ans, scnt = 1;
int sw[105], w[105], visited[105], finish[105], sn[105];
string str;
vector<vector<int>> v;
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
			sn[t] = scnt;
			sw[scnt] = min(sw[scnt], w[t]);
			finish[t] = true;
			if (cur == t)break;
		}
		scnt++;
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	v.resize(n + 1);
	fill(sw, sw + n + 1, INF);
	for (int i = 1;i <= n;i++)cin >> w[i];
	for (int i = 0;i < n;i++) {
		cin >> str;
		for (int j = 0;j < n;j++)
			if (str[j] == '1') v[i + 1].push_back(j + 1);
	}
	for (int i = 1;i <= n;i++)if (!visited[i])dfs(i);
	for (int i = 1;i < scnt;i++)ans += sw[i];
	cout << ans << endl;
	return 0;
}