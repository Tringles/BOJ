#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, pair<int, int>> P;
#define endl '\n'
#define INF 2e9
#define LINF 2e11
#define MOD 1000000007

ll n, dp[3][100001], w[3][100001], cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (++cnt) {
		cin >> n;
		if (!n)break;
		for (int i = 1; i <= n; i++)
			for (int j = 0; j < 3; j++)
				cin >> w[j][i];
		dp[0][1] = INF;
		for (int i = 1; i <= n; i++) {
			if (i == 1) {
				dp[1][i] = w[1][i];
				dp[2][i] = dp[1][i] + w[2][i];
			}
			else {
				dp[0][i] = min(dp[0][i - 1], dp[1][i - 1]) + w[0][i];
				dp[1][i] = min(dp[0][i], min(dp[0][i - 1], min(dp[1][i - 1], dp[2][i - 1]))) + w[1][i];
				dp[2][i] = min(dp[1][i], min(dp[1][i - 1], dp[2][i - 1])) + w[2][i];
			}
		}
		cout << cnt << ". " << dp[1][n] << endl;
		memset(dp, 0, sizeof(dp));
		memset(w, 0, sizeof(w));
	}
	return 0;
}