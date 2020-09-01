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

int n, m;
int s[1000001], p[1001];
ll sum, ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		s[i] %= m;
	}
	p[0] = 1;
	for (int i = 0; i < n; i++) {
		sum += s[i];
		sum %= m;
		p[sum]++;
	}
	for (int i = 0; i < m; i++) ans += 1ll*p[i] * 1ll*(p[i] - 1) / 2ll;
	cout << ans << endl;
	return 0;
}
