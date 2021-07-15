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

int n, q, parNode[200005], p[200005], check[200005];
vector<PII> v;
vector<PI> qv;
stack<string> ans;

int find(int x) {
	if (p[x] < 0)return x;
	return p[x] = find(p[x]);
}
bool merge(int x, int y, bool f) {
	x = find(x);
	y = find(y);
	if (x == y)return true;
	if (f) p[x] = y;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> q;
	memset(p, -1, sizeof(p));
	for (int i = 1, p1; i < n; i++) {
		cin >> p1;
		parNode[i + 1] = p1;
	}
	for (int i = n + q - 2, p1, p2, p3; i >= 0; i--) {
		cin >> p1;
		if (p1) {
			cin >> p2 >> p3;
			v.push_back({ p2,{ p3,i } });
		}
		else {
			cin >> p2;
			check[p2] = true;
			qv.push_back({ p2,i });
		}
	}
	reverse(v.begin(), v.end());
	reverse(qv.begin(), qv.end());
	for (int i = 2; i <= n; i++)if (!check[i])merge(i, parNode[i], 1);
	int s = 0;
	for (auto& cur : qv) {
		int cNode = cur.first, idx = cur.second;
		while (true) {
			if (s == v.size())break;
			int v1 = v[s].first, v2 = v[s].second.first, w = v[s].second.second;
			if (idx > w) {
				if (merge(v1, v2, 0))ans.push("YES");
				else ans.push("NO");
				s++;
			}
			else break;
		}
		merge(cNode, parNode[cNode], 1);
	}
	for (; s < v.size(); s++) {
		int v1 = v[s].first, v2 = v[s].second.first;
		if (merge(v1, v2, 0))ans.push("YES");
		else ans.push("NO");
	}
	while (!ans.empty()) {
		cout << ans.top() << endl;
		ans.pop();
	}
	return 0;
}