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

ll n, k, ans, res;
vector<ll> v;
set<ll> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		v.push_back(k);
		s.insert(k);
	}
	sort(v.begin(), v.end());
	for (auto& i : s) {
		int cnt = upper_bound(v.begin(), v.end(), i) - lower_bound(v.begin(), v.end(), i);
		if (res < cnt) {
			res = cnt;
			ans = i;
		}
	}
	cout << ans << endl;
	return 0;
}