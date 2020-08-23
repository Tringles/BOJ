#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define endl '\n'
#define INF 2e9
#define LINF 2e11
#define MOD 1000000007

int t, n, dp[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	dp[1] = 1, dp[2] = 2, dp[3] = 4;
	for (int i = 4; i <= 1000000; i++)
		dp[i] = ((dp[i - 1] + dp[i - 2]) % (MOD + 2) + dp[i - 3]) % (MOD + 2);
	cin >> t;
	while (t--) {
		cin >> n;
		cout << dp[n] << endl;
	}
	return 0;
}
