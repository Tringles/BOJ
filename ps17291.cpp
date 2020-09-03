#include<bits/stdc++.h>
#include<unordered_map>
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

int n, dp[22][22], ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	dp[1][1] = 1;
	for (int i = 2; i <= 20; i++) {
		for (int j = 1; j < i; j++) {
			if (j % 2) {
				if (i - j < 3)dp[i][j] += dp[i - 1][j];
			}
			else if (i - j < 4)dp[i][j] += dp[i - 1][j];
			dp[i][i] += dp[i - 1][j];
		}
	}
	for (int i = 1; i <= n; i++)ans += dp[n][i];
	cout << ans << endl;
	return 0;
}
