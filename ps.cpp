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

ll n, m, p, mid, ans, total;
vector<ll> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p;
		v.push_back(p);
		total += p;
	}
	sort(v.begin(), v.end());
	ll lo = 0, hi = INF;
	cin >> m;
	if (total <= m) {
		cout << v[n - 1] << endl;
		return 0;
	}
	while (lo < hi) {
		mid = (lo + hi) >> 1;
		int cut = v.end() - lower_bound(v.begin(), v.end(), mid);
		ll cur = cut * mid;
		for (int i = 0; i < n - cut; i++)cur += v[i];
		if (cur > m)hi = mid;
		else if (cur <= m) {
			ans = max(ans, mid);
			lo = mid + 1;
		}
	}
	cout << ans << endl;
	return 0;
}
