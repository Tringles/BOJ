#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define endl '\n'
#define INF 2e9
#define LINF 2e11
#define MOD 1000000007

int n, s[121], tet[121], dp[300001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	fill(dp, dp + 300001, INF);
	cin >> n;
	for (int i = 1; i <= 120; i++)s[i] = s[i - 1] + i;
	for (int i = 1; i <= 120; i++)tet[i] = tet[i - 1] + s[i];
	for (int i = 1; i <= 120; i++)dp[tet[i]] = 1;
	for (int i = 1; i <= 120; i++)
		for (int j = tet[i]; j <= n; j++)
			dp[j] = min(dp[j], dp[j - tet[i]] + 1);
	cout << dp[n] << endl;
	return 0;
}
