#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define endl '\n'
#define INF 2e9
#define LINF 2e11
#define MOD 1000000007

int n, dp[2][1000001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	dp[0][0] = 1, dp[0][1] = 2;
	dp[1][0] = 0, dp[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[1][i] = ((dp[0][i - 1] + dp[0][i - 2]) % MOD + dp[1][i - 2]) % MOD;
		dp[0][i] = (dp[0][i - 2] + (2 * dp[1][i]) % MOD) % MOD;
	}
	cout << dp[0][n] << endl;
	return 0;
}