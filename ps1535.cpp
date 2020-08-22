#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define endl '\n'
#define INF 2e9
#define LINF 2e11
#define MOD 1000000007

int n, lost[21], happy[21];
int dp[22][111];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> lost[i];
	for (int i = 1; i <= n; i++)cin >> happy[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 100; j++) {
			if (lost[i] >= j)dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - lost[i]] + happy[i]);
		}
	}
	cout << dp[n][100] << endl;
	return 0;
}
