#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define endl '\n'
#define INF 2e9
#define LINF 2e11
#define MOD 1000000007

int n, s[1001], dp[1111];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> s[i];
	dp[1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= s[i]; j++) {
			if (dp[i]) {
				if (dp[i + j])dp[i + j] = min(dp[i + j], dp[i] + 1);
				else dp[i + j] = dp[i] + 1;
			}
		}
	}
	cout << (dp[n] ? dp[n] - 1 : -1) << endl;
	return 0;
}