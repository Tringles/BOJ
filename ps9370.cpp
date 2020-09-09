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

int T;
int n, m, t, s, g, h, p1, p2, p3, destination, gd, hd, inter;
int dist[2002], visit[2002];
priority_queue<PI, vector<PI>, greater<PI >> q;
vector<vector<PI>> v;
vector<PI> dest;
vector<int> ans;

void djs(int s) {
	memset(visit, 0, sizeof(visit));
	fill(dist, dist + n + 1, INF);
	priority_queue<PI, vector<PI>, greater<PI>> pq;
	pq.push({ 0, s });
	dist[s] = 0;
	while (!pq.empty()) {
		int cur;
		do {
			cur = pq.top().second;
			pq.pop();
		} while (!pq.empty() && visit[cur]);
		if (visit[cur])	break;
		visit[cur] = 1;
		for (auto& i : v[cur]) {
			int next = i.first, ndist = i.second;
			if (dist[next] > dist[cur] + ndist) {
				dist[next] = dist[cur] + ndist;
				pq.push({ dist[next], next });
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> n >> m >> t;
		cin >> s >> g >> h;
		v.resize(n + 1);
		fill(dist, dist + n + 1, INF);
		for (int i = 0; i < m; i++) {
			cin >> p1 >> p2 >> p3;
			v[p1].push_back({ p2,p3 });
			v[p2].push_back({ p1,p3 });
		}
		for (int i = 0; i < t; i++) {
			cin >> destination;
			dest.push_back({ destination,0 });
		}
		djs(s);
		for (auto& i : dest) {
			int cur = i.first;
			i.second = dist[cur];
		}
		for (auto& i : v[g]) {
			if (i.first == h) {
				inter = i.second;
				break;
			}
		}
		gd = dist[g];
		hd = dist[h];
		djs(h);
		for (auto& i : dest) {
			if (dist[i.first] + gd + inter == i.second)
				ans.push_back(i.first);
		}
		djs(g);
		for (auto& i : dest) {
			if (dist[i.first] + hd + inter == i.second)
				ans.push_back(i.first);
		}
		sort(ans.begin(), ans.end());
		for (auto& i : ans)cout << i << ' ';
		cout << endl;
		v.clear();
		ans.clear();
		dest.clear();
	}
	return 0;
}
