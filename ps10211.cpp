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

int t, n, s[1001], dp[1001], ans = -INF;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++)cin >> s[i];
		for (int i = 1; i <= n; i++) {
			if (dp[i - 1] + s[i] > s[i])dp[i] = dp[i - 1] + s[i];
			else dp[i] = s[i];
		}
		for (int i = 1; i <= n; i++)
			ans = max(ans, dp[i]);
		cout << ans << endl;
		ans = -INF;
	}
	return 0;
}
