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

int n, m, b, g[505][505];
PI ans = { INF,0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> b;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			cin >> g[i][j];
		}
	}

	for (int k = 0;k <= 256;k++) {
		int sum = 0, cnt = 0;
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < m;j++) {
				if (g[i][j] > k) {
					sum += 2 * (g[i][j] - k);
					cnt -= (g[i][j] - k);
				}
				else {
					sum += (k - g[i][j]);
					cnt += (k - g[i][j]);
				}
			}
		}
		if (cnt > b)continue;
		if (ans.first >= sum) {
			ans = { sum, k };
		}
	}
	cout << ans.first << ' ' << ans.second << endl;
	return 0;
}