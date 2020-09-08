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

ll n, m, s, ans, l, r, lo, hi, sum, ret;
vector<PI> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		l = r = lo = hi = 0;
		ret = sum = -INF;
		for (int j = 0; j < m; j++) {
			cin >> s;
			if (sum < 0) {
				sum = s;
				lo = hi = j;
			}
			else {
				if (sum)hi++;
				else lo = hi = j;
				sum += s;
			}
			if (ret < sum || (ret == sum && hi - lo < r - l)) {
				ret = sum;
				l = lo, r = hi;
			}
		}
		v.push_back({ l,r });
		ans += ret;
	}
	cout << ans << endl;
	for (auto& i : v)
		cout << i.first + 1 << ' ' << i.second + 1 << endl;
	return 0;
}
