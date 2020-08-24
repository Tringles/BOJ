#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, pair<int, int>> P;
#define endl '\n'
#define INF 2e9
#define LINF 2e11
#define MOD 1000000003

int n, k, dp[1111][1111], ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i <= n; i++) {
		dp[i][1] = i;
		dp[i][0] = 1;
	}
	for (int i = 2; i <= n; i++)
		for (int j = 2; j <= k; j++)
			dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % MOD;
	ans = (dp[n - 1][k] + dp[n - 3][k - 1]) % MOD;
	cout << ans << endl;
	return 0;
}