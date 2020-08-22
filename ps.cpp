#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define endl '\n'
#define INF 2e9
#define LINF 2e11
#define MOD 1000000007

int n, dp[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	dp[1] = dp[2] = 1;
	for (int i = 3; i <= abs(n); i++)dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000000;
	if (n == 0)cout << 0 << endl << 0 << endl;
	else if (n < 0) {
		if (abs(n) % 2)cout << 1 << endl;
		else cout << -1 << endl;
		cout << dp[abs(n)] << endl;
	}
	else {
		cout << 1 << endl;
		cout << dp[n] << endl;
	}
	return 0;
}