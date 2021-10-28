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

ll n, k, s[5555], visited[5555], ans = LINF;
queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0;i < n;i++)cin >> s[i];
	int l = 1, r = 1000000;
	while (l <= r) {
		k = (l + r) >> 1;
		q.push(0);
		visited[0] = true;
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (int i = cur + 1;i < n;i++) {
				if (visited[i])continue;
				if (k >= (i - cur) * (1 + abs(s[i] - s[cur]))) {
					visited[i] = true;
					q.push(i);
				}
			}
		}
		if (visited[n - 1]) {
			r = k - 1;
			ans = min(ans, k);
		}
		else l = k + 1;
		memset(visited, 0, sizeof(visited));
	}
	cout << ans << endl;
	return 0;
}