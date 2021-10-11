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

int n, ans;
vector<vector<int>> v(10005);
priority_queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0, p1, p2;i < n;i++) {
		cin >> p1 >> p2;
		v[p2].push_back(p1);
	}
	for (int i = 10000;i > 0;i--) {
		for (auto& j : v[i])q.push(j);
		if (!q.empty()) {
			ans += q.top();
			q.pop();
		}
	}
	cout << ans << endl;
	return 0;
}