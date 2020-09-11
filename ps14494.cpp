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

int n, m, dp[1005][1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)dp[i][0] = 1;
	for (int i = 0; i < m; i++)dp[0][i] = 1;
	for (int i = 1; i < n; i++)
		for (int j = 1; j < m; j++)
			dp[i][j] = ((dp[i - 1][j] % MOD + dp[i][j - 1] % MOD) % MOD + dp[i - 1][j - 1] % MOD) % MOD;
	cout << dp[n - 1][m - 1] << endl;
	return 0;
}
