#include<bits/stdc++.h>
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

bool prime[123457 * 2];
int n, ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	fill(prime + 2, prime + 123457 * 2, true);
	for (int i = 2; i < 123457 * 2; i++) {
		for (int j = i * 2; j < 123457 * 2; j += i)
			prime[j] = false;
	}
	while (1) {
		cin >> n;
		if (!n)break;
		for (int i = n + 1; i <= 2 * n; i++)
			if (prime[i])ans++;
		cout << ans << endl;
		ans = 0;
	}
	return 0;
}
