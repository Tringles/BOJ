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
vector<PI> v[10005];

PI bfs(int s) {
	PI ret = { 0,0 };
	int visited[10005] = { 0, };
	queue<int> q;
	q.push(s);
	visited[s] = true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto& i : v[cur]) {
			if (!visited[i.first]) {
				visited[i.first] = visited[cur] + i.second;
				if (ret.first < visited[i.first])ret = { visited[i.first],i.first };
				q.push(i.first);
			}
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (cin >> n >> m >> k) {
		v[n].push_back({ m,k });
		v[m].push_back({ n,k });
	}
	if (!n && !m)cout << 0 << endl;
	else {
		PI p = bfs(1);
		p = bfs(p.second);
		cout << p.first - 1 << endl;
	}
	return 0;
}