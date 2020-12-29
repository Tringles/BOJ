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

int n, m, p1, p2, p3, j, s, mdist = INF, answer;
int jvisit[101], svisit[101], jdist[101], sdist[101], tdist[101];
vector<vector<PI>> v;
vector<int> ans;
priority_queue<PI, vector<PI>, greater<PI>> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	v.resize(n + 1);
	fill(jdist, jdist + n + 1, INF);
	fill(sdist, sdist + n + 1, INF);
	for (int i = 0; i < m; i++) {
		cin >> p1 >> p2 >> p3;
		v[p1].push_back({ p2,p3 });
		v[p2].push_back({ p1,p3 });
	}
	cin >> j >> s;
	jdist[j] = 0;
	q.push({ 0,j });
	while (!q.empty()) {
		int cur;
		do {
			cur = q.top().second;
			q.pop();
		} while (!q.empty() && jvisit[cur]);
		jvisit[cur] = true;
		for (auto& i : v[cur]) {
			int next = i.first, ndist = i.second;
			if (jdist[next] > jdist[cur] + ndist) {
				jdist[next] = jdist[cur] + ndist;
				q.push({ jdist[next],next });
			}
		}
	}
	sdist[s] = 0;
	q.push({ 0,s });
	while (!q.empty()) {
		int cur;
		do {
			cur = q.top().second;
			q.pop();
		} while (!q.empty() && svisit[cur]);
		svisit[cur] = true;
		for (auto &i : v[cur]) {
			int next = i.first, ndist = i.second;
			if (sdist[next] > sdist[cur] + ndist) {
				sdist[next] = sdist[cur] + ndist;
				q.push({ sdist[next],next });
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (i == j || i == s)continue;
		if (mdist > jdist[i] + sdist[i])
			mdist = jdist[i] + sdist[i];
	}
	for (int i = 1; i <= n; i++) {
		if (i == j || i == s)continue;
		if (jdist[i] <= sdist[i] && sdist[i] + jdist[i] == mdist) {
			ans.push_back(i);
		}
	}
	if (ans.empty())cout << -1 << endl;
	else {
		int check = INF;
		for (auto& i : ans) {
			if (check > jdist[i]) {
				answer = i;
				check = jdist[i];
			}
		}
		cout << answer << endl;
	}
	return 0;
}
