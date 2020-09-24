#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PI;
typedef pair<double, double> PD;
typedef pair<ll, ll> PL;
typedef pair<double, pair<double, double>> PDD;
typedef pair<ll, pair<ll, ll>> PLL;
#define endl '\n'
#define INF 2e9
#define LINF 2e15
#define MOD 1000000007

int n, s, m[22], ans;

void func(int cur, int sum) {
	if (cur >= n) {
		if (sum == s)ans++;
		return;
	}
	func(cur + 1, sum + m[cur]);
	func(cur + 1, sum);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> s;
	for (int i = 0; i < n; i++)cin >> m[i];
	func(0, 0);
	if (!s)ans--;
	cout << ans << endl;
	return 0;
}